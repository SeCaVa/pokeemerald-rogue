

// When changing this, make sure to:
// -bump ROGUE_SAVE_VERSION in rogue_save.h
// -update SAVE_VER_ID_X_Y_Z enum in rogue_save.h
const u8 gText_RogueVersion[] = _("v2.2.1");

#ifdef ROGUE_EXPANSION
const u8 gText_RogueVersionPrefix[] = _("EX");
#else
const u8 gText_RogueVersionPrefix[] = _("Vanilla");
#endif

#if defined(ROGUE_FEATURE_AUTOMATION)
const u8 gText_RogueVersionSuffix[] = _("(AUTOMATION)");
#elif defined(ROGUE_DEBUG)
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("(DEBUG)");
#else
const u8 gText_RogueVersionSpacer[] = _(" - ");
const u8 gText_RogueVersionSuffix[] = _("Modo Revisado + Z-A pt.2");
#endif

// UI String
//
const u8 gText_StatusRoute[] = _("Ruta: {STR_VAR_1}\n");
const u8 gText_StatusBadges[] = _("Medallas: {STR_VAR_1}\n");
const u8 gText_StatusScore[] = _("Puntos: {STR_VAR_1}\n");
const u8 gText_StatusTimer[] = _("Tiempo: {STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusClock[] = _("{STR_VAR_1}:{STR_VAR_2}\n");
const u8 gText_StatusSeasonSpring[] = _("·Primav.·");
const u8 gText_StatusSeasonSummer[] = _("·Verano·");
const u8 gText_StatusSeasonAutumn[] = _("·Otoño·");
const u8 gText_StatusSeasonWinter[] = _("·Invier.·");

// Colours aren't exact as they'll be used in battle UI
const u8 gText_MoveEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Eficaz");
const u8 gText_MoveNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}Sin efecto…");
const u8 gText_MoveSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Súper eficaz");
const u8 gText_MoveNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}Poco eficaz");
const u8 gText_MoveSlash[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}·");
const u8 gText_MoveShortEffective[] = _("{COLOR BLUE}{SHADOW DYNAMIC_COLOR6}Eficaz");
const u8 gText_MoveShortNoEffect[] = _("{COLOR TRANSPARENT}{SHADOW BLUE}SinEfc");
const u8 gText_MoveShortSuperEffective[] = _("{COLOR GREEN}{SHADOW DYNAMIC_COLOR6}Súper");
const u8 gText_MoveShortNotVeryEffective[] = _("{COLOR WHITE}{SHADOW DYNAMIC_COLOR6}PocoEf");


// Trainers
//
const u8 gText_TrainerName_Default[] = _("Rogue");

const u8 gText_TrainerName_Brendan[] = _("BRUNO");
const u8 gText_TrainerName_May[] = _("AURA");
const u8 gText_TrainerName_Red[] = _("ROJO");
const u8 gText_TrainerName_Leaf[] = _("HOJA");
const u8 gText_TrainerName_Ethan[] = _("ECO");
const u8 gText_TrainerName_Lyra[] = _("LIRA");

// Items
//
const u8 gText_EscapeRopeDesc[] = _(
    "Úsala para huir\n"
    "al instante de\n"
    "casi cualquier lugar.");

// Difficulty/Config lab settings
//

//{COLOR DARK_GRAY}{SHADOW DARK_GRAY} <default> orange tint
//{COLOR GREEN}{SHADOW LIGHT_GREEN} no tint
//{COLOR RED}{SHADOW LIGHT_RED} red tint
//{COLOR LIGHT_BLUE}{SHADOW BLUE} green tint
const u8 gText_16Spaces[] = _("                ");
const u8 gText_32Spaces[] = _("                                ");

const u8 gText_DifficultySettings[] = _("Ajustes de dificultad");
const u8 gText_DifficultyArrowLeft[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{LEFT_ARROW}");
const u8 gText_DifficultyArrowRight[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{RIGHT_ARROW}");

const u8 gText_DifficultyDoesntAffectReward[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}(no afecta a premios)");
const u8 gText_DifficultyRewardLevel[] = _("{FONT_SMALL}{COLOR GREEN}{SHADOW LIGHT_GREEN}Premios: ");

const u8 gText_DifficultyPreset[] = _("Dificultad");

// Colours on the Settings Screen are out of order and wild
//LIGHT_BLUE = green
//BLUE = light green
//LIGHT_RED = red
//RED = light red
//DARK_GRAY = light yellow
//LIGHT_GRAY = dark yellow
//LIGHT_GREEN = light grey
const u8 gText_DifficultyPresetEasy[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Fácil");
const u8 gText_DifficultyPresetMedium[] = _("{COLOR LIGHT_BLUE}{SHADOW LIGHT_GREEN}Normal");
const u8 gText_DifficultyPresetHard[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}Difícil");
const u8 gText_DifficultyPresetBrutal[] = _("{COLOR LIGHT_RED}{SHADOW RED}Brutal");
const u8 gText_DifficultyPresetCustom[] = _("{COLOR DARK_GRAY}{SHADOW LIGHT_GREEN}Personal.");

const u8 gText_DifficultyEnabled[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}Activado  ");
const u8 gText_DifficultyDisabled[] = _("{COLOR LIGHT_RED}{SHADOW LIGHT_GREEN}Desactiv.");
const u8 gText_DifficultyModeActive[] = _("{COLOR LIGHT_BLUE}{SHADOW BLUE}¡Activo!");

const u8 gText_DifficultyExpAll[] = _("Repartir Exp.");
const u8 gText_DifficultyOverLvl[] = _("Sobrenivel");
const u8 gText_DifficultyEVGain[] = _("Ganar EV");
const u8 gText_DifficultyOverworldMons[] = _("{PKMN} salvajes visibles");
const u8 gText_DifficultyBagWipe[] = _("Nuevo comienzo");
const u8 gText_DifficultySwitchMode[] = _("Modo cambio");

const u8 gText_DifficultyTrainers[] = _("Entrenadores");
const u8 gText_DifficultyItems[] = _("Objetos");
const u8 gText_DifficultyLegendaries[] = _("Legendarios");

const u8 gText_DifficultyCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Cambia ajustes individuales y adapta\n"
    "la dificultad a tu gusto."
);

const u8 gText_AdventureCustomDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Cambia ajustes individuales y adapta\n"
    "la aventura a tu gusto."
);

const u8 gText_DifficultyTrainersDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Ajusta la calidad, cantidad y fuerza\n"
    "de los {PKMN} de los Entrenadores."
);

const u8 gText_DifficultyItemsDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Pendiente de revisión..."
);

const u8 gText_DifficultyLegendariesDesc[] = _(
    "{COLOR GREEN}{SHADOW LIGHT_GREEN}"
    "Reduce la calidad y cantidad de\n"
    "encuentros con {PKMN} Legendarios."
);

// Campaigns
//
const u8 gText_CampaignHofTitle[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}{STR_VAR_1}");

const u8 gText_Campaign_None[] = _("???");
const u8 gText_Campaign_LowBST[] = _("COPA BST");
const u8 gText_Campaign_Classic[] = _("Modo Clásico");
const u8 gText_Campaign_MiniBossBattler[] = _("Adicto al Combate");
const u8 gText_Campaign_AutoBattler[] = _("Combate Automático");
const u8 gText_Campaign_LaterManner[] = _("Modo LaterManner");
const u8 gText_Campaign_PokeballLimit[] = _("Captura Limitada");
const u8 gText_Campaign_OneHp[] = _("Modo Un Golpe");

// Debug
//
#ifdef ROGUE_DEBUG
const u8 gText_RogueDebug_Header[] = _("ROGUE DEBUG");
const u8 gText_RogueDebug_Save[] = _("\nSave: ");
const u8 gText_RogueDebug_Room[] = _("\nRoom: ");
const u8 gText_RogueDebug_BossRoom[] = _("\nBossRoom: ");
const u8 gText_RogueDebug_Difficulty[] = _("\nDfcy: ");
const u8 gText_RogueDebug_PlayerLvl[] = _("\nPly lvl: ");
const u8 gText_RogueDebug_WildLvl[] = _("\nWld lvl: ");
const u8 gText_RogueDebug_WildCount[] = _("\nWld Opt: ");
const u8 gText_RogueDebug_ItemCount[] = _("\nItm Opt: ");
const u8 gText_RogueDebug_TrainerCount[] = _("\nTrn Opt: ");
const u8 gText_RogueDebug_Seed[] = _("\nSeed: ");

const u8 gText_RogueDebug_AdvHeader[] = _("ROGUE ADVPATH");
const u8 gText_RogueDebug_AdvCount[] = _("\nCount: ");
const u8 gText_RogueDebug_X[] = _("\nX: ");
const u8 gText_RogueDebug_Y[] = _("\nY: ");
#endif