Documentation for rvk_ticketing module and supporting modules.

I decided to implement this project as a module for several reasons, the biggest being able to
test and develop without having to work on the main website itself, since the project is using
a specific content type and (now five) taxonomy vocabularies.

I also decided to write three modules instead of one, abstracting the parts of street lookup
(Borgarvefsja) and communication with Mainmanager (mainmanager) to seperate modules. Both to reduce
code in the module, but also so others could use them, without having to enable this one.

When this module is installed, a content type Ábendingar (indications) is created, among with five
taxonomy vocabularies:  Ábendingategundir (indication types), Checkword items (categories from
Mainmanager), Deildir og svið (internal departments from city of Reykjavik), Utanaðkomandi deildir
 og svið (external departments: Strætó, Faxaflóahafnir and Orka Náttúrunnar) and Staða ábendingar
(indication status).  The taxonomies are all used within the content type.

When the vocabularies are created, they are also populated with data. The checkword taxonomy is
populated via an API configured and documented in the Mainmanager module.

Only configuration that has do be done after installing is entering the emails for the External
departments, as the Rules module uses that field to forward the indication to the external
department.

The content type relies on few modules, therefor they are set as dependencies:
Already on Reykjavik.is
Display suite (ds)
Views (views)
Field Group (field_group)
Entity Reference (entityreference)
Node Clone (clone)

Will be installed when this module is installed:
Node clone tab (node_clone_tab)
Rules (rules)
Rules Admin (rules_admin)

And of course the two seperate custom modules:
(borgarvefsja)
(mainmanager)

After the installation, go to the subfolder rules_to_be_imported to import the three rules there.
Rules are imported via this url: /admin/config/workflow/rules/reaction/import

Usage:
Like previously stated, the meat and potatoes of this module is the content type and the
taxonomy vocabularies that are with it, with few other goodies.

User creates a new indication by a multistep form, created in the rvk_ticketing.module with the
function rvk_ticketing_create_ticket_form(). In order to re-arrange the form or add new fields,
the implementation goes here. Be aware though, that the hook_validate() and hook_submit() functions
are implemented as well, and if fields are moved or removed, a tweak of those functions is
necessary.

In step one, the user can choose if he/she want's to use location information for the indication.
If selected, the user can use the map (default) to point to the location.