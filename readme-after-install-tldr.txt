/admin/structure/taxonomy/indication_types/fields/field_send_mail_f_new_indication
Please check the Use field label instead of the "On value" as label. Also enter Já as On value and Nei as Off value.

/admin/structure/taxonomy/external_departments (and then edit each external department)
Enter the email address each external department has.

All the rules undur rules_to_be_imported, need to be imported via the Rules UI

(/admin/structure/types/manage/indications/fields/field_indication_type_ref/widget-type).
Use Hierarchical Select Widget. It also has to have Save term linage, Allow the user to choose a term from any level and
Level labels enabled (Svið/Deild, Yfirflokkur, Undirflokkur).

/admin/config/people/accounts/fields
Add field_svid, which has a Taxonomy Term Reference to Ábendingategundir

/admin/structure/types/manage/indications/fields/field_indication_respond_by
/admin/structure/types/manage/indications/fields/field_indication_responded_at
/admin/structure/types/manage/indications/fields/field_indication_close_by
/admin/structure/types/manage/indications/fields/field_indication_closed_at
All those four dates have to get default value to None!!!!!!

Fieldgroups
=================================
Fieldgroups for the content type Indications (need to be there for display purposes):

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


/admin/config/search/path/patterns
We also need to change the pathauto config, to not use the title as url path, but node id's (abendingar/xxx)