static const u8 sDummyDesc[] = _(
    "?????");

// Poké Balls
static const u8 sPokeBallDesc[] = _(
    "Dispositivo\n"
    "capsular que atrapa\n"
    "Pokémon salvajes.");

static const u8 sGreatBallDesc[] = _(
    "Poké Ball de alto\n"
    "rendimiento.");

static const u8 sUltraBallDesc[] = _(
    "Poké Ball de\n"
    "rendimiento\n"
    "superior.");

static const u8 sMasterBallDesc[] = _(
    "La Poké Ball\n"
    "definitiva. Nunca\n"
    "falla.");

static const u8 sPremierBallDesc[] = _(
    "Poké Ball\n"
    "conmemorativa\n"
    "singular.");

static const u8 sHealBallDesc[] = _(
    "Poké Ball que cura\n"
    "PS y estado al\n"
    "Pokémon capturado.");

static const u8 sNetBallDesc[] = _(
    "Ideal para Pokémon\n"
    "Agua y Bicho.");

static const u8 sNestBallDesc[] = _(
    "Ideal para Pokémon\n"
    "de nivel bajo.");

static const u8 sDiveBallDesc[] = _(
    "Ideal para Pokémon\n"
    "que viven bajo el\n"
    "agua.");

static const u8 sDuskBallDesc[] = _(
    "Más fácil capturar\n"
    "de noche o en\n"
    "lugares oscuros.");

static const u8 sTimerBallDesc[] = _(
    "Mejora con cada\n"
    "turno de combate.");

static const u8 sQuickBallDesc[] = _(
    "Captura mejor si se\n"
    "usa al inicio del\n"
    "encuentro.");

static const u8 sRepeatBallDesc[] = _(
    "Funciona bien con\n"
    "especies ya\n"
    "capturadas.");

static const u8 sLuxuryBallDesc[] = _(
    "Acogedora Ball que\n"
    "da más amistad.");

static const u8 sLevelBallDesc[] = _(
    "Funciona bien con\n"
    "Pokémon de nivel\n"
    "inferior al tuyo.");

static const u8 sLureBallDesc[] = _(
    "Indicada para los\n"
    "Pokémon pescados\n"
    "con caña.");

static const u8 sMoonBallDesc[] = _(
    "Atrapa mejor a los\n"
    "que evolucionan con\n"
    "Piedra Lunar.");

static const u8 sFriendBallDesc[] = _(
    "Hace más amistosos\n"
    "a los Pokémon que\n"
    "captura.");

static const u8 sLoveBallDesc[] = _(
    "Atrapa mejor a los\n"
    "de tu especie y sexo\n"
    "opuesto.");

static const u8 sFastBallDesc[] = _(
    "Especialmente\n"
    "indicada para\n"
    "Pokémon evasivos.");

static const u8 sHeavyBallDesc[] = _(
    "Funciona bien con\n"
    "Pokémon de mucho\n"
    "peso.");

static const u8 sDreamBallDesc[] = _(
#if B_DREAM_BALL_MODIFIER >= GEN_8
    "A Ball that works\n"
    "well on sleeping\n"
    "Pokémon.");
#else
    "A Poké Ball used in\n"
    "the Entree Forest.");
#endif

static const u8 sSafariBallDesc[] = _(
    "Poké Ball especial\n"
    "de la Zona Safari.");

static const u8 sSportBallDesc[] = _(
    "Poké Ball especial\n"
    "del Concurso de\n"
    "Captura de Bichos.");

static const u8 sParkBallDesc[] = _(
    "Poké Ball que se\n"
    "utiliza dentro del\n"
    "Parque Compi.");

static const u8 sBeastBallDesc[] = _(
    "Poké Ball especial\n"
    "con la que es difícil\n"
    "atrapar Pokémon.");

static const u8 sCherishBallDesc[] = _(
    "Poké Ball singular\n"
    "creada para una\n"
    "ocasión especial.");

// Medicine
static const u8 sPotionDesc[] = _(
    "Medicina en espray\n"
    "que restaura 20 PS a\n"
    "un Pokémon.");

static const u8 sSuperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "60 points.");
#else
    "50 points.");
#endif

static const u8 sHyperPotionDesc[] = _(
    "Restores the HP of\n"
    "a Pokémon by\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "120 points.");
#else
    "200 points.");
#endif

static const u8 sMaxPotionDesc[] = _(
    "Medicina en espray\n"
    "que restaura todos\n"
    "los PS.");

static const u8 sFullRestoreDesc[] = _(
    "Restaura todos los\n"
    "PS y cura todos los\n"
    "estados.");

static const u8 sReviveDesc[] = _(
    "Revive a un Pokémon\n"
    "debilitado con la\n"
    "mitad de PS.");

static const u8 sMaxReviveDesc[] = _(
    "Revive a un Pokémon\n"
    "debilitado con\n"
    "todos sus PS.");

static const u8 sFreshWaterDesc[] = _(
    "A mineral water\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 30 points.");
#else
    "by 50 points.");
#endif

static const u8 sSodaPopDesc[] = _(
    "A fizzy soda drink\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 50 points.");
#else
    "by 60 points.");
#endif

static const u8 sLemonadeDesc[] = _(
    "A very sweet drink\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 70 points.");
#else
    "by 80 points.");
#endif

static const u8 sMoomooMilkDesc[] = _(
    "Leche muy nutritiva\n"
    "que restaura 100 PS.");

static const u8 sEnergyPowderDesc[] = _(
    "A bitter powder\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 60 points.");
#else
    "by 50 points.");
#endif

static const u8 sEnergyRootDesc[] = _(
    "A bitter root\n"
    "that restores HP\n"
#if I_HEALTH_RECOVERY >= GEN_7
    "by 120 points.");
#else
    "by 200 points.");
#endif

static const u8 sHealPowderDesc[] = _(
    "Polvos muy amargos\n"
    "que curan todos los\n"
    "estados.");

static const u8 sRevivalHerbDesc[] = _(
    "Hierba muy amarga\n"
    "que reanima con\n"
    "todos los PS.");

static const u8 sAntidoteDesc[] = _(
    "Espray que cura el\n"
    "envenenamiento.");

static const u8 sParalyzeHealDesc[] = _(
    "Medicina en espray\n"
    "que cura a un\n"
    "Pokémon paralizado.");

static const u8 sBurnHealDesc[] = _(
    "Espray que cura las\n"
    "quemaduras.");

static const u8 sIceHealDesc[] = _(
    "Medicina en espray\n"
    "que descongela a un\n"
    "Pokémon.");

static const u8 sAwakeningDesc[] = _(
    "Espray que\n"
    "despierta a un\n"
    "Pokémon dormido.");

static const u8 sFullHealDesc[] = _(
    "Espray que cura\n"
    "todos los problemas\n"
    "de estado.");

static const u8 sEtherDesc[] = _(
    "Restaura 10 PP del\n"
    "movimiento elegido\n"
    "de un Pokémon.");

static const u8 sMaxEtherDesc[] = _(
    "Restaura todos los\n"
    "PP de un movimiento.");

static const u8 sElixirDesc[] = _(
    "Restaura 10 PP de\n"
    "todos los\n"
    "movimientos.");

static const u8 sMaxElixirDesc[] = _(
    "Restaura todos los\n"
    "PP de todos los\n"
    "movimientos.");

static const u8 sBerryJuiceDesc[] = _(
    "Zumo de bayas 100%\n"
    "natural que\n"
    "restaura 20 PS.");

static const u8 sSacredAshDesc[] = _(
    "Reanima a todos los\n"
    "debilitados con\n"
    "todos sus PS.");

static const u8 sSweetHeartDesc[] = _(
    "Chocolatina dulce\n"
    "que restaura 20 PS.");

static const u8 sMaxHoneyDesc[] = _(
    "Miel que revive a un\n"
    "Pokémon debilitado\n"
    "con todos sus PS.");

static const u8 sPewterCrunchiesDesc[] = _(
    "Tentempié de Ciudad\n"
    "Plateada. Cura el\n"
    "estado.");

static const u8 sRageCandyBarDesc[] = _(
    "Caramelo de Pueblo\n"
    "Caoba. Cura el\n"
    "estado.");

static const u8 sLavaCookieDesc[] = _(
    "Dulce típico que\n"
    "cura los estados.");

static const u8 sOldGateauDesc[] = _(
    "Dulce de la Vieja\n"
    "Mansión. Cura el\n"
    "estado.");

static const u8 sCasteliaconeDesc[] = _(
    "Helado de Ciudad\n"
    "Porcelana. Cura el\n"
    "estado.");

static const u8 sLumioseGaletteDesc[] = _(
    "Galleta de Ciudad\n"
    "Luminalia. Cura el\n"
    "estado.");

static const u8 sShalourSableDesc[] = _(
    "Pasta de Ciudad\n"
    "Yantra. Cura el\n"
    "estado.");

static const u8 sBigMalasadaDesc[] = _(
    "Fritura típica de\n"
    "Alola. Cura el\n"
    "estado.");

// Vitamins
static const u8 sHPUpDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia los PS\n"
    "de base.");

static const u8 sProteinDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia el\n"
    "Ataque de base.");

static const u8 sIronDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia la\n"
    "Defensa de base.");

static const u8 sCalciumDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia el\n"
    "At. Esp. de base.");

static const u8 sZincDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia la\n"
    "Def. Esp. de base.");

static const u8 sCarbosDesc[] = _(
    "Bebida nutritiva\n"
    "que potencia la\n"
    "Velocidad de base.");

static const u8 sPPUpDesc[] = _(
    "Aumenta un poco los\n"
    "PP máximos de un\n"
    "movimiento.");

static const u8 sPPMaxDesc[] = _(
    "Aumenta al límite\n"
    "los PP máximos de un\n"
    "movimiento.");

// EV Feathers
static const u8 sHealthFeatherDesc[] = _(
    "Sube los PS base de\n"
    "un Pokémon.");

static const u8 sMuscleFeatherDesc[] = _(
    "Sube el Ataque base\n"
    "de un Pokémon.");

static const u8 sResistFeatherDesc[] = _(
    "Sube la Defensa\n"
    "base de un Pokémon.");

static const u8 sGeniusFeatherDesc[] = _(
    "Sube el At. Esp. base\n"
    "de un Pokémon.");

static const u8 sCleverFeatherDesc[] = _(
    "Sube la Def. Esp.\n"
    "base de un Pokémon.");

static const u8 sSwiftFeatherDesc[] = _(
    "Sube la Velocidad\n"
    "base de un Pokémon.");

// Ability Modifiers
static const u8 sAbilityCapsuleDesc[] = _(
    "Cambia entre las dos\n"
    "habilidades de un\n"
    "Pokémon.");

static const u8 sAbilityPatchDesc[] = _(
    "Cambia la habilidad\n"
    "a otra menos común.");

// Mints
static const u8 sLonelyMintDesc[] = _(
    "Su aroma favorece\n"
    "Ataque, no Defensa.");

static const u8 sAdamantMintDesc[] = _(
    "Su aroma favorece\n"
    "Ataque, no At. Esp.");

static const u8 sNaughtyMintDesc[] = _(
    "Su aroma favorece\n"
    "Ataque, no Def. Esp.");

static const u8 sBraveMintDesc[] = _(
    "Su aroma favorece\n"
    "Ataque, no\n"
    "Velocidad.");

static const u8 sBoldMintDesc[] = _(
    "Su aroma favorece\n"
    "Defensa, no Ataque.");

static const u8 sImpishMintDesc[] = _(
    "Su aroma favorece\n"
    "Defensa, no At. Esp.");

static const u8 sLaxMintDesc[] = _(
    "Su aroma favorece\n"
    "Defensa, no\n"
    "Def. Esp.");

static const u8 sRelaxedMintDesc[] = _(
    "Su aroma favorece\n"
    "Defensa, no\n"
    "Velocidad.");

static const u8 sModestMintDesc[] = _(
    "Su aroma favorece\n"
    "At. Esp., no Ataque.");

static const u8 sMildMintDesc[] = _(
    "Su aroma favorece\n"
    "At. Esp., no Defensa.");

static const u8 sRashMintDesc[] = _(
    "Su aroma favorece\n"
    "At. Esp., no Def. Esp.");

static const u8 sQuietMintDesc[] = _(
    "Su aroma favorece\n"
    "At. Esp., no\n"
    "Velocidad.");

static const u8 sCalmMintDesc[] = _(
    "Su aroma favorece\n"
    "Def. Esp., no Ataque.");

static const u8 sGentleMintDesc[] = _(
    "Su aroma favorece\n"
    "Def. Esp., no\n"
    "Defensa.");

static const u8 sCarefulMintDesc[] = _(
    "Su aroma favorece\n"
    "Def. Esp., no At. Esp.");

static const u8 sSassyMintDesc[] = _(
    "Su aroma favorece\n"
    "Def. Esp., no\n"
    "Velocidad.");

static const u8 sTimidMintDesc[] = _(
    "Su aroma favorece\n"
    "Velocidad, no\n"
    "Ataque.");

static const u8 sHastyMintDesc[] = _(
    "Su aroma favorece\n"
    "Velocidad, no\n"
    "Defensa.");

static const u8 sJollyMintDesc[] = _(
    "Su aroma favorece\n"
    "Velocidad, no\n"
    "At. Esp.");

static const u8 sNaiveMintDesc[] = _(
    "Su aroma favorece\n"
    "Velocidad, no\n"
    "Def. Esp.");

static const u8 sSeriousMintDesc[] = _(
    "Con su aroma, todas\n"
    "las características\n"
    "crecen igual.");

// Candy
static const u8 sRareCandyDesc[] = _(
    "Caramelo energético\n"
    "que sube a un\n"
    "Pokémon de nivel.");

static const u8 sExpCandyXSDesc[] = _(
    "Caramelo que da muy\n"
    "poca experiencia a\n"
    "un Pokémon.");

static const u8 sExpCandySDesc[] = _(
    "Caramelo que da\n"
    "poca experiencia a\n"
    "un Pokémon.");

static const u8 sExpCandyMDesc[] = _(
    "Caramelo que da\n"
    "experiencia a un\n"
    "Pokémon.");

static const u8 sExpCandyLDesc[] = _(
    "Caramelo que da\n"
    "bastante\n"
    "experiencia.");

static const u8 sExpCandyXLDesc[] = _(
    "Caramelo que da\n"
    "mucha experiencia a\n"
    "un Pokémon.");

static const u8 sDynamaxCandyDesc[] = _(
    "Caramelo que sube el\n"
    "nivel Dinamax de un\n"
    "Pokémon.");

// Medicinal Flutes
static const u8 sBlueFluteDesc[] = _(
    "Flauta de cristal\n"
    "azul que despierta a\n"
    "un Pokémon.");

static const u8 sYellowFluteDesc[] = _(
    "Flauta de cristal\n"
    "amarillo que quita la\n"
    "confusión.");

static const u8 sRedFluteDesc[] = _(
    "Flauta de cristal\n"
    "rojo que quita el\n"
    "enamoramiento.");

// Encounter-modifying Flutes
static const u8 sBlackFluteDesc[] = _(
    "Flauta negra: atrae\n"
    "Pokémon fuertes.");

static const u8 sWhiteFluteDesc[] = _(
    "Flauta blanca: atrae\n"
    "Pokémon débiles.");

// Encounter Modifiers
static const u8 sRepelDesc[] = _(
    "Evita Pokémon\n"
    "salvajes débiles\n"
    "durante 100 pasos.");

static const u8 sSuperRepelDesc[] = _(
    "Evita Pokémon\n"
    "salvajes débiles\n"
    "durante 200 pasos.");

static const u8 sMaxRepelDesc[] = _(
    "Evita Pokémon\n"
    "salvajes débiles\n"
    "durante 250 pasos.");

static const u8 sLureDesc[] = _(
    "Colonia que atrae\n"
    "Pokémon durante\n"
    "100 pasos.");

static const u8 sSuperLureDesc[] = _(
    "Colonia que atrae\n"
    "Pokémon durante\n"
    "200 pasos.");

static const u8 sMaxLureDesc[] = _(
    "Colonia que atrae\n"
    "Pokémon durante\n"
    "250 pasos.");

static const u8 sEscapeRopeDesc[] = _(
    "Cuerda larga y\n"
    "resistente para\n"
    "huir de cuevas.");

// Battle items
static const u8 sXAttackDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Attack during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Attack during one\n"
    "battle.");
#endif

static const u8 sXDefenseDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Defense during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Defense during one\n"
    "battle.");
#endif

static const u8 sXSpAtkDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Sp. Atk during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Sp. Atk during one\n"
    "battle.");
#endif

static const u8 sXSpDefDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Sp. Def during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Sp. Def during one\n"
    "battle.");
#endif

static const u8 sXSpeedDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises stat\n"
    "Speed during\n"
    "one battle.");
#else
    "Raises the stat\n"
    "Speed during one\n"
    "battle.");
#endif

static const u8 sXAccuracyDesc[] = _(
#if B_X_ITEMS_BUFF >= GEN_7
    "Sharply raises move\n"
    "accuracy during\n"
    "one battle.");
#else
    "Raises accuracy\n"
    "of attack moves\n"
    "during one battle.");
#endif

static const u8 sDireHitDesc[] = _(
    "Aumenta el índice\n"
    "de crítico en\n"
    "combate.");

static const u8 sGuardSpecDesc[] = _(
    "Evita que bajen las\n"
    "características del\n"
    "equipo 5 turnos.");

// Escape Items
static const u8 sPokeDollDesc[] = _(
    "Un muñeco que atrae\n"
    "a los Pokémon. Sirve\n"
    "para huir.");

static const u8 sFluffyTailDesc[] = _(
    "Objeto que atrae a\n"
    "los Pokémon. Sirve\n"
    "para huir.");

static const u8 sPokeToyDesc[] = _(
    "Juguete que atrae a\n"
    "los Pokémon. Sirve\n"
    "para huir.");

static const u8 sMaxMushroomsDesc[] = _(
    "Aumenta todas las\n"
    "características en\n"
    "combate.");

// Treasures
static const u8 sBottleCapDesc[] = _(
    "Una bonita chapa\n"
    "plateada muy\n"
    "apreciada.");

static const u8 sGoldBottleCapDesc[] = _(
    "Una bonita chapa\n"
    "dorada muy\n"
    "apreciada.");

static const u8 sNuggetDesc[] = _(
    "Pepita de oro puro.\n"
    "Se vende muy cara.");

static const u8 sBigNuggetDesc[] = _(
    "Pepita grande de\n"
    "oro puro. Se vende\n"
    "muy cara.");

static const u8 sTinyMushroomDesc[] = _(
    "Seta pequeña y poco\n"
    "común, popular\n"
    "entre gourmets.");

static const u8 sBigMushroomDesc[] = _(
    "Seta grande y poco\n"
    "común, muy popular\n"
    "entre gourmets.");

static const u8 sBalmMushroomDesc[] = _(
    "Seta de agradable\n"
    "aroma. Se vende a\n"
    "buen precio.");

static const u8 sPearlDesc[] = _(
    "Perla pequeña y\n"
    "plateada. Se vende\n"
    "barata.");

static const u8 sBigPearlDesc[] = _(
    "Perla plateada\n"
    "grande. Se vende a\n"
    "buen precio.");

static const u8 sPearlStringDesc[] = _(
    "Perlas plateadas\n"
    "grandes. Se venden\n"
    "a buen precio.");

static const u8 sStardustDesc[] = _(
    "Bonita arena roja.\n"
    "Se vende barata.");

static const u8 sStarPieceDesc[] = _(
    "Fragmento de una\n"
    "bonita gema roja. Se\n"
    "vende muy caro.");

static const u8 sCometShardDesc[] = _(
    "Fragmento de un\n"
    "cometa. Se vende a\n"
    "buen precio.");

static const u8 sShoalSaltDesc[] = _(
    "Una sal muy fina que\n"
    "se encuentra en la\n"
    "Cueva Cardumen.");

static const u8 sShoalShellDesc[] = _(
    "Concha que se\n"
    "encuentra en la\n"
    "Cueva Cardumen.");

static const u8 sRedShardDesc[] = _(
    "Fragmento rojo de\n"
    "una herramienta\n"
    "antigua.");

static const u8 sBlueShardDesc[] = _(
    "Fragmento azul de\n"
    "una herramienta\n"
    "antigua.");

static const u8 sYellowShardDesc[] = _(
    "Fragmento amarillo\n"
    "de una herramienta\n"
    "antigua.");

static const u8 sGreenShardDesc[] = _(
    "Fragmento verde de\n"
    "una herramienta\n"
    "antigua.");

static const u8 sHeartScaleDesc[] = _(
    "Bella y rara escama\n"
    "con forma de\n"
    "corazón.");

static const u8 sHoneyDesc[] = _(
    "Miel de dulce aroma\n"
    "recolectada por\n"
    "Pokémon.");

static const u8 sRareBoneDesc[] = _(
    "Hueso de gran valor\n"
    "arqueológico. Se\n"
    "vende caro.");

static const u8 sOddKeystoneDesc[] = _(
    "A veces se oyen\n"
    "voces en su\n"
    "interior.");

static const u8 sPrettyFeatherDesc[] = _(
    "Una pluma bonita\n"
    "pero corriente. No\n"
    "hace nada.");

static const u8 sRelicCopperDesc[] = _(
    "Moneda de cobre de\n"
    "más de 3000 años de\n"
    "antigüedad.");

static const u8 sRelicSilverDesc[] = _(
    "Moneda de plata de\n"
    "más de 3000 años de\n"
    "antigüedad.");

static const u8 sRelicGoldDesc[] = _(
    "Moneda de oro de\n"
    "más de 3000 años de\n"
    "antigüedad.");

static const u8 sRelicVaseDesc[] = _(
    "Jarrón de más de\n"
    "3000 años de\n"
    "antigüedad.");

static const u8 sRelicBandDesc[] = _(
    "Brazalete de más de\n"
    "3000 años de\n"
    "antigüedad.");

static const u8 sRelicStatueDesc[] = _(
    "Efigie de piedra de\n"
    "más de 3000 años de\n"
    "antigüedad.");

static const u8 sRelicCrownDesc[] = _(
    "Corona de más de\n"
    "3000 años de\n"
    "antigüedad.");

static const u8 sStrangeSouvenirDesc[] = _(
    "Ornamento de un\n"
    "Pokémon venerado\n"
    "en Alola.");

// Fossils
static const u8 sHelixFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "del fondo marino.\n"
    "Parece una concha.");

static const u8 sDomeFossilDesc[] = _(
    "Fósil marino. Parece\n"
    "un caparazón.");

static const u8 sOldAmberDesc[] = _(
    "Ámbar con genes de\n"
    "un Pokémon antiguo.");

static const u8 sRootFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "del fondo marino.\n"
    "Parece una raíz.");

static const u8 sClawFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "del fondo marino.\n"
    "Parece una garra.");

static const u8 sArmorFossilDesc[] = _(
    "Fósil terrestre.\n"
    "Parece una placa\n"
    "ósea.");

static const u8 sSkullFossilDesc[] = _(
    "Fósil terrestre.\n"
    "Parece parte de una\n"
    "cabeza.");

static const u8 sCoverFossilDesc[] = _(
    "Fósil marino. Parece\n"
    "un caparazón.");

static const u8 sPlumeFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "volador. Parece un\n"
    "ala.");

static const u8 sJawFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "terrestre. Parece\n"
    "una mandíbula.");

static const u8 sSailFossilDesc[] = _(
    "Fósil de un Pokémon\n"
    "terrestre. Parece la\n"
    "huella de una aleta.");

static const u8 sFossilizedBirdDesc[] = _(
    "Fósil de un Pokémon\n"
    "antiguo que surcaba\n"
    "los cielos.");

static const u8 sFossilizedFishDesc[] = _(
    "Fósil de un Pokémon\n"
    "antiguo que\n"
    "habitaba en el mar.");

static const u8 sFossilizedDrakeDesc[] = _(
    "Fósil de un Pokémon\n"
    "antiguo que\n"
    "habitaba en tierra.");

static const u8 sFossilizedDinoDesc[] = _(
    "Fósil de un Pokémon\n"
    "antiguo que\n"
    "habitaba en el mar.");

// Mulch
static const u8 sGrowthMulchDesc[] = _(
    "Abono que acelera el\n"
    "crecimiento de las\n"
    "bayas.");

static const u8 sDampMulchDesc[] = _(
    "Abono que frena el\n"
    "crecimiento de las\n"
    "bayas.");

static const u8 sStableMulchDesc[] = _(
    "Abono que alarga la\n"
    "vida de las plantas\n"
    "de bayas.");

static const u8 sGooeyMulchDesc[] = _(
    "Abono que hace que\n"
    "rebroten más bayas.");

static const u8 sRichMulchDesc[] = _(
    "Abono que aumenta\n"
    "las bayas\n"
    "cosechadas.");

static const u8 sSurpriseMulchDesc[] = _(
    "Abono que aumenta\n"
    "las mutaciones de\n"
    "bayas.");

static const u8 sBoostMulchDesc[] = _(
    "Abono que hace que\n"
    "la tierra se seque\n"
    "antes.");

static const u8 sAmazeMulchDesc[] = _(
    "Abono con efectos\n"
    "Rico, Sorpresa y\n"
    "Fructífero.");

// Apricorns
static const u8 sRedApricornDesc[] = _(
    "Bonguri de color\n"
    "rojo y aroma muy\n"
    "penetrante.");

static const u8 sBlueApricornDesc[] = _(
    "Bonguri de color\n"
    "azul y aroma tierno.");

static const u8 sYellowApricornDesc[] = _(
    "Bonguri de color\n"
    "amarillo y aroma\n"
    "refrescante.");

static const u8 sGreenApricornDesc[] = _(
    "Bonguri verde con\n"
    "aroma a café\n"
    "tostado.");

static const u8 sPinkApricornDesc[] = _(
    "Bonguri de color\n"
    "rosa y aroma dulce.");

static const u8 sWhiteApricornDesc[] = _(
    "Bonguri blanco que\n"
    "no desprende aroma\n"
    "alguno.");

static const u8 sBlackApricornDesc[] = _(
    "Bonguri de color\n"
    "negro y aroma\n"
    "indescriptible.");

static const u8 sWishingPieceDesc[] = _(
    "Al lanzarlo en un\n"
    "nido, aparece un\n"
    "Pokémon Dinamax.");

static const u8 sGalaricaTwigDesc[] = _(
    "Rama de Galanuez.\n"
    "Sirve para crear\n"
    "accesorios.");

static const u8 sArmoriteOreDesc[] = _(
    "Mineral poco común\n"
    "de la Isla de la\n"
    "Armadura.");

static const u8 sDyniteOreDesc[] = _(
    "Extraño mineral del\n"
    "Supernido Dinamax.");

// Mail
static const u8 sOrangeMailDesc[] = _(
    "Carta con dibujos\n"
    "de Zigzagoon para\n"
    "un Pokémon.");

static const u8 sHarborMailDesc[] = _(
    "Carta con dibujos\n"
    "de Wingull para un\n"
    "Pokémon.");

static const u8 sGlitterMailDesc[] = _(
    "Carta con dibujos\n"
    "de Pikachu para un\n"
    "Pokémon.");

static const u8 sMechMailDesc[] = _(
    "Carta con dibujos\n"
    "de Magnemite para\n"
    "un Pokémon.");

static const u8 sWoodMailDesc[] = _(
    "Carta con dibujos\n"
    "de Slakoth para un\n"
    "Pokémon.");

static const u8 sWaveMailDesc[] = _(
    "Carta con dibujos\n"
    "de Wailmer para un\n"
    "Pokémon.");

static const u8 sBeadMailDesc[] = _(
    "Carta con un dibujo\n"
    "del Pokémon que la\n"
    "lleva.");

static const u8 sShadowMailDesc[] = _(
    "Carta con dibujos\n"
    "de Duskull para un\n"
    "Pokémon.");

static const u8 sTropicMailDesc[] = _(
    "Carta con dibujos\n"
    "de Bellossom para un\n"
    "Pokémon.");

static const u8 sDreamMailDesc[] = _(
    "Carta con un dibujo\n"
    "del Pokémon que la\n"
    "lleva.");

static const u8 sFabMailDesc[] = _(
    "Carta con un dibujo\n"
    "precioso para un\n"
    "Pokémon.");

static const u8 sRetroMailDesc[] = _(
    "Carta con los\n"
    "dibujos de tres\n"
    "Pokémon.");

// Evolution Items
static const u8 sFireStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon. Es\n"
    "naranja.");

static const u8 sWaterStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon. Es\n"
    "azul.");

static const u8 sThunderStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon.\n"
    "Tiene un rayo.");

static const u8 sLeafStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon.\n"
    "Tiene una hoja.");

static const u8 sIceStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon.\n"
    "Parece de hielo.");

static const u8 sSunStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon. Es\n"
    "roja como el sol.");

static const u8 sMoonStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon. Es\n"
    "negra.");

static const u8 sShinyStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon.\n"
    "Brilla mucho.");

static const u8 sDuskStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon. Es\n"
    "muy oscura.");

static const u8 sDawnStoneDesc[] = _(
    "Hace evolucionar a\n"
    "ciertos Pokémon.\n"
    "Brilla como el alba.");

static const u8 sSweetAppleDesc[] = _(
    "Manzana muy dulce.\n"
    "Hace evolucionar.");

static const u8 sTartAppleDesc[] = _(
    "Manzana muy ácida.\n"
    "Hace evolucionar.");

static const u8 sCrackedPotDesc[] = _(
    "Tetera agrietada.\n"
    "Hace evolucionar.");

static const u8 sChippedPotDesc[] = _(
    "Tetera rota que\n"
    "hace evolucionar a\n"
    "ciertos Pokémon.");

static const u8 sGalaricaCuffDesc[] = _(
    "Brazalete de\n"
    "Galanuez para\n"
    "Slowpoke.");

static const u8 sGalaricaWreathDesc[] = _(
    "Corona de Galanuez\n"
    "que adoran los\n"
    "Slowpoke de Galar.");

static const u8 sDragonScaleDesc[] = _(
    "Gruesa y resistente\n"
    "escama de los\n"
    "Pokémon Dragón.");

static const u8 sUpgradeDesc[] = _(
    "Una caja peculiar\n"
    "fabricada por Silph\n"
    "S.A.");

static const u8 sProtectorDesc[] = _(
    "Protección muy\n"
    "pesada que adora un\n"
    "Pokémon.");

static const u8 sElectirizerDesc[] = _(
    "Contiene mucha\n"
    "energía eléctrica.\n"
    "Un Pokémon lo adora.");

static const u8 sMagmarizerDesc[] = _(
    "Contiene mucha\n"
    "energía magmática.\n"
    "Un Pokémon la adora.");

static const u8 sDubiousDiscDesc[] = _(
    "Dispositivo\n"
    "transparente con\n"
    "datos misteriosos.");

static const u8 sReaperClothDesc[] = _(
    "Tela con una\n"
    "potente energía\n"
    "espiritual.");

static const u8 sPrismScaleDesc[] = _(
    "Escama que brilla\n"
    "con los colores del\n"
    "arcoíris.");

static const u8 sWhippedDreamDesc[] = _(
    "Dulce de nata que\n"
    "adora cierto\n"
    "Pokémon.");

static const u8 sSachetDesc[] = _(
    "Saquito aromático\n"
    "que le encanta a\n"
    "cierto Pokémon.");

static const u8 sOvalStoneDesc[] = _(
    "Piedra con forma de\n"
    "huevo que hace\n"
    "evolucionar.");

static const u8 sStrawberrySweetDesc[] = _(
    "Caramelo con forma\n"
    "de fresa que adora\n"
    "Milcery.");

static const u8 sLoveSweetDesc[] = _(
    "Caramelo con forma\n"
    "de corazón que\n"
    "adora Milcery.");

static const u8 sBerrySweetDesc[] = _(
    "Caramelo con forma\n"
    "de baya que adora\n"
    "Milcery.");

static const u8 sCloverSweetDesc[] = _(
    "Caramelo con forma\n"
    "de trébol que adora\n"
    "Milcery.");

static const u8 sFlowerSweetDesc[] = _(
    "Caramelo con forma\n"
    "de flor que adora\n"
    "Milcery.");

static const u8 sStarSweetDesc[] = _(
    "Caramelo con forma\n"
    "de estrella que\n"
    "adora Milcery.");

static const u8 sRibbonSweetDesc[] = _(
    "Caramelo con forma\n"
    "de lazo que adora\n"
    "Milcery.");

static const u8 sEverstoneDesc[] = _(
    "El Pokémon que lleva\n"
    "esta piedra mágica\n"
    "no evoluciona.");

static const u8 sBlackAuguriteDesc[] = _(
    "Piedra negra que\n"
    "hace evolucionar a\n"
    "algunos Pokémon.");;

static const u8 sLinkingCordDesc[] = _(
    "Hilo misterioso que\n"
    "hace evolucionar a\n"
    "algunos Pokémon.");

static const u8 sPeatBlockDesc[] = _(
    "Un bloque que hace\n"
    "evolucionar a un\n"
    "Pokémon.");

// Nectars
static const u8 sRedNectarDesc[] = _(
    "Néctar de Ula-Ula.\n"
    "Cambia la forma de\n"
    "Oricorio.");

static const u8 sYellowNectarDesc[] = _(
    "Néctar de Melemele.\n"
    "Cambia la forma de\n"
    "Oricorio.");

static const u8 sPinkNectarDesc[] = _(
    "Néctar de Akala.\n"
    "Cambia la forma de\n"
    "Oricorio.");

static const u8 sPurpleNectarDesc[] = _(
    "Néctar de Poni.\n"
    "Cambia la forma de\n"
    "Oricorio.");

// Plates
static const u8 sFlamePlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Fuego.");

static const u8 sSplashPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Agua.");

static const u8 sZapPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Eléctrico.");

static const u8 sMeadowPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Planta.");

static const u8 sIciclePlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Hielo.");

static const u8 sFistPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Lucha.");

static const u8 sToxicPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Veneno.");

static const u8 sEarthPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Tierra.");

static const u8 sSkyPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Volador.");

static const u8 sMindPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Psíquico.");

static const u8 sInsectPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Bicho.");

static const u8 sStonePlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Roca.");

static const u8 sSpookyPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Fantasma.");

static const u8 sDracoPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Dragón.");

static const u8 sDreadPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Siniestro.");

static const u8 sIronPlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Acero.");

static const u8 sPixiePlateDesc[] = _(
    "Tabla de piedra que\n"
    "potencia el tipo\n"
    "Hada.");

// Drives
static const u8 sDouseDriveDesc[] = _(
    "Tecno Shock de\n"
    "Genesect pasa a\n"
    "tipo Agua.");

static const u8 sShockDriveDesc[] = _(
    "Tecno Shock de\n"
    "Genesect pasa a\n"
    "tipo Eléctrico.");

static const u8 sBurnDriveDesc[] = _(
    "Tecno Shock de\n"
    "Genesect pasa a\n"
    "tipo Fuego.");

static const u8 sChillDriveDesc[] = _(
    "Tecno Shock de\n"
    "Genesect pasa a\n"
    "tipo Hielo.");

// Memories
static const u8 sFireMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Fuego. Cambia\n"
    "el tipo de Silvally.");

static const u8 sWaterMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Agua. Cambia el\n"
    "tipo de Silvally.");

static const u8 sElectricMemoryDesc[] = _(
    "Disco de tipo\n"
    "Eléctrico. Cambia el\n"
    "tipo de Silvally.");

static const u8 sGrassMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Planta. Cambia\n"
    "el tipo de Silvally.");

static const u8 sIceMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Hielo. Cambia el\n"
    "tipo de Silvally.");

static const u8 sFightingMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Lucha. Cambia\n"
    "el tipo de Silvally.");

static const u8 sPoisonMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Veneno. Cambia\n"
    "el tipo de Silvally.");

static const u8 sGroundMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Tierra. Cambia\n"
    "el tipo de Silvally.");

static const u8 sFlyingMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Volador. Cambia\n"
    "el tipo de Silvally.");

static const u8 sPsychicMemoryDesc[] = _(
    "Disco de tipo\n"
    "Psíquico. Cambia el\n"
    "tipo de Silvally.");

static const u8 sBugMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Bicho. Cambia el\n"
    "tipo de Silvally.");

static const u8 sRockMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Roca. Cambia el\n"
    "tipo de Silvally.");

static const u8 sGhostMemoryDesc[] = _(
    "Disco de tipo\n"
    "Fantasma. Cambia el\n"
    "tipo de Silvally.");

static const u8 sDragonMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Dragón. Cambia\n"
    "el tipo de Silvally.");

static const u8 sDarkMemoryDesc[] = _(
    "Disco de tipo\n"
    "Siniestro. Cambia el\n"
    "tipo de Silvally.");

static const u8 sSteelMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Acero. Cambia\n"
    "el tipo de Silvally.");

static const u8 sFairyMemoryDesc[] = _(
    "Disco de datos de\n"
    "tipo Hada. Cambia el\n"
    "tipo de Silvally.");

static const u8 sRustedSwordDesc[] = _(
    "Espada legendaria\n"
    "de un héroe, ahora\n"
    "oxidada.");

static const u8 sRustedShieldDesc[] = _(
    "Escudo legendario\n"
    "de un héroe, ahora\n"
    "oxidado.");

// Colored Orbs
static const u8 sRedOrbDesc[] = _(
    "Piedra carmesí\n"
    "ligada a las\n"
    "leyendas de Hoenn.");

static const u8 sBlueOrbDesc[] = _(
    "Piedra añil ligada a\n"
    "las leyendas de\n"
    "Hoenn.");

// Mega Stones
static const u8 sVenusauriteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Venusaur.");

static const u8 sCharizarditeDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Charizard.");

static const u8 sBlastoisiniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Blastoise.");

static const u8 sBeedrilliteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Beedrill.");

static const u8 sPidgeotiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Pidgeot.");

static const u8 sAlakaziteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Alakazam.");

static const u8 sSlowbroniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Slowbro.");

static const u8 sGengariteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Gengar.");

static const u8 sKangaskhaniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Kangaskhan.");

static const u8 sPinsiriteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Pinsir.");

static const u8 sGyaradositeDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Gyarados.");

static const u8 sAerodactyliteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Aerodactyl.");

static const u8 sMewtwoniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Mewtwo.");

static const u8 sRaichuniteDesc[] = _(
    "Permite a Raichu\n"
    "megaevolucionar en\n"
    "combate.");

static const u8 sAmpharositeDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Ampharos.");

static const u8 sSteelixiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Steelix.");

static const u8 sScizoriteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Scizor.");

static const u8 sHeracroniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Heracross.");

static const u8 sHoundoominiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Houndoom.");

static const u8 sTyranitariteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Tyranitar.");

static const u8 sSceptiliteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Sceptile.");

static const u8 sBlazikeniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Blaziken.");

static const u8 sSwampertiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Swampert.");

static const u8 sGardevoiriteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Gardevoir.");

static const u8 sSableniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Sableye.");

static const u8 sMawiliteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Mawile.");

static const u8 sAggroniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Aggron.");

static const u8 sMedichamiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Medicham.");

static const u8 sManectiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Manectric.");

static const u8 sSharpedoniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Sharpedo.");

static const u8 sCameruptiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Camerupt.");

static const u8 sAltarianiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Altaria.");

static const u8 sBanettiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Banette.");

static const u8 sAbsoliteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Absol.");

static const u8 sGlalititeDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Glalie.");

static const u8 sSalamenciteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Salamence.");

static const u8 sMetagrossiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Metagross.");

static const u8 sLatiasiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Latias.");

static const u8 sLatiositeDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Latios.");

static const u8 sLopunniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Lopunny.");

static const u8 sGarchompiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Garchomp.");

static const u8 sLucarioniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Lucario.");

static const u8 sAbomasiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Abomasnow.");

static const u8 sGalladiteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Gallade.");

static const u8 sAudiniteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Audino.");

static const u8 sDianciteDesc[] = _(
    "Megapiedra. Permite\n"
    "megaevolucionar a\n"
    "Diancie.");

// Gems
static const u8 sNormalGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Normal.");

static const u8 sFireGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Fuego.");

static const u8 sWaterGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Agua.");

static const u8 sElectricGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Eléctrico.");

static const u8 sGrassGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Planta.");

static const u8 sIceGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Hielo.");

static const u8 sFightingGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Lucha.");

static const u8 sPoisonGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Veneno.");

static const u8 sGroundGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Tierra.");

static const u8 sFlyingGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Volador.");

static const u8 sPsychicGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Psíquico.");

static const u8 sBugGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Bicho.");

static const u8 sRockGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Roca.");

static const u8 sGhostGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Fantasma.");

static const u8 sDragonGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Dragón.");

static const u8 sDarkGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Siniestro.");

static const u8 sSteelGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Acero.");

static const u8 sFairyGemDesc[] = _(
    "Joya de un solo uso\n"
    "que potencia el tipo\n"
    "Hada.");

// Z-Crystals
static const u8 sNormaliumZDesc[] = _(
    "Convierte los\n"
    "movimientos Normal\n"
    "en movimientos Z.");

static const u8 sFiriumZDesc[] = _(
    "Convierte los\n"
    "movimientos Fuego\n"
    "en movimientos Z.");

static const u8 sWateriumZDesc[] = _(
    "Convierte los\n"
    "movimientos Agua en\n"
    "movimientos Z.");

static const u8 sElectriumZDesc[] = _(
    "Los movimientos\n"
    "Eléctrico pasan a\n"
    "ser movimientos Z.");

static const u8 sGrassiumZDesc[] = _(
    "Convierte los\n"
    "movimientos Planta\n"
    "en movimientos Z.");

static const u8 sIciumZDesc[] = _(
    "Convierte los\n"
    "movimientos Hielo en\n"
    "movimientos Z.");

static const u8 sFightiniumZDesc[] = _(
    "Convierte los\n"
    "movimientos Lucha\n"
    "en movimientos Z.");

static const u8 sPoisoniumZDesc[] = _(
    "Convierte los\n"
    "movimientos Veneno\n"
    "en movimientos Z.");

static const u8 sGroundiumZDesc[] = _(
    "Convierte los\n"
    "movimientos Tierra\n"
    "en movimientos Z.");

static const u8 sFlyiniumZDesc[] = _(
    "Convierte los\n"
    "movimientos Volador\n"
    "en movimientos Z.");

static const u8 sPsychiumZDesc[] = _(
    "Los movimientos\n"
    "Psíquico pasan a\n"
    "ser movimientos Z.");

static const u8 sBuginiumZDesc[] = _(
    "Convierte los\n"
    "movimientos Bicho\n"
    "en movimientos Z.");

static const u8 sRockiumZDesc[] = _(
    "Convierte los\n"
    "movimientos Roca en\n"
    "movimientos Z.");

static const u8 sGhostiumZDesc[] = _(
    "Los movimientos\n"
    "Fantasma pasan a\n"
    "ser movimientos Z.");

static const u8 sDragoniumZDesc[] = _(
    "Convierte los\n"
    "movimientos Dragón\n"
    "en movimientos Z.");

static const u8 sDarkiniumZDesc[] = _(
    "Los movimientos\n"
    "Siniestro pasan a\n"
    "ser movimientos Z.");

static const u8 sSteeliumZDesc[] = _(
    "Convierte los\n"
    "movimientos Acero\n"
    "en movimientos Z.");

static const u8 sFairiumZDesc[] = _(
    "Convierte los\n"
    "movimientos Hada en\n"
    "movimientos Z.");

static const u8 sPikaniumZDesc[] = _(
    "Convierte Placaje\n"
    "Eléc. de Pikachu en\n"
    "movimiento Z.");

static const u8 sEeviumZDesc[] = _(
    "Convierte Última\n"
    "Baza de Eevee en\n"
    "movimiento Z.");

static const u8 sSnorliumZDesc[] = _(
    "Gigaimpacto de\n"
    "Snorlax pasa a ser\n"
    "movimiento Z.");

static const u8 sMewniumZDesc[] = _(
    "Convierte Psíquico\n"
    "de Mew en\n"
    "movimiento Z.");

static const u8 sDecidiumZDesc[] = _(
    "Convierte Puntada\n"
    "Somb. de Decidueye\n"
    "en movimiento Z.");

static const u8 sInciniumZDesc[] = _(
    "Lariat Oscuro de\n"
    "Incineroar pasa a\n"
    "ser mov. Z.");

static const u8 sPrimariumZDesc[] = _(
    "Convierte Aria\n"
    "Burbuja de Primarina\n"
    "en movimiento Z.");

static const u8 sLycaniumZDesc[] = _(
    "Convierte Roca\n"
    "Afilada de Lycanroc\n"
    "en movimiento Z.");

static const u8 sMimikiumZDesc[] = _(
    "Carantoña de\n"
    "Mimikyu pasa a ser\n"
    "movimiento Z.");

static const u8 sKommoniumZDesc[] = _(
    "Convierte Fragor\n"
    "Escamas de Kommo-o\n"
    "en movimiento Z.");

static const u8 sTapuniumZDesc[] = _(
    "Convierte Furia\n"
    "Natural de los tapus\n"
    "en movimiento Z.");

static const u8 sSolganiumZDesc[] = _(
    "Meteoimpacto de\n"
    "Solgaleo pasa a ser\n"
    "movimiento Z.");

static const u8 sLunaliumZDesc[] = _(
    "Convierte Rayo\n"
    "Umbrío de Lunala en\n"
    "movimiento Z.");

static const u8 sMarshadiumZDesc[] = _(
    "Robasombra de\n"
    "Marshadow pasa a\n"
    "ser movimiento Z.");

static const u8 sAloraichiumZDesc[] = _(
    "Convierte Rayo de\n"
    "Raichu de Alola en\n"
    "movimiento Z.");

static const u8 sPikashuniumZDesc[] = _(
    "Convierte Rayo de\n"
    "Pikachu con gorra\n"
    "en movimiento Z.");

static const u8 sUltranecroziumZDesc[] = _(
    "Cristal que da una\n"
    "nueva forma a\n"
    "Necrozma fusionado.");

// Species-specific Held Items
static const u8 sLightBallDesc[] = _(
    "Esfera que sube el\n"
    "Ataque y At. Esp. de\n"
    "Pikachu.");

static const u8 sLeekDesc[] = _(
    "Sube el índice de\n"
    "crítico de\n"
    "Farfetch'd.");

static const u8 sThickClubDesc[] = _(
    "Hueso que potencia\n"
    "a Cubone y Marowak.");

static const u8 sLuckyPunchDesc[] = _(
    "Guantes que suben\n"
    "mucho el crítico de\n"
    "Chansey.");

static const u8 sMetalPowderDesc[] = _(
    "Polvo fino que\n"
    "aumenta la Defensa\n"
    "de Ditto.");

static const u8 sQuickPowderDesc[] = _(
    "Polvo fino que\n"
    "aumenta la\n"
    "Velocidad de Ditto.");

static const u8 sDeepSeaScaleDesc[] = _(
    "Brillo rosado. Sube\n"
    "la Def. Esp. de\n"
    "Clamperl.");

static const u8 sDeepSeaToothDesc[] = _(
    "Brillo plateado.\n"
    "Sube el At. Esp. de\n"
    "Clamperl.");

static const u8 sSoulDewDesc[] = _(
#if B_SOUL_DEW_BOOST >= GEN_7
    "Powers up Latios' &\n"
    "Latias' Psychic and\n"
    "Dragon-type moves.");
#else
    "Hold item: raises\n"
    "Sp. Atk & Sp. Def of\n"
    "Latios & Latias.");
#endif

static const u8 sAdamantOrbDesc[] = _(
    "Esfera que potencia\n"
    "Acero y Dragón de\n"
    "Dialga.");

static const u8 sLustrousOrbDesc[] = _(
    "Esfera que potencia\n"
    "Dragón y Agua de\n"
    "Palkia.");

static const u8 sGriseousOrbDesc[] = _(
    "Esfera que potencia\n"
    "Dragón y Fantasma\n"
    "de Giratina.");

// Incenses
static const u8 sSeaIncenseDesc[] = _(
    "Incienso de curioso\n"
    "aroma. Potencia el\n"
    "tipo Agua.");

static const u8 sLaxIncenseDesc[] = _(
    "Su peculiar aroma\n"
    "reduce la Precisión\n"
    "rival.");

static const u8 sOddIncenseDesc[] = _(
    "Incienso exótico\n"
    "que potencia el tipo\n"
    "Psíquico.");

static const u8 sRockIncenseDesc[] = _(
    "Incienso exótico\n"
    "que potencia el tipo\n"
    "Roca.");

static const u8 sFullIncenseDesc[] = _(
    "Incienso que hace\n"
    "que su portador\n"
    "vaya más lento.");

static const u8 sWaveIncenseDesc[] = _(
    "Incienso de curioso\n"
    "aroma. Potencia el\n"
    "tipo Agua.");

static const u8 sRoseIncenseDesc[] = _(
    "Incienso exótico\n"
    "que potencia el tipo\n"
    "Planta.");

static const u8 sLuckIncenseDesc[] = _(
    "Duplica las\n"
    "ganancias si su\n"
    "portador combate.");

static const u8 sPureIncenseDesc[] = _(
    "Reduce los\n"
    "encuentros con\n"
    "Pokémon salvajes.");

// Contest Scarves
static const u8 sRedScarfDesc[] = _(
    "Aumenta el carisma\n"
    "en los concursos.");

static const u8 sBlueScarfDesc[] = _(
    "Aumenta la belleza\n"
    "en los concursos.");

static const u8 sPinkScarfDesc[] = _(
    "Aumenta la dulzura\n"
    "en los concursos.");

static const u8 sGreenScarfDesc[] = _(
    "Aumenta el ingenio\n"
    "en los concursos.");

static const u8 sYellowScarfDesc[] = _(
    "Aumenta la dureza\n"
    "en los concursos.");

// EV Gain Modifiers
static const u8 sMachoBraceDesc[] = _(
    "Brazal pesado: más\n"
    "crecimiento, menos\n"
    "Velocidad.");

static const u8 sPowerWeightDesc[] = _(
    "Mejora los PS de\n"
    "base; reduce la\n"
    "Velocidad.");

static const u8 sPowerBracerDesc[] = _(
    "Mejora el Ataque de\n"
    "base; reduce la\n"
    "Velocidad.");

static const u8 sPowerBeltDesc[] = _(
    "Mejora la Defensa\n"
    "de base; reduce la\n"
    "Velocidad.");

static const u8 sPowerLensDesc[] = _(
    "Mejora el At. Esp. de\n"
    "base; reduce la\n"
    "Velocidad.");

static const u8 sPowerBandDesc[] = _(
    "Mejora la Def. Esp.\n"
    "de base; reduce la\n"
    "Velocidad.");

static const u8 sPowerAnkletDesc[] = _(
    "Mejora la Velocidad\n"
    "de base, pero la\n"
    "reduce en combate.");

// Type-boosting Held Items
static const u8 sSilkScarfDesc[] = _(
    "Pañuelo de seda que\n"
    "potencia el tipo\n"
    "Normal.");

static const u8 sCharcoalDesc[] = _(
    "Carbón que potencia\n"
    "el tipo Fuego.");

static const u8 sMysticWaterDesc[] = _(
    "Gema como una gota\n"
    "que potencia el tipo\n"
    "Agua.");

static const u8 sMagnetDesc[] = _(
    "Imán potente que\n"
    "potencia el tipo\n"
    "Eléctrico.");

static const u8 sMiracleSeedDesc[] = _(
    "Semilla llena de vida\n"
    "que potencia el tipo\n"
    "Planta.");

static const u8 sNeverMeltIceDesc[] = _(
    "Hielo eterno que\n"
    "potencia el tipo\n"
    "Hielo.");

static const u8 sBlackBeltDesc[] = _(
    "Cinturón que\n"
    "potencia el tipo\n"
    "Lucha.");

static const u8 sPoisonBarbDesc[] = _(
    "Púa venenosa que\n"
    "potencia el tipo\n"
    "Veneno.");

static const u8 sSoftSandDesc[] = _(
    "Arena suave que\n"
    "potencia el tipo\n"
    "Tierra.");

static const u8 sSharpBeakDesc[] = _(
    "Pico afilado que\n"
    "potencia el tipo\n"
    "Volador.");

static const u8 sTwistedSpoonDesc[] = _(
    "Cuchara doblada que\n"
    "potencia el tipo\n"
    "Psíquico.");

static const u8 sSilverPowderDesc[] = _(
    "Polvo plateado que\n"
    "potencia el tipo\n"
    "Bicho.");

static const u8 sHardStoneDesc[] = _(
    "Piedra muy dura que\n"
    "potencia el tipo\n"
    "Roca.");

static const u8 sSpellTagDesc[] = _(
    "Etiqueta siniestra\n"
    "que potencia el tipo\n"
    "Fantasma.");

static const u8 sDragonFangDesc[] = _(
    "Colmillo muy duro\n"
    "que potencia el tipo\n"
    "Dragón.");

static const u8 sBlackGlassesDesc[] = _(
    "Gafas oscuras que\n"
    "potencian el tipo\n"
    "Siniestro.");

static const u8 sMetalCoatDesc[] = _(
    "Película metálica\n"
    "que potencia el tipo\n"
    "Acero.");

// Choice Items
static const u8 sChoiceBandDesc[] = _(
    "Más ataque físico,\n"
    "pero un solo\n"
    "movimiento.");

static const u8 sChoiceSpecsDesc[] = _(
    "Más ataque\n"
    "especial, pero un\n"
    "solo movimiento.");

static const u8 sChoiceScarfDesc[] = _(
    "Más Velocidad, pero\n"
    "un solo movimiento.");

// Status Orbs
static const u8 sFlameOrbDesc[] = _(
    "Esfera extraña que\n"
    "quema a su portador.");

static const u8 sToxicOrbDesc[] = _(
    "Esfera extraña que\n"
    "envenena\n"
    "gravemente.");

// Weather Rocks
static const u8 sDampRockDesc[] = _(
    "Prolonga la Danza\n"
    "Lluvia del portador.");

static const u8 sHeatRockDesc[] = _(
    "Prolonga el Día\n"
    "Soleado del\n"
    "portador.");

static const u8 sSmoothRockDesc[] = _(
    "Prolonga la\n"
    "Tormenta de Arena\n"
    "del portador.");

static const u8 sIcyRockDesc[] = _(
    "Prolonga el Granizo\n"
    "del portador.");

// Terrain Seeds
static const u8 sElectricSeedDesc[] = _(
    "Sube la Defensa con\n"
    "campo eléctrico.");

static const u8 sPsychicSeedDesc[] = _(
    "Sube la Def. Esp. con\n"
    "campo psíquico.");

static const u8 sMistySeedDesc[] = _(
    "Sube la Def. Esp. con\n"
    "campo de niebla.");

static const u8 sGrassySeedDesc[] = _(
    "Sube la Defensa con\n"
    "campo de hierba.");

// Type-activated Stat Modifiers
static const u8 sAbsorbBulbDesc[] = _(
    "Sube el At. Esp. al\n"
    "recibir un ataque de\n"
    "Agua.");

static const u8 sCellBatteryDesc[] = _(
    "Batería: sube el\n"
    "Ataque si recibe\n"
    "Eléctrico.");

static const u8 sLuminousMossDesc[] = _(
    "Sube la Def. Esp. al\n"
    "recibir un ataque de\n"
    "Agua.");

static const u8 sSnowballDesc[] = _(
    "Sube el Ataque al\n"
    "recibir un ataque de\n"
    "Hielo.");

// Misc. Held Items
static const u8 sBrightPowderDesc[] = _(
    "Destello que baja la\n"
    "Precisión del\n"
    "enemigo.");

static const u8 sWhiteHerbDesc[] = _(
    "Restaura las\n"
    "características\n"
    "reducidas. Un uso.");

static const u8 sExpShareDesc[] = _(
#if I_EXP_SHARE_ITEM >= GEN_6
    "This device gives\n"
    "exp. to other\n"
    "party members.");
#else
    "A hold item that\n"
    "gets Exp. points\n"
    "from battles.");
#endif

static const u8 sQuickClawDesc[] = _(
    "Garra ligera que a\n"
    "veces permite\n"
    "atacar primero.");

static const u8 sSootheBellDesc[] = _(
    "Cascabel de tañido\n"
    "calmante que da más\n"
    "amistad.");

#if B_MENTAL_HERB >= GEN_5
static const u8 sMentalHerbDesc[] = _(
    "Libera al Pokémon de\n"
    "los movimientos que\n"
    "atrapan.");
#else
static const u8 sMentalHerbDesc[] = _(
    "Libera de los\n"
    "movimientos que\n"
    "atan. Un solo uso.");
#endif

static const u8 sKingsRockDesc[] = _(
    "Puede amedrentar al\n"
    "Pokémon al que dañe.");

static const u8 sAmuletCoinDesc[] = _(
    "Duplica las\n"
    "ganancias si su\n"
    "portador combate.");

static const u8 sCleanseTagDesc[] = _(
    "Reduce los\n"
    "encuentros con\n"
    "Pokémon salvajes.");

static const u8 sSmokeBallDesc[] = _(
    "Permite huir siempre\n"
    "de Pokémon\n"
    "salvajes.");

static const u8 sFocusBandDesc[] = _(
    "Puede resistir un\n"
    "K.O. y quedarse con\n"
    "1 PS.");

static const u8 sLuckyEggDesc[] = _(
    "Huevo que da Puntos\n"
    "de Experiencia\n"
    "extra.");

static const u8 sScopeLensDesc[] = _(
    "Lente que aumenta\n"
    "la probabilidad de\n"
    "crítico.");

static const u8 sLeftoversDesc[] = _(
    "Restaura PS poco a\n"
    "poco durante el\n"
    "combate.");

static const u8 sShellBellDesc[] = _(
    "Recupera algunos PS\n"
    "cada vez que inflige\n"
    "daño.");

static const u8 sWideLensDesc[] = _(
    "Aumenta un poco la\n"
    "precisión de los\n"
    "movimientos.");

static const u8 sMuscleBandDesc[] = _(
    "Cinta que potencia\n"
    "un poco los ataques\n"
    "físicos.");

static const u8 sWiseGlassesDesc[] = _(
    "Potencian un poco\n"
    "los ataques\n"
    "especiales.");

static const u8 sExpertBeltDesc[] = _(
    "Potencia un poco\n"
    "los movimientos\n"
    "supereficaces.");

static const u8 sLightClayDesc[] = _(
    "Prolonga barreras\n"
    "como Reflejo y\n"
    "Pantalla de Luz.");

static const u8 sLifeOrbDesc[] = _(
    "Potencia los\n"
    "ataques, pero\n"
    "consume PS.");

static const u8 sPowerHerbDesc[] = _(
    "Permite usar al\n"
    "instante un ataque\n"
    "que carga.");

static const u8 sFocusSashDesc[] = _(
    "Con PS al máximo,\n"
    "resiste un K.O. con 1\n"
    "PS.");

static const u8 sZoomLensDesc[] = _(
    "Si actúa después\n"
    "del rival, sube la\n"
    "Precisión.");

static const u8 sMetronomeDesc[] = _(
    "Potencia un\n"
    "movimiento usado\n"
    "seguido.");

static const u8 sIronBallDesc[] = _(
    "Reduce la Velocidad;\n"
    "Tierra alcanza a\n"
    "voladores.");

static const u8 sLaggingTailDesc[] = _(
    "Cola muy pesada. Su\n"
    "portador se mueve\n"
    "más lento.");

static const u8 sDestinyKnotDesc[] = _(
    "Hilo rojo que\n"
    "transmite el\n"
    "enamoramiento.");

static const u8 sBlackSludgeDesc[] = _(
    "Cura a los tipo\n"
    "Veneno; daña a los\n"
    "demás.");

static const u8 sGripClawDesc[] = _(
    "Prolonga los\n"
    "ataques como\n"
    "Atadura.");

static const u8 sStickyBarbDesc[] = _(
    "Daña al portador y\n"
    "puede adherirse al\n"
    "rival.");

static const u8 sShedShellDesc[] = _(
    "Concha que permite\n"
    "cambiarse siempre.");

static const u8 sBigRootDesc[] = _(
    "Recupera más PS con\n"
    "los ataques que\n"
    "drenan.");

static const u8 sRazorClawDesc[] = _(
    "Aumenta la\n"
    "probabilidad de\n"
    "golpe crítico.");

static const u8 sRazorFangDesc[] = _(
    "Puede amedrentar al\n"
    "Pokémon al que dañe.");

static const u8 sEvioliteDesc[] = _(
    "Sube Defensa y\n"
    "Def. Esp. si aún\n"
    "puede evolucionar.");

static const u8 sFloatStoneDesc[] = _(
    "Piedra muy ligera\n"
    "que reduce el peso.");

static const u8 sRockyHelmetDesc[] = _(
    "Daña a quien ataque\n"
    "al portador por\n"
    "contacto.");

static const u8 sAirBalloonDesc[] = _(
    "Hace flotar al\n"
    "portador. Estalla si\n"
    "le golpean.");

static const u8 sRedCardDesc[] = _(
    "Expulsa al rival que\n"
    "le cause daño.");

static const u8 sRingTargetDesc[] = _(
    "Vulnerable a\n"
    "movimientos que no\n"
    "le afectarían.");

static const u8 sBindingBandDesc[] = _(
    "Banda que potencia\n"
    "los movimientos que\n"
    "estrujan al rival.");

static const u8 sEjectButtonDesc[] = _(
    "Si le atacan, se\n"
    "retira y sale otro\n"
    "Pokémon.");

static const u8 sWeaknessPolicyDesc[] = _(
    "Si recibe un golpe\n"
    "supereficaz,\n"
    "++Ataque y At. Esp.");

static const u8 sAssaultVestDesc[] = _(
    "Sube la Def. Esp.,\n"
    "pero impide movs. de\n"
    "estado.");

static const u8 sSafetyGogglesDesc[] = _(
    "Gafa que protege\n"
    "del clima y de los\n"
    "polvos.");

static const u8 sAdrenalineOrbDesc[] = _(
    "Sube la Velocidad si\n"
    "le intimidan.");

static const u8 sTerrainExtenderDesc[] = _(
    "Prolonga los campos\n"
    "que crea el\n"
    "portador.");

static const u8 sProtectivePadsDesc[] = _(
    "Protege de los\n"
    "efectos del\n"
    "contacto directo.");

static const u8 sThroatSprayDesc[] = _(
    "Sube el At. Esp. al\n"
    "usar un movimiento\n"
    "de sonido.");

static const u8 sEjectPackDesc[] = _(
    "Si le bajan\n"
    "características, se\n"
    "retira.");

static const u8 sHeavyDutyBootsDesc[] = _(
    "Anula las trampas\n"
    "colocadas en el\n"
    "campo.");

static const u8 sBlunderPolicyDesc[] = _(
    "Sube mucho la\n"
    "Velocidad si falla\n"
    "por precisión.");

static const u8 sRoomServiceDesc[] = _(
    "Reduce la Velocidad\n"
    "con Espacio Raro.");

static const u8 sUtilityUmbrellaDesc[] = _(
    "Invulnerable a los\n"
    "efectos de la lluvia\n"
    "y el sol.");

// Berries
static const u8 sCheriBerryDesc[] = _(
    "Se lleva o usa para\n"
    "curar la parálisis.");

static const u8 sChestoBerryDesc[] = _(
    "Se lleva o usa para\n"
    "despertar del\n"
    "sueño.");

static const u8 sPechaBerryDesc[] = _(
    "Se lleva o usa para\n"
    "curar el\n"
    "envenenamiento.");

static const u8 sRawstBerryDesc[] = _(
    "Se lleva o usa para\n"
    "curar las\n"
    "quemaduras.");

static const u8 sAspearBerryDesc[] = _(
    "Los Pokémon pueden\n"
    "llevarla o usarla\n"
    "para descongelarse.");

static const u8 sLeppaBerryDesc[] = _(
    "Se lleva o usa para\n"
    "restaurar 10 PP.");

static const u8 sOranBerryDesc[] = _(
    "Se lleva o usa para\n"
    "restaurar 10 PS.");

static const u8 sPersimBerryDesc[] = _(
    "Se lleva o usa para\n"
    "librarse de la\n"
    "confusión.");

static const u8 sLumBerryDesc[] = _(
    "Se lleva o usa para\n"
    "curar problemas de\n"
    "estado.");

static const u8 sSitrusBerryDesc[] = _(
#if I_SITRUS_BERRY_HEAL >= GEN_4
    "A hold item that\n"
    "restores the user's\n"
    "HP a little.");
#else
    "A hold item that\n"
    "restores 30 HP in\n"
    "battle.");
#endif

static const u8 sFigyBerryDesc[] = _(
    "Restaura PS. Puede\n"
    "confundir si no le\n"
    "gusta.");

static const u8 sWikiBerryDesc[] = _(
    "Restaura PS. Puede\n"
    "confundir si no le\n"
    "gusta.");

static const u8 sMagoBerryDesc[] = _(
    "Restaura PS. Puede\n"
    "confundir si no le\n"
    "gusta.");

static const u8 sAguavBerryDesc[] = _(
    "Restaura PS. Puede\n"
    "confundir si no le\n"
    "gusta.");

static const u8 sIapapaBerryDesc[] = _(
    "Restaura PS. Puede\n"
    "confundir si no le\n"
    "gusta.");

static const u8 sRazzBerryDesc[] = _(
    "Para Pokécubos de\n"
    "carisma. Roja y\n"
    "picante.");

static const u8 sBlukBerryDesc[] = _(
    "Para Pokécubos de\n"
    "belleza. Azulada y\n"
    "seca.");

static const u8 sNanabBerryDesc[] = _(
    "Para Pokécubos de\n"
    "dulzura. Rosa y\n"
    "dulce.");

static const u8 sWepearBerryDesc[] = _(
    "Para Pokécubos de\n"
    "ingenio. Verde y\n"
    "amarga.");

static const u8 sPinapBerryDesc[] = _(
    "Para Pokécubos de\n"
    "dureza. Amarilla y\n"
    "ácida.");

static const u8 sPomegBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce sus PS\n"
    "de base.");

static const u8 sKelpsyBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce su\n"
    "Ataque de base.");

static const u8 sQualotBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce su\n"
    "Defensa de base.");

static const u8 sHondewBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce su\n"
    "At. Esp. de base.");

static const u8 sGrepaBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce su\n"
    "Def. Esp. de base.");

static const u8 sTamatoBerryDesc[] = _(
    "Gana su amistad,\n"
    "pero reduce su\n"
    "Velocidad de base.");

static const u8 sCornnBerryDesc[] = _(
    "Para Pokécubos de\n"
    "belleza. Muy rara.");

static const u8 sMagostBerryDesc[] = _(
    "Para Pokécubos de\n"
    "dulzura. Muy rara.");

static const u8 sRabutaBerryDesc[] = _(
    "Para Pokécubos de\n"
    "ingenio. Muy rara.");

static const u8 sNomelBerryDesc[] = _(
    "Para Pokécubos de\n"
    "dureza. Muy rara.");

static const u8 sSpelonBerryDesc[] = _(
    "Para Pokécubos de\n"
    "dulzura. Muy rara.");

static const u8 sPamtreBerryDesc[] = _(
    "Para Pokécubos de\n"
    "belleza. Muy rara.");

static const u8 sWatmelBerryDesc[] = _(
    "Para Pokécubos de\n"
    "ingenio. Muy rara.");

static const u8 sDurinBerryDesc[] = _(
    "Para Pokécubos de\n"
    "ingenio. Muy rara.");

static const u8 sBelueBerryDesc[] = _(
    "Para Pokécubos de\n"
    "belleza. Muy rara.");

static const u8 sChilanBerryDesc[] = _(
    "Debilita un ataque\n"
    "de tipo Normal del\n"
    "enemigo.");

static const u8 sOccaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Fuego.");

static const u8 sPasshoBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Agua.");

static const u8 sWacanBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Eléctrico.");

static const u8 sRindoBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Planta.");

static const u8 sYacheBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Hielo.");

static const u8 sChopleBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Lucha.");

static const u8 sKebiaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Veneno.");

static const u8 sShucaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Tierra.");

static const u8 sCobaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Volador.");

static const u8 sPayapaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Psíquico.");

static const u8 sTangaBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Bicho.");

static const u8 sChartiBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Roca.");

static const u8 sKasibBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Fantasma.");

static const u8 sHabanBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Dragón.");

static const u8 sColburBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Siniestro.");

static const u8 sBabiriBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Acero.");

static const u8 sRoseliBerryDesc[] = _(
    "Debilita un ataque\n"
    "supereficaz de tipo\n"
    "Hada.");

static const u8 sLiechiBerryDesc[] = _(
    "Sube el Ataque en un\n"
    "momento de apuro.");

static const u8 sGanlonBerryDesc[] = _(
    "Sube la Defensa en\n"
    "un momento de\n"
    "apuro.");

static const u8 sSalacBerryDesc[] = _(
    "Sube la Velocidad en\n"
    "un momento de\n"
    "apuro.");

static const u8 sPetayaBerryDesc[] = _(
    "Sube el At. Esp. en\n"
    "un momento de\n"
    "apuro.");

static const u8 sApicotBerryDesc[] = _(
    "Sube la Def. Esp. en\n"
    "un momento de\n"
    "apuro.");

static const u8 sLansatBerryDesc[] = _(
    "Más probabilidad de\n"
    "crítico en un apuro.");

static const u8 sStarfBerryDesc[] = _(
    "Sube mucho una\n"
    "característica en\n"
    "un apuro.");

static const u8 sEnigmaBerryDesc[] = _(
    "Restaura PS al\n"
    "recibir un ataque\n"
    "supereficaz.");

static const u8 sMicleBerryDesc[] = _(
    "Sube la precisión de\n"
    "un movimiento en un\n"
    "apuro.");

static const u8 sCustapBerryDesc[] = _(
    "En un apuro, permite\n"
    "actuar primero una\n"
    "vez.");

static const u8 sJabocaBerryDesc[] = _(
    "Daña también a\n"
    "quien lance un\n"
    "ataque físico.");

static const u8 sRowapBerryDesc[] = _(
    "Daña también a\n"
    "quien lance un\n"
    "ataque especial.");

static const u8 sKeeBerryDesc[] = _(
    "Sube la Defensa\n"
    "tras recibir un\n"
    "ataque físico.");

static const u8 sMarangaBerryDesc[] = _(
    "Sube la Def. Esp.\n"
    "tras recibir un\n"
    "ataque especial.");

static const u8 sEnigmaBerryEReaderDesc[] = _(
    "Ingrediente de\n"
    "{POKEBLOCK}. Plántala y\n"
    "verás qué sale.");

// TMs/HMs
static const u8 sTM01Desc[] = _(
    "Potente, pero falla\n"
    "si el rival golpea\n"
    "antes.");

static const u8 sTM02Desc[] = _(
    "Engancha y rasga al\n"
    "rival con garras\n"
    "largas y afiladas.");

static const u8 sTM03Desc[] = _(
    "Genera ultrasonidos\n"
    "que pueden\n"
    "confundir.");

static const u8 sTM04Desc[] = _(
    "Se concentra y sube\n"
    "el At. Esp. y la\n"
    "Def. Esp.");

static const u8 sTM05Desc[] = _(
    "Un rugido feroz que\n"
    "ahuyenta al rival y\n"
    "acaba el combate.");

static const u8 sTM06Desc[] = _(
    "Envenena al rival\n"
    "con una toxina cada\n"
    "vez peor.");

static const u8 sTM07Desc[] = _(
    "Provoca granizo que\n"
    "daña a todo lo que\n"
    "no sea Hielo.");

static const u8 sTM08Desc[] = _(
    "Fortalece el cuerpo\n"
    "y sube el Ataque y\n"
    "la Defensa.");

static const u8 sTM09Desc[] = _(
    "Dispara de 2 a 5\n"
    "semillas seguidas al\n"
    "rival.");

static const u8 sTM10Desc[] = _(
    "Su potencia varía\n"
    "según el Pokémon.");

static const u8 sTM11Desc[] = _(
    "Potencia los\n"
    "ataques de Fuego\n"
    "durante 5 turnos.");

static const u8 sTM12Desc[] = _(
    "Enfurece al rival\n"
    "para que solo use\n"
    "ataques.");

static const u8 sTM13Desc[] = _(
    "Dispara un rayo\n"
    "helado que puede\n"
    "congelar.");

static const u8 sTM14Desc[] = _(
    "Ventisca brutal que\n"
    "puede congelar al\n"
    "rival.");

static const u8 sTM15Desc[] = _(
    "Muy potente, pero\n"
    "debe recargar el\n"
    "turno siguiente.");

static const u8 sTM16Desc[] = _(
    "Crea un muro de luz\n"
    "que reduce el daño\n"
    "especial.");

static const u8 sTM17Desc[] = _(
    "Anula todo el daño,\n"
    "pero puede fallar si\n"
    "se repite.");

static const u8 sTM18Desc[] = _(
    "Potencia los\n"
    "ataques de Agua\n"
    "durante 5 turnos.");

static const u8 sTM19Desc[] = _(
    "Recupera la mitad\n"
    "del daño que causa.");

static const u8 sTM20Desc[] = _(
    "Evita los problemas\n"
    "de estado con un\n"
    "poder místico.");

static const u8 sTM21Desc[] = _(
    "Cuanto menos te\n"
    "aprecie, más\n"
    "potente es.");

static const u8 sTM22Desc[] = _(
    "Absorbe luz el 1.er\n"
    "turno y ataca en el\n"
    "siguiente.");

static const u8 sTM23Desc[] = _(
    "Golpea con una cola\n"
    "dura. Puede bajar la\n"
    "Defensa.");

static const u8 sTM24Desc[] = _(
    "Potente ataque\n"
    "eléctrico que puede\n"
    "paralizar.");

static const u8 sTM25Desc[] = _(
    "Lanza un rayo al\n"
    "rival. Puede\n"
    "paralizarlo.");

static const u8 sTM26Desc[] = _(
    "Provoca un\n"
    "terremoto. No\n"
    "afecta a voladores.");

static const u8 sTM27Desc[] = _(
    "Cuanto más te\n"
    "aprecie, más\n"
    "potente es.");

static const u8 sTM28Desc[] = _(
    "Excava el 1.er turno\n"
    "y ataca en el\n"
    "siguiente.");

static const u8 sTM29Desc[] = _(
    "Potente ataque\n"
    "psíquico. Puede\n"
    "bajar la Def. Esp.");

static const u8 sTM30Desc[] = _(
    "Lanza una masa\n"
    "oscura. Puede bajar\n"
    "la Def. Esp.");

static const u8 sTM31Desc[] = _(
    "Rompe barreras como\n"
    "Pantalla de Luz y\n"
    "hace daño.");

static const u8 sTM32Desc[] = _(
    "Crea copias\n"
    "ilusorias para subir\n"
    "la evasión.");

static const u8 sTM33Desc[] = _(
    "Crea un muro de luz\n"
    "que reduce el daño\n"
    "físico.");

static const u8 sTM34Desc[] = _(
    "Una descarga\n"
    "eléctrica que nunca\n"
    "falla.");

static const u8 sTM35Desc[] = _(
    "Lanza un chorro de\n"
    "fuego que puede\n"
    "quemar.");

static const u8 sTM36Desc[] = _(
    "Lanza lodo al rival.\n"
    "Puede envenenarlo.");

static const u8 sTM37Desc[] = _(
    "Crea una tormenta\n"
    "de arena que dura\n"
    "varios turnos.");

static const u8 sTM38Desc[] = _(
    "Potente ataque de\n"
    "fuego que puede\n"
    "quemar.");

static const u8 sTM39Desc[] = _(
    "Frena al rival con\n"
    "rocas. Puede bajar\n"
    "su Velocidad.");

static const u8 sTM40Desc[] = _(
    "Ataque rapidísimo\n"
    "que no se puede\n"
    "esquivar.");

static const u8 sTM41Desc[] = _(
    "Impide al rival\n"
    "repetir el mismo\n"
    "movimiento.");

static const u8 sTM42Desc[] = _(
    "+Ataque si tiene\n"
    "veneno, quemadura o\n"
    "parálisis.");

static const u8 sTM43Desc[] = _(
    "Añade un efecto al\n"
    "ataque según el\n"
    "lugar.");

static const u8 sTM44Desc[] = _(
    "Duerme 2 turnos y\n"
    "recupera PS y\n"
    "estado.");

static const u8 sTM45Desc[] = _(
    "Dificulta que el\n"
    "sexo opuesto le\n"
    "ataque.");

static const u8 sTM46Desc[] = _(
    "Al atacar, puede\n"
    "robar el objeto del\n"
    "rival.");

static const u8 sTM47Desc[] = _(
    "Despliega unas alas\n"
    "afiladas y golpea al\n"
    "rival.");

static const u8 sTM48Desc[] = _(
    "Intercambia su\n"
    "habilidad con la del\n"
    "rival.");

static const u8 sTM49Desc[] = _(
    "Roba el efecto del\n"
    "movimiento que usa\n"
    "el rival.");

static const u8 sTM50Desc[] = _(
    "Ataca con toda su\n"
    "fuerza, pero baja\n"
    "mucho el At. Esp.");

static const u8 sTM51Desc[] = _( // Todo
    "?????");

static const u8 sTM52Desc[] = _( // Todo
    "?????");

static const u8 sTM53Desc[] = _( // Todo
    "?????");

static const u8 sTM54Desc[] = _( // Todo
    "?????");

static const u8 sTM55Desc[] = _( // Todo
    "?????");

static const u8 sTM56Desc[] = _( // Todo
    "?????");

static const u8 sTM57Desc[] = _( // Todo
    "?????");

static const u8 sTM58Desc[] = _( // Todo
    "?????");

static const u8 sTM59Desc[] = _( // Todo
    "?????");

static const u8 sTM60Desc[] = _( // Todo
    "?????");

static const u8 sTM61Desc[] = _( // Todo
    "?????");

static const u8 sTM62Desc[] = _( // Todo
    "?????");

static const u8 sTM63Desc[] = _( // Todo
    "?????");

static const u8 sTM64Desc[] = _( // Todo
    "?????");

static const u8 sTM65Desc[] = _( // Todo
    "?????");

static const u8 sTM66Desc[] = _( // Todo
    "?????");

static const u8 sTM67Desc[] = _( // Todo
    "?????");

static const u8 sTM68Desc[] = _( // Todo
    "?????");

static const u8 sTM69Desc[] = _( // Todo
    "?????");

static const u8 sTM70Desc[] = _( // Todo
    "?????");

static const u8 sTM71Desc[] = _( // Todo
    "?????");

static const u8 sTM72Desc[] = _( // Todo
    "?????");

static const u8 sTM73Desc[] = _( // Todo
    "?????");

static const u8 sTM74Desc[] = _( // Todo
    "?????");

static const u8 sTM75Desc[] = _( // Todo
    "?????");

static const u8 sTM76Desc[] = _( // Todo
    "?????");

static const u8 sTM77Desc[] = _( // Todo
    "?????");

static const u8 sTM78Desc[] = _( // Todo
    "?????");

static const u8 sTM79Desc[] = _( // Todo
    "?????");

static const u8 sTM80Desc[] = _( // Todo
    "?????");

static const u8 sTM81Desc[] = _( // Todo
    "?????");

static const u8 sTM82Desc[] = _( // Todo
    "?????");

static const u8 sTM83Desc[] = _( // Todo
    "?????");

static const u8 sTM84Desc[] = _( // Todo
    "?????");

static const u8 sTM85Desc[] = _( // Todo
    "?????");

static const u8 sTM86Desc[] = _( // Todo
    "?????");

static const u8 sTM87Desc[] = _( // Todo
    "?????");

static const u8 sTM88Desc[] = _( // Todo
    "?????");

static const u8 sTM89Desc[] = _( // Todo
    "?????");

static const u8 sTM90Desc[] = _( // Todo
    "?????");

static const u8 sTM91Desc[] = _( // Todo
    "?????");

static const u8 sTM92Desc[] = _( // Todo
    "?????");

static const u8 sTM93Desc[] = _( // Todo
    "?????");

static const u8 sTM94Desc[] = _( // Todo
    "?????");

static const u8 sTM95Desc[] = _( // Todo
    "?????");

static const u8 sTM96Desc[] = _( // Todo
    "?????");

static const u8 sTM97Desc[] = _( // Todo
    "?????");

static const u8 sTM98Desc[] = _( // Todo
    "?????");

static const u8 sTM99Desc[] = _( // Todo
    "?????");

static const u8 sTM100Desc[] = _( // Todo
    "?????");

static const u8 sHM01Desc[] = _(
    "Ataca al rival con\n"
    "cuchillas o garras\n"
    "afiladas.");

static const u8 sHM02Desc[] = _(
    "Vuela alto el 1.er\n"
    "turno y ataca en el\n"
    "siguiente.");

static const u8 sHM03Desc[] = _(
    "Crea una ola enorme\n"
    "que cae sobre el\n"
    "rival.");

static const u8 sHM04Desc[] = _(
    "Acumula mucha\n"
    "fuerza y luego\n"
    "golpea al rival.");

static const u8 sHM05Desc[] = _(
    "Lanza un potente\n"
    "destello que baja la\n"
    "precisión.");

static const u8 sHM06Desc[] = _(
    "Ataque demoledor\n"
    "que puede bajar la\n"
    "Defensa.");

static const u8 sHM07Desc[] = _(
    "Embiste con fuerza\n"
    "para remontar\n"
    "cascadas.");

static const u8 sHM08Desc[] = _(
    "Se sumerge el 1.er\n"
    "turno y ataca en el\n"
    "siguiente.");

// Charms
static const u8 sOvalCharmDesc[] = _(
    "Amuleto ovalado:\n"
    "más Huevos en la\n"
    "guardería.");

static const u8 sShinyCharmDesc[] = _(
    "Amuleto brillante:\n"
    "más Pokémon\n"
    "variocolor.");

static const u8 sCatchingCharmDesc[] = _(
    "Aumenta la\n"
    "probabilidad de\n"
    "capturas críticas.");

static const u8 sExpCharmDesc[] = _(
    "Amuleto que aumenta\n"
    "los Puntos de\n"
    "Experiencia.");

// Form-changing Key Items
static const u8 sRotomCatalogDesc[] = _(
    "Catálogo de los\n"
    "artilugios\n"
    "favoritos de Rotom.");

static const u8 sGracideaDesc[] = _(
    "Flor que se regala\n"
    "en ramos de\n"
    "agradecimiento.");

static const u8 sRevealGlassDesc[] = _(
    "Espejo que devuelve\n"
    "a su forma original.");

static const u8 sDNASplicersDesc[] = _(
    "Punta que fusiona a\n"
    "Kyurem con cierto\n"
    "Pokémon.");

static const u8 sZygardeCubeDesc[] = _(
    "Almacena núcleos y\n"
    "células de Zygarde.");

static const u8 sPrisonBottleDesc[] = _(
    "Vasija que confina\n"
    "el poder de cierto\n"
    "Pokémon.");

static const u8 sNSolarizerDesc[] = _(
    "Aparato que fusiona\n"
    "y separa a Necrozma\n"
    "con Solgaleo.");

static const u8 sNLunarizerDesc[] = _(
    "Aparato que fusiona\n"
    "y separa a Necrozma\n"
    "con Lunala.");

static const u8 sReinsOfUnityDesc[] = _(
    "Correas brillantes,\n"
    "ofrenda al Rey de\n"
    "las Cosechas.");

// Battle Mechanic Key Items
static const u8 sMegaRingDesc[] = _(
    "Permite\n"
    "megaevolucionar con\n"
    "una Megapiedra.");

static const u8 sZPowerRingDesc[] = _(
    "Pulsera que permite\n"
    "usar movimientos Z.");

static const u8 sDynamaxBandDesc[] = _(
    "Con una Estrella\n"
    "Deseo, permite\n"
    "dinamaxizar.");

// Misc. Key Items
static const u8 sBicycleDesc[] = _(
    "Bici plegable más\n"
    "rápida que las\n"
    "Deportivas.");

static const u8 sMachBikeDesc[] = _(
    "Bicicleta plegable\n"
    "el doble de rápida.");

static const u8 sAcroBikeDesc[] = _(
    "Bicicleta plegable\n"
    "para saltos y\n"
    "acrobacias.");

static const u8 sOldRodDesc[] = _(
    "Caña usada y\n"
    "desgastada para\n"
    "pescar Pokémon.");

static const u8 sGoodRodDesc[] = _(
    "Caña nuevecita y de\n"
    "gran calidad.");

static const u8 sSuperRodDesc[] = _(
    "Increíble caña de\n"
    "pescar de alta\n"
    "tecnología.");

static const u8 sDowsingMachineDesc[] = _(
    "Reacciona ante\n"
    "objetos que no se\n"
    "ven.");

static const u8 sTownMapDesc[] = _(
    "Mapa que indica\n"
    "dónde te\n"
    "encuentras.");

static const u8 sVsSeekerDesc[] = _(
    "Busca Entrenadores\n"
    "listos para el\n"
    "combate.");

static const u8 sTMCaseDesc[] = _(
    "Un estuche práctico\n"
    "para guardar MT y\n"
    "MO.");

static const u8 sBerryPouchDesc[] = _(
    "Un recipiente\n"
    "práctico para\n"
    "guardar bayas.");

static const u8 sPokemonBoxLinkDesc[] = _(
    "Da acceso a tus\n"
    "Cajas del PC en todo\n"
    "momento.");

static const u8 sCoinCaseDesc[] = _(
    "Un estuche que\n"
    "guarda hasta 9.999\n"
    "fichas.");

static const u8 sPowderJarDesc[] = _(
    "Guarda el Polvo Baya\n"
    "hecho con la\n"
    "Trituradora.");

static const u8 sWailmerPailDesc[] = _(
    "Regadera con forma\n"
    "de Wailmer para las\n"
    "bayas.");

static const u8 sPokeRadarDesc[] = _(
    "Busca Pokémon que\n"
    "se esconden en la\n"
    "hierba.");

static const u8 sPokeblockCaseDesc[] = _(
    "Un estuche para\n"
    "guardar los {POKEBLOCK}\n"
    "de la Licuadora.");

static const u8 sSootSackDesc[] = _(
    "Bolsa para recoger\n"
    "ceniza volcánica.");

static const u8 sPokeFluteDesc[] = _(
    "Flauta de timbre\n"
    "dulce que despierta\n"
    "Pokémon.");

static const u8 sFameCheckerDesc[] = _(
    "Guarda información\n"
    "sobre gente famosa.");

static const u8 sTeachyTVDesc[] = _(
    "Una tele con un\n"
    "programa de\n"
    "consejos.");

// Story Key Items
static const u8 sSSTicketDesc[] = _(
    "El billete necesario\n"
    "para viajar en\n"
    "ferry.");

static const u8 sEonTicketDesc[] = _(
    "Billete de barco\n"
    "para viajar a Isla\n"
    "del Sur.");

static const u8 sMysticTicketDesc[] = _(
    "Un billete para\n"
    "subir al barco a\n"
    "Roca Ombligo.");

static const u8 sAuroraTicketDesc[] = _(
    "Un billete para\n"
    "subir al barco a Isla\n"
    "Origen.");

static const u8 sOldSeaMapDesc[] = _(
    "Una carta náutica\n"
    "gastada que lleva a\n"
    "una isla.");

static const u8 sLetterDesc[] = _(
    "Carta del\n"
    "presidente de Devon\n"
    "S.A.");

static const u8 sDevonPartsDesc[] = _(
    "Contiene piezas de\n"
    "algo fabricado por\n"
    "Devon S. A.");

static const u8 sGoGogglesDesc[] = _(
    "Gafas que protegen\n"
    "de las tormentas de\n"
    "arena.");

static const u8 sDevonScopeDesc[] = _(
    "Revela a los\n"
    "Pokémon invisibles\n"
    "con sonidos.");

static const u8 sBasementKeyDesc[] = _(
    "La llave de\n"
    "Malvalanova, bajo\n"
    "Ciudad Malvalona.");

static const u8 sScannerDesc[] = _(
    "Un aparato\n"
    "encontrado en la\n"
    "Nao Abandonada.");

static const u8 sStorageKeyDesc[] = _(
    "La llave del almacén\n"
    "de la Nao\n"
    "Abandonada.");

static const u8 sKeyToRoom1Desc[] = _(
    "Llave de una puerta\n"
    "de la Nao\n"
    "Abandonada.");

static const u8 sKeyToRoom2Desc[] = _(
    "Llave de una puerta\n"
    "de la Nao\n"
    "Abandonada.");

static const u8 sKeyToRoom4Desc[] = _(
    "Llave de una puerta\n"
    "de la Nao\n"
    "Abandonada.");

static const u8 sKeyToRoom6Desc[] = _(
    "Llave de una puerta\n"
    "de la Nao\n"
    "Abandonada.");

static const u8 sMeteoriteDesc[] = _(
    "Meteorito de la\n"
    "Cascada Meteoro.");

static const u8 sMagmaEmblemDesc[] = _(
    "Una medalla con la\n"
    "forma del emblema\n"
    "del Equipo Magma.");

static const u8 sContestPassDesc[] = _(
    "Pase para\n"
    "participar en los\n"
    "Concursos Pokémon.");

static const u8 sParcelDesc[] = _(
    "Paquete que debes\n"
    "entregar al Prof.\n"
    "Oak.");

static const u8 sSecretKeyDesc[] = _(
    "La llave del\n"
    "Gimnasio de Isla\n"
    "Canela.");

static const u8 sBikeVoucherDesc[] = _(
    "Un vale para\n"
    "conseguir una bici\n"
    "gratis.");

static const u8 sGoldTeethDesc[] = _(
    "Dientes de oro del\n"
    "Guarda de la Zona\n"
    "Safari.");

static const u8 sCardKeyDesc[] = _(
    "Tarjeta llave de las\n"
    "oficinas de Silph\n"
    "S.A.");

static const u8 sLiftKeyDesc[] = _(
    "Llave del ascensor\n"
    "de la Guarida\n"
    "Rocket.");

static const u8 sSilphScopeDesc[] = _(
    "Visor de Silph S.A.\n"
    "que revela lo\n"
    "invisible.");

static const u8 sTriPassDesc[] = _(
    "Pase de ferri entre\n"
    "las islas Uno, Dos y\n"
    "Tres.");

static const u8 sRainbowPassDesc[] = _(
    "Para los ferris\n"
    "entre Carmín y las\n"
    "Islas Sete.");

static const u8 sTeaDesc[] = _(
    "Té aromático ideal\n"
    "para aplacar la sed.");

static const u8 sRubyDesc[] = _(
    "Una gema roja y\n"
    "brillante que\n"
    "simboliza la pasión.");

static const u8 sSapphireDesc[] = _(
    "Gema azul brillante,\n"
    "símbolo de\n"
    "honestidad.");

static const u8 sAbilityShieldDesc[] = _(
    "Impide que cambien\n"
    "la habilidad del\n"
    "portador.");

static const u8 sClearAmuletDesc[] = _(
    "Impide que bajen las\n"
    "características del\n"
    "portador.");

static const u8 sPunchingGloveDesc[] = _(
    "Potencia los\n"
    "puñetazos y evita\n"
    "que hagan contacto.");

static const u8 sCovertCloakDesc[] = _(
    "Protege al portador\n"
    "de los efectos\n"
    "secundarios.");

static const u8 sLoadedDiceDesc[] = _(
    "Saca números altos:\n"
    "más golpes\n"
    "múltiples.");

static const u8 sAuspiciousArmorDesc[] = _(
    "Armadura llena de\n"
    "buenos deseos. Hace\n"
    "evolucionar.");

static const u8 sBoosterEnergyDesc[] = _(
    "Energía que\n"
    "potencia ciertas\n"
    "habilidades.");

static const u8 sBigBambooShootDesc[] = _(
    "Brote de bambú\n"
    "grande y raro. Muy\n"
    "cotizado.");

static const u8 sGimmighoulCoinDesc[] = _(
    "Gimmighoul acumula y\n"
    "atesora estas\n"
    "curiosas monedas.");

static const u8 sLeadersCrestDesc[] = _(
    "Fragmento de una\n"
    "hoja antigua. Lo\n"
    "lleva Bisharp.");

static const u8 sMaliciousArmorDesc[] = _(
    "Armadura llena de\n"
    "malicia. Hace\n"
    "evolucionar.");

static const u8 sMirrorHerbDesc[] = _(
    "Copia las mejoras de\n"
    "características del\n"
    "rival una vez.");

static const u8 sScrollOfDarknessDesc[] = _(
    "Pergamino con los\n"
    "secretos de la\n"
    "senda oscura.");

static const u8 sScrollOfWatersDesc[] = _(
    "Pergamino con los\n"
    "secretos de la\n"
    "senda del agua.");

static const u8 sTeraOrbDesc[] = _(
    "Su energía permite\n"
    "teracristalizar.");

static const u8 sTinyBambooShootDesc[] = _(
    "Brote de bambú\n"
    "pequeño y raro. Muy\n"
    "cotizado.");

static const u8 sTeraShardDesc[] = _(
    "Un fragmento que\n"
    "puede cambiar el\n"
    "teratipo de un {PKMN}.");

static const u8 sAdamantCrystalDesc[] = _(
    "Una gema grande y\n"
    "brillante que cambia\n"
    "la forma de Dialga.");

static const u8 sGriseousCoreDesc[] = _(
    "Una gema grande y\n"
    "brillante que cambia\n"
    "la forma de Giratina.");

static const u8 sLustrousGlobeDesc[] = _(
    "Una gema grande y\n"
    "brillante que cambia\n"
    "la forma de Palkia.");

static const u8 sBerserkGene[] = _(
    "Sube mucho el\n"
    "Ataque, pero\n"
    "confunde un tiempo.");

static const u8 sFairyFeatherDesc[] = _(
    "Pluma ligera que\n"
    "potencia el tipo\n"
    "Hada.");

static const u8 sSyrupyAppleDesc[] = _(
    "Manzana almibarada\n"
    "que hace\n"
    "evolucionar.");

static const u8 sUnremarkableTeacupDesc[] = _(
    "Taza rajada que\n"
    "hace evolucionar a\n"
    "un Pokémon.");

static const u8 sMasterpieceTeacupDesc[] = _(
    "Taza desportillada\n"
    "que hace\n"
    "evolucionar.");

static const u8 sCornerstoneMaskDesc[] = _(
    "Permite a Ogerpon\n"
    "usar el tipo Roca en\n"
    "combate.");

static const u8 sWellspringMaskDesc[] = _(
    "Permite a Ogerpon\n"
    "usar el tipo Agua en\n"
    "combate.");

static const u8 sHearthflameMaskDesc[] = _(
    "Permite a Ogerpon\n"
    "usar el tipo Fuego\n"
    "en combate.");

static const u8 sHealthMochiDesc[] = _(
    "Sube los PS base de\n"
    "un Pokémon.");

static const u8 sMuscleMochiDesc[] = _(
    "Sube el Ataque base\n"
    "de un Pokémon.");

static const u8 sResistMochiDesc[] = _(
    "Sube la Defensa\n"
    "base de un Pokémon.");

static const u8 sGeniusMochiDesc[] = _(
    "Sube el At. Esp. base\n"
    "de un Pokémon.");

static const u8 sCleverMochiDesc[] = _(
    "Sube la Def. Esp.\n"
    "base de un Pokémon.");

static const u8 sSwiftMochiDesc[] = _(
    "Sube la Velocidad\n"
    "base de un Pokémon.");

static const u8 sFreshStartMochiDesc[] = _(
    "Restablece todos\n"
    "los puntos base de\n"
    "un Pokémon.");

static const u8 sGlimmeringCharmDesc[] = _(
    "Aumenta los\n"
    "teralitos de las\n"
    "teraincursiones.");

static const u8 sMetalAlloyDesc[] = _(
    "Metal peculiar que\n"
    "hace evolucionar.");
