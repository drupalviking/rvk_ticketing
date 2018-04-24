Documentation for rvk_ticketing module and supporting modules.

I decided to implement this project as a module for several reasons, the biggest being able to
test and develop without having to work on the main website itself, since the project is using
a specific content type and (now three) taxonomy vocabularies.

I also decided to write two modules instead of one, abstracting the parts of street lookup
(Borgarvefsja) to seperate module. Both to reduce
code in the module, but also so others could use them, without having to enable this one. There was one more,
Mainmanager (mainmanager), which handled all communications with the sub-system Mainmanager, but when I showcased this
project to the people using Mainmanager, they requested to be part of this project, hence we discarded all implementations
to it. The module still exists though, here: https://github.com/drupalviking/mainmanager

When this module is installed, a content type Ábendingar (indications) is created, among with three
taxonomy vocabularies:  Ábendingategundir (indication types), Utanaðkomandi deildir
 og svið (external departments: Strætó, Faxaflóahafnir and Orka Náttúrunnar) and Staða ábendingar
(indication status).  The taxonomies are all used within the content type.

There used to be one more vocabulary, Deildir og svið, but I merged that into Ábendingategundir, after a feature request,
requiring the indication types to be hierarchical.

When the vocabularies are created, they are also populated with data.

Configuration
==========================
Some configuration is required after installing. First you need to go to /admin/config/services/borgarvefsja to save the
config for Borgarvefsjá, and then do the same for the Ticketing module: /admin/config/services/abendingar

Next you need to create the Thank you page, which the user will be redirected to, after he's done submitting the
indication. Default path is /abendingar/takk-fyrir-abendinguna, but you can change it to whatever you like. Defaults
are provided to the opening hours of the service desk and also for how many days the service desk has to respond, before
the indication becomes "to old".

Each Indication type (in the vocabulary indication types) has also few configs. First of all, you can change the default
setting of how many days the indication type has to finish the process, after it has been assigned (default is 2 days),
and also a checkbox, if the whole department is to be notified with an email. (Used for departments that usually don't
get too many indications).

You have to edit one field of the indication_types vocabulary itself, after first install:
/admin/structure/taxonomy/indication_types/fields/field_send_mail_f_new_indication  Please check the Use field label instead
of the "On value" as label. Also enter Já as On value and Nei as Off value.

You also have to configure External departments vocabulary, and enter the email details for each external department
(in order for them to get the indication in email). There is a rule for sending those indications to the external
departments.

Talking about rules, there are few of them that need importing, all of them are stored under rules_to_be_imported folder
within this module.

You need to add a field to the User, a taxonomy term reference to Ábendingategundir vocabulary. That can be done here:
/admin/config/people/accounts/fields

You also need to add the path to 'abendingar/stjornbord' into the user menu: /admin/structure/menu/manage/management/add
Keep the weight at 50, so it will always be to the furthest right.

Remove the old redirect, here: /admin/config/search/redirect (It's called abendingar)

Apparently, the filters for Indication status do not export over to the production site. So you need to go to
/admin/structure/views/view/indications/edit/indications_new and edit each filter in every display, where
Efni: Staða (=) | Stillingar (The equal sign is indicating that there is no filter criteria.

The Node
====================
For the node type itself (indications), there is also some configuration to be done. First we need to configure the
taxonomy term field field_indication_type_ref to use Hierarchical Select Widget
(/admin/structure/types/manage/indications/fields/field_indication_type_ref/widget-type). It also has to have Save term
linage, Allow the user to choose a term from any level and Level labels enabled (Svið/Deild, Yfirflokkur, Undirflokkur).

Fieldgroups for the content type Indications:

Efni (group_indication_content)
	Title
	Ábending
	Túlkuð ábending
	Svar

Flokkun í þjónustuveri (group_indication_service_cat)
	Staða
	Ábendingategund

Skilaboð starfsmanna (group_indication_messages)
	Innri málsmeðferð

Ítarefni (group_indication_media_items)
	Staðsetning
	XHnit
	YHnit
	Mynd með tilkynningu

Sendandi (group_indication_sender)
	Nafn sendanda
	Kennitala
	Netfang
	Símanúmer

Áframsenda (group_indication_forward)
	Áframsenda á utanaðkomandi

Tímasetningar (group_indication_timestamps)
    Svara ábendingu fyrir
    Ábendingunni svarað þann
    Ábendingunni þarf að loka fyrir
    Ábendingunni lokað þann

We also need to change the pathauto config, to not use the title as url path, but node id's (abendingar/xxx)

Node display
======================
When the indication nodes are displayed, a map might have to be shown. In order to display the map and to push the
data from the node to the Javascripts, I had to override the preprocess_page hook.


Dependencies
======================

The content type relies on few modules, therefor they are set as dependencies:
Already on Reykjavik.is
Display suite (ds)
Views (views)
Field Group (field_group)
Entity Reference (entityreference)
Node Clone (clone)
JQuery Update (jquery_update)
Date (date)
Taxonomy Menu (taxonomy_menu)
Views Block Area (views_block_area)
Date Views (date_views)
Date Popup (date_popup)

Will be installed when this module is installed:
Node clone tab (node_clone_tab)
Rules (rules)
Rules Admin (rules_admin)
Views Show More (views_show_more)
Hierarchical Select (hierarchical_select)
Hierarchical Select Taxonomy (hs_taxonomy)
TVI: Taxonomy View Integrator (tvi)

And of course the seperate custom module:
(borgarvefsja)


Usage
========================
Like previously stated, the meat and potatoes of this module is the content type and the
taxonomy vocabularies that are with it, with few other goodies.

User (who submits indications)
------------------------------------
User creates a new indication by a form, created in the rvk_ticketing.module with the
function rvk_ticketing_create_ticket_form(). In order to re-arrange the form or add new fields,
the implementation goes here. Be aware though, that the hook_validate() and hook_submit() functions
are implemented as well, and if fields are moved or removed, a tweak of those functions is
necessary. hook_presave() is also implemented, so remember to go through it too.

The form is implemented with #tree => TRUE. That's because image fields are added by ajax, and I needed a way to contain
the images within an array.

The user can select his/hers location, either by clicking on a map or use Location services in the phone/web browser.
The user can also type in the address, which will then be displayed on the map. The address lookup is a service provided
by Borgarvefsjá module. Finally, the User can decide to enter his/hers contact information.

After submission, an email is sent to the user (given that he did enter his email).

Internal users
------------------------------------
Two user groups are within the internal usage: Service desk, which sorts the indications and forwards them to either
internal or external departments, and the users who actually handle the indications.

All users that are given access have to get the configuration parameter. That's the field we added to the user above.
The more granular the indication type is, the more granular the user will see the indications. E.g. if the user has
Umhverfis- og skipulagssvið, he can see everything below, but if he has Götur og gangstéttar, he will only see indications
below that, but not those assigned to Umhverfis- og skipulagssvið, nor the ones for Gróður and götugögn.

After an indication is sumbitted, some ajustments are made within the presave hook. One is time calculations. General
rule is that the service desk has two working days to respond to the indication. In order to determine what working days
are, I had to write a function determining what are considered holidays. The function
rvk_ticketing_get_last_response_date(DateTime $day, $days_to_respond = 2) handles that (and the helper functions below).
It takes into consideration Christmas, New Years day, Easter, Ascention of Jesus and Petecost, to name few (all of the
dates are defined in the helper function _rvk_ticketing_get_holidays_for_year() ). It also takes into consideration what
time the indication was sent, to make sure that if it was sent off-hours, that the counter will not start until the
service desk opens.

Few view blocks were created to display the indications to the service desk and the responders. The page /abendingar
is working off the user's configuration of what department he belongs to. The page is created with the function
rvk_ticketing_view_indications_page()  If the user is not working at the service desk, he will only get the indications
assigned to his indication type and those below it in the tree.

The process
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
The procecss of the indication is as follows:

New indication appears at the dashboard for those working at the service desk. They have overview of the status of all
indications, new, accepted, in progress and those who have gone over the accepted response time (as configured in the
module settings and in the taxonomy vocabulary settings). They can also see a
link to the closed indications page (which is a view page). A service desk employee will open each indication to review
it. Within each indication is a space to "interpret" the indication (rewrite it if the wording is hazy or inconclusive).
It also has a space for "internal communication", where employees can write comments that will not be shown on the
external web. Service desk also changes the status from New to Received (although, if the indication will have an
Indication type selected, other than Service desk, it will change the status).

All other employees that can see indication views that match their configuration on the User page. A new Indication is
actually a received one, other than that, they can do the same as Service desk to handle them.