
#if B_BINDING_TURNS >= GEN_5
#define BINDING_TURNS "4 o 5"
#else
#define BINDING_TURNS "2 a 5"
#endif

static const u8 sNullDescription[] = _(
    "");

static const u8 sPoundDescription[] = _(
    "Golpea con las patas o la\n"
    "cola.");

static const u8 sKarateChopDescription[] = _(
    "Da un golpe cortante. Suele\n"
    "ser crítico.");

static const u8 sDoubleSlapDescription[] = _(
    "Abofetea de dos a cinco\n"
    "veces seguidas.");

static const u8 sCometPunchDescription[] = _(
    "Pega de dos a cinco veces\n"
    "seguidas.");

static const u8 sMegaPunchDescription[] = _(
    "Un puñetazo de gran\n"
    "potencia.");

static const u8 sPayDayDescription[] = _(
    "Arroja monedas que luego\n"
    "recupera.");

static const u8 sFirePunchDescription[] = _(
    "Puñetazo ardiente. Puede\n"
    "quemar.");

static const u8 sIcePunchDescription[] = _(
    "Puñetazo helado. Puede\n"
    "congelar.");

static const u8 sThunderPunchDescription[] = _(
    "Puñetazo eléctrico. Puede\n"
    "paralizar.");

static const u8 sScratchDescription[] = _(
    "Araña con afiladas garras.");

static const u8 sViseGripDescription[] = _(
    "Atrapa con potentes pinzas.");

static const u8 sGuillotineDescription[] = _(
    "Pinzas que pueden derribar\n"
    "de un golpe.");

static const u8 sRazorWindDescription[] = _(
    "1.er turno: prepara. 2.º:\n"
    "ataca.");

static const u8 sSwordsDanceDescription[] = _(
    "Baile frenético que aumenta\n"
    "mucho el Ataque.");

static const u8 sCutDescription[] = _(
    "Corta con garras, guadañas,\n"
    "etc.");

static const u8 sGustDescription[] = _(
    "Crea un tornado con las\n"
    "alas.");

static const u8 sWingAttackDescription[] = _(
    "Golpea al objetivo con unas\n"
    "grandes alas.");

static const u8 sWhirlwindDescription[] = _(
    "Se lleva al rival y termina\n"
    "el combate.");

static const u8 sFlyDescription[] = _(
    "1.er turno: vuela. 2.º:\n"
    "ataca.");

static const u8 sBindDescription[] = _(
    "Aprieta al rival con fuerza\n"
    "durante "BINDING_TURNS" turnos.");

static const u8 sSlamDescription[] = _(
    "Golpea con las\n"
    "extremidades.");

static const u8 sVineWhipDescription[] = _(
    "Azota al objetivo con ramas\n"
    "finas.");

static const u8 sStompDescription[] = _(
    "Tremendo pisotón que puede\n"
    "hacer retroceder al rival.");

static const u8 sDoubleKickDescription[] = _(
    "Una patada doble. Golpea dos\n"
    "veces.");

static const u8 sMegaKickDescription[] = _(
    "Patada de extrema fuerza.");

static const u8 sJumpKickDescription[] = _(
    "Da un salto y pega una\n"
    "patada. Si falla, se lesiona.");

static const u8 sRollingKickDescription[] = _(
    "Una patada rápida y\n"
    "circular.");

static const u8 sSandAttackDescription[] = _(
    "Arroja arena a la cara y\n"
    "baja la Precisión.");

static const u8 sHeadbuttDescription[] = _(
    "Cabezazo que puede hacer\n"
    "retroceder al rival.");

static const u8 sHornAttackDescription[] = _(
    "Ataca al objetivo con una\n"
    "cornada.");

static const u8 sFuryAttackDescription[] = _(
    "Cornea al objetivo de dos a\n"
    "cinco veces.");

static const u8 sHornDrillDescription[] = _(
    "Ataque taladro. Fulmina en\n"
    "un golpe.");

static const u8 sTackleDescription[] = _(
    "Embiste con todo el cuerpo.");

static const u8 sBodySlamDescription[] = _(
    "Ataque corporal que puede\n"
    "paralizar.");

static const u8 sWrapDescription[] = _(
    "Envuelve y aprieta al rival\n"
    BINDING_TURNS" veces con lianas.");

static const u8 sTakeDownDescription[] = _(
    "Carga desmedida que también\n"
    "hiere al agresor.");

static const u8 sThrashDescription[] = _(
    "Embestida que dura 2 ó 3\n"
    "turnos y te confunde.");

static const u8 sDoubleEdgeDescription[] = _(
    "Ataque arriesgado que\n"
    "también hiere al agresor.");

static const u8 sTailWhipDescription[] = _(
    "Agita la cola para bajar la\n"
    "Defensa del contrincante.");

static const u8 sPoisonStingDescription[] = _(
    "Puede envenenar al enemigo\n"
    "con púas tóxicas.");

static const u8 sTwineedleDescription[] = _(
    "Pincha dos veces con dos\n"
    "espinas. Puede envenenar.");

static const u8 sPinMissileDescription[] = _(
    "Lanza finas púas que hieren\n"
    "de dos a cinco veces.");

static const u8 sLeerDescription[] = _(
    "Intimida al objetivo para\n"
    "bajar su Defensa.");

static const u8 sBiteDescription[] = _(
    "Un voraz bocado que puede\n"
    "hacer retroceder al rival.");

static const u8 sGrowlDescription[] = _(
    "Dulce gruñido que reduce el\n"
    "Ataque del contrincante.");

static const u8 sRoarDescription[] = _(
    "Ahuyenta al rival y finaliza\n"
    "el combate.");

static const u8 sSingDescription[] = _(
    "Cancioncilla que puede\n"
    "dormir al enemigo.");

static const u8 sSupersonicDescription[] = _(
    "Raras ondas sónicas que\n"
    "pueden confundir.");

static const u8 sSonicBoomDescription[] = _(
    "Lanza ondas de choque que\n"
    "restan 20 PS al objetivo.");

static const u8 sDisableDescription[] = _(
    "Desactiva un ataque del\n"
    "contrincante.");

static const u8 sAcidDescription[] = _(
    "Rocía un ácido corrosivo.\n"
#if B_UPDATED_MOVE_DATA >= GEN_4
    "Puede bajar la Def. Esp.");
#else
    "Puede bajar la Defensa.");
#endif

static const u8 sEmberDescription[] = _(
    "Ligero ataque que puede\n"
    "causar quemaduras.");

static const u8 sFlamethrowerDescription[] = _(
    "Fuerte ataque que puede\n"
    "causar quemaduras.");

static const u8 sMistDescription[] = _(
    "Te rodea de fina niebla y\n"
    "protege tus habilidades.");

static const u8 sWaterGunDescription[] = _(
    "Ataca disparando agua con\n"
    "gran potencia.");

static const u8 sHydroPumpDescription[] = _(
    "Lanza una gran masa de agua\n"
    "a presión para atacar.");

static const u8 sSurfDescription[] = _(
    "Crea una ola enorme y se la\n"
    "lanza al enemigo.");

static const u8 sIceBeamDescription[] = _(
    "Rayo de hielo que puede\n"
    "llegar a congelar.");

static const u8 sBlizzardDescription[] = _(
    "Tormenta helada. Puede\n"
    "causar congelación.");

static const u8 sPsybeamDescription[] = _(
    "Extraño rayo que puede\n"
    "causar confusión.");

static const u8 sBubbleBeamDescription[] = _(
    "Diluvio de burbujas que\n"
    "puede bajar la Velocidad.");

static const u8 sAuroraBeamDescription[] = _(
    "Rayo multicolor que puede\n"
    "reducir el Ataque.");

static const u8 sHyperBeamDescription[] = _(
    "Es muy eficaz, pero te\n"
    "inmoviliza 1 turno.");

static const u8 sPeckDescription[] = _(
    "Ensarta al objetivo con un\n"
    "cuerno o pico punzante.");

static const u8 sDrillPeckDescription[] = _(
    "Picotazo giratorio y\n"
    "perforador muy potente.");

static const u8 sSubmissionDescription[] = _(
    "Tira al objetivo al suelo.\n"
    "También hiere al agresor.");

static const u8 sLowKickDescription[] = _(
    "Cuanto más pesa el enemigo,\n"
    "más daño causa.");

static const u8 sCounterDescription[] = _(
    "Devuelve un golpe físico por\n"
    "duplicado.");

static const u8 sSeismicTossDescription[] = _(
    "Se restarán tantos PS como\n"
    "nivel tenga el agresor.");

static const u8 sStrengthDescription[] = _(
    "Potente ataque físico.");

static const u8 sAbsorbDescription[] = _(
    "Absorbe la mitad del daño\n"
    "producido.");

static const u8 sMegaDrainDescription[] = _(
    "Absorbe la mitad del daño\n"
    "producido.");

static const u8 sLeechSeedDescription[] = _(
    "Planta tres semillas que\n"
    "quitan PS en cada turno.");

static const u8 sGrowthDescription[] = _(
    "Crece a marchas forzadas y\n"
    "aumenta el At. Esp.");

static const u8 sRazorLeafDescription[] = _(
    "Corta con hojas afiladas.\n"
    "Suele ser crítico.");

static const u8 sSolarBeamDescription[] = _(
    "Primer turno: absorbe luz.\n"
    "Segundo turno: ataca.");

static const u8 sPoisonPowderDescription[] = _(
    "Polvo tóxico que envenena\n"
    "al objetivo.");

static const u8 sStunSporeDescription[] = _(
    "Esparce polvo que puede\n"
    "paralizar al enemigo.");

static const u8 sSleepPowderDescription[] = _(
    "Esparce polvo que puede\n"
    "dormir al enemigo.");

static const u8 sPetalDanceDescription[] = _(
    "Embestida que dura 2 ó 3\n"
    "turnos y te confunde.");

static const u8 sStringShotDescription[] = _(
    "Baja la Velocidad del\n"
    "enemigo.");

static const u8 sDragonRageDescription[] = _(
    "Ráfaga de furiosas ondas de\n"
    "choque que quitan 40 PS.");

static const u8 sFireSpinDescription[] = _(
    "Atrapa al rival en un aro\n"
    "de fuego "BINDING_TURNS" turnos.");

static const u8 sThunderShockDescription[] = _(
    "Ataque eléctrico que puede\n"
    "paralizar al objetivo.");

static const u8 sThunderboltDescription[] = _(
    "Duro ataque eléctrico que\n"
    "puede paralizar al enemigo.");

static const u8 sThunderWaveDescription[] = _(
    "Una descarga que puede\n"
    "paralizar al enemigo.");

static const u8 sThunderDescription[] = _(
    "Un rayo que puede paralizar\n"
    "al enemigo.");

static const u8 sRockThrowDescription[] = _(
    "Tira una pequeña roca al\n"
    "objetivo.");

static const u8 sEarthquakeDescription[] = _(
    "Fuerte, pero inútil contra\n"
    "voladores.");

static const u8 sFissureDescription[] = _(
    "Ataque de tierra. Fulmina en\n"
    "1 golpe.");

static const u8 sDigDescription[] = _(
    "1.er turno: cava. 2.º: ataca.");

static const u8 sToxicDescription[] = _(
    "Envenena al rival de forma\n"
    "progresiva.");

static const u8 sConfusionDescription[] = _(
    "Débil ataque telequinético\n"
    "que puede causar confusión.");

static const u8 sPsychicDescription[] = _(
    "Fuerte ataque psíquico que\n"
    "puede bajar la Def. Esp.");

static const u8 sHypnosisDescription[] = _(
    "Ataque hipnótico que puede\n"
    "dormir al enemigo.");

static const u8 sMeditateDescription[] = _(
    "El usuario reposa y medita\n"
    "para potenciar el Ataque.");

static const u8 sAgilityDescription[] = _(
    "Relaja el cuerpo para ganar\n"
    "mucha Velocidad.");

static const u8 sQuickAttackDescription[] = _(
    "Ataque rápido que permite\n"
    "golpear en 1.er lugar.");

static const u8 sRageDescription[] = _(
    "Mejora tu Ataque cada vez\n"
    "que te golpean.");

static const u8 sTeleportDescription[] = _(
    "Movimiento psíquico que\n"
    "permite huir al instante.");

static const u8 sNightShadeDescription[] = _(
    "Se restarán tantos PS como\n"
    "nivel tenga el agresor.");

static const u8 sMimicDescription[] = _(
    "Copia un ataque usado por el\n"
    "enemigo.");

static const u8 sScreechDescription[] = _(
    "Alarido agudo que reduce\n"
    "mucho la Defensa del rival.");

static const u8 sDoubleTeamDescription[] = _(
    "Crea copias de sí mismo para\n"
    "mejorar la Evasión.");

static const u8 sRecoverDescription[] = _(
    "Restaura hasta la mitad de\n"
    "tus PS máximos.");

static const u8 sHardenDescription[] = _(
    "Tensa la musculatura para\n"
    "aumentar la Defensa.");

static const u8 sMinimizeDescription[] = _(
    "El usuario mengua para\n"
    "aumentar mucho la Evasión.");

static const u8 sSmokescreenDescription[] = _(
    "Nube de humo que baja la\n"
    "Precisión del rival.");

static const u8 sConfuseRayDescription[] = _(
    "Rayo siniestro que confunde\n"
    "al objetivo.");

static const u8 sWithdrawDescription[] = _(
    "El usuario se protege en su\n"
    "coraza y sube la Defensa.");

static const u8 sDefenseCurlDescription[] = _(
    "Oculta su punto débil al\n"
    "rizarse. Sube la Defensa.");

static const u8 sBarrierDescription[] = _(
    "Crea una barrera para\n"
    "aumentar mucho la Defensa.");

static const u8 sLightScreenDescription[] = _(
    "Reduce el daño que causa el\n"
    "At. Esp. del rival.");

static const u8 sHazeDescription[] = _(
    "Nube negra que elimina los\n"
    "cambios de característ.");

static const u8 sReflectDescription[] = _(
    "Pared de luz que debilita\n"
    "los ataques físicos.");

static const u8 sFocusEnergyDescription[] = _(
    "Concentra energía para\n"
    "asegurar un golpe crítico.");

static const u8 sBideDescription[] = _(
    "Espera 2 turnos para atacar\n"
    "con doble potencia.");

static const u8 sMetronomeDescription[] = _(
    "Usa al azar un ataque\n"
    "Pokémon.");

static const u8 sMirrorMoveDescription[] = _(
    "Contraataca con el mismo\n"
    "movimiento.");

static const u8 sSelfDestructDescription[] = _(
    "Causa mucho daño, pero te\n"
    "debilita.");

static const u8 sEggBombDescription[] = _(
    "Arroja un huevo al objetivo\n"
    "con gran fuerza.");

static const u8 sLickDescription[] = _(
    "Usa la lengua para atacar.\n"
    "Puede causar parálisis.");

static const u8 sSmogDescription[] = _(
    "Gases de escape que pueden\n"
    "llegar a envenenar.");

static const u8 sSludgeDescription[] = _(
    "Arroja residuos al rival.\n"
    "Puede llegar a envenenar.");

static const u8 sBoneClubDescription[] = _(
    "Aporrea con un hueso. Puede\n"
    "causar el retroceso.");

static const u8 sFireBlastDescription[] = _(
    "Llama intensa que chamusca\n"
    "y puede causar quemaduras.");

static const u8 sWaterfallDescription[] = _(
    "Embiste con impulso para\n"
    "remontar una cascada.");

static const u8 sClampDescription[] = _(
    "Atrapa y aprieta al rival\n"
    "durante "BINDING_TURNS" turnos.");

static const u8 sSwiftDescription[] = _(
    "Lanza rayos en forma de\n"
    "estrella que no fallan.");

static const u8 sSkullBashDescription[] = _(
    "1.er turno: se prepara. 2.º:\n"
    "da el cabezazo.");

static const u8 sSpikeCannonDescription[] = _(
    "Lanza finas púas que hieren\n"
    "de dos a cinco veces.");

static const u8 sConstrictDescription[] = _(
    "Constriñe para herir y\n"
    "puede bajar la Velocidad.");

static const u8 sAmnesiaDescription[] = _(
    "Olvida algo y aumenta mucho\n"
    "la Defensa Esp.");

static const u8 sKinesisDescription[] = _(
    "Distrae al rival y baja su\n"
    "nivel de Precisión.");

static const u8 sSoftBoiledDescription[] = _(
    "Restaura hasta la mitad de\n"
    "tus PS máximos.");

static const u8 sHighJumpKickDescription[] = _(
    "Si fallas esta patada,\n"
    "puedes autolesionarte.");

static const u8 sGlareDescription[] = _(
    "Intimida y asusta al rival\n"
    "hasta dejarlo paralizado.");

static const u8 sDreamEaterDescription[] = _(
    "Roba la mitad del daño\n"
    "causado a un rival dormido.");

static const u8 sPoisonGasDescription[] = _(
    "Envuelve al enemigo en gas\n"
    "tóxico venenoso.");

static const u8 sBarrageDescription[] = _(
    "Arroja esferas al rival de 2\n"
    "a 5 veces.");

static const u8 sLeechLifeDescription[] = _(
    "Absorbe la mitad del daño\n"
    "producido.");

static const u8 sLovelyKissDescription[] = _(
    "Pide un beso con una cara\n"
    "que asusta y adormece.");

static const u8 sSkyAttackDescription[] = _(
    "1.º, busca punto flaco. 2.º,\n"
    "va a por él.");

static const u8 sTransformDescription[] = _(
    "Modifica las células del\n"
    "rival y lo clona.");

static const u8 sBubbleDescription[] = _(
    "Usa burbujas para intentar\n"
    "bajar la Velocidad.");

static const u8 sDizzyPunchDescription[] = _(
    "Rítmicos puñetazos que\n"
    "pueden causar confusión.");

static const u8 sSporeDescription[] = _(
    "Esparce esporas que inducen\n"
    "al sueño.");

static const u8 sFlashDescription[] = _(
    "Ciega con un fogonazo de luz\n"
    "y baja la Precisión.");

static const u8 sPsywaveDescription[] = _(
    "Ataque con onda de energía\n"
    "de intensidad variable.");

static const u8 sSplashDescription[] = _(
    "No tiene ningún efecto. Solo\n"
    "salpica.");

static const u8 sAcidArmorDescription[] = _(
    "Te hace líquido y aumenta\n"
    "bastante tu Defensa.");

static const u8 sCrabhammerDescription[] = _(
    "Golpea con fuerza con unas\n"
    "pinzas. Suele ser crítico.");

static const u8 sExplosionDescription[] = _(
    "Causa mucho daño, pero te\n"
    "debilita.");

static const u8 sFurySwipesDescription[] = _(
    "Araña rápidamente de dos a\n"
    "cinco veces.");

static const u8 sBonemerangDescription[] = _(
    "Lanza un hueso a modo de\n"
    "bumerán, que da 2 veces.");

static const u8 sRestDescription[] = _(
    "Te duerme durante 2 turnos\n"
    "para curarte totalmente.");

static const u8 sRockSlideDescription[] = _(
    "Lanza grandes pedruscos.\n"
    "Puede causar retroceso.");

static const u8 sHyperFangDescription[] = _(
    "Ataque con finos colmillos.\n"
    "Puede causar retroceso.");

static const u8 sSharpenDescription[] = _(
    "Mejora el Ataque de quien lo\n"
    "usa.");

static const u8 sConversionDescription[] = _(
    "Cambia tu tipo por el tipo\n"
    "de un ataque que tengas.");

static const u8 sTriAttackDescription[] = _(
    "Dispara 3 tipos de rayos a\n"
    "la vez.");

static const u8 sSuperFangDescription[] = _(
    "Finos colmillos que reducen\n"
    "a la mitad los PS del rival.");

static const u8 sSlashDescription[] = _(
    "Acuchilla con pinzas, etc.\n"
    "Suele dar un golpe crítico.");

static const u8 sSubstituteDescription[] = _(
    "Crea un señuelo con 1/4 de\n"
    "tus PS máximos.");

static const u8 sStruggleDescription[] = _(
    "Sólo se usa al acabarse los\n"
    "PP. Te hiere un poco.");

static const u8 sSketchDescription[] = _(
    "Copia siempre el último\n"
    "ataque del rival.");

static const u8 sTripleKickDescription[] = _(
    "Patea 3 veces seguidas y\n"
    "cada vez más fuerte.");

static const u8 sThiefDescription[] = _(
    "Puede quitarle al rival el\n"
    "objeto que lleve.");

static const u8 sSpiderWebDescription[] = _(
    "Enreda al rival para evitar\n"
    "que huya o pida el relevo.");

static const u8 sMindReaderDescription[] = _(
    "Adivina el ataque del otro y\n"
    "actúa en consecuencia.");

static const u8 sNightmareDescription[] = _(
    "El rival dormido pierde 1/4\n"
    "de PS por turno.");

static const u8 sFlameWheelDescription[] = _(
    "Ataca envuelto en fuego.\n"
    "Puede causar quemaduras.");

static const u8 sSnoreDescription[] = _(
    "Fuerte ronquido que puede\n"
    "usarse estando dormido.");

static const u8 sCurseDescription[] = _(
    "En el tipo Fantasma tiene un\n"
    "efecto distinto.");

static const u8 sFlailDescription[] = _(
    "Causa un daño mayor si\n"
    "tienes pocos PS.");

static const u8 sConversion2Description[] = _(
    "Tu tipo se hace resistente\n"
    "al último tipo de ataque.");

static const u8 sAeroblastDescription[] = _(
    "Lanza un chorro de aire que\n"
    "suele dar un golpe crítico.");

static const u8 sCottonSporeDescription[] = _(
    "Le pega esporas al rival\n"
    "para reducir su Velocidad.");

static const u8 sReversalDescription[] = _(
    "Causa un daño mayor si\n"
    "tienes pocos PS.");

static const u8 sSpiteDescription[] = _(
    "Baja con rencor PP del\n"
    "último ataque recibido.");

static const u8 sPowderSnowDescription[] = _(
    "Lanza nieve que puede\n"
    "llegar a congelar.");

static const u8 sProtectDescription[] = _(
    "Frena ataques, pero puede\n"
    "fallar si se usa sin parar.");

static const u8 sMachPunchDescription[] = _(
    "Puñetazo que se da rápido\n"
    "para golpear primero.");

static const u8 sScaryFaceDescription[] = _(
    "Asusta al objetivo para\n"
    "reducir mucho su Velocidad.");

static const u8 sFeintAttackDescription[] = _(
    "Acerca al enemigo para que\n"
    "el golpe no falle.");

static const u8 sSweetKissDescription[] = _(
    "Pide un beso con dulzura y\n"
    "suele causar confusión.");

static const u8 sBellyDrumDescription[] = _(
    "Reduce tus PS para mejorar\n"
    "el Ataque.");

static const u8 sSludgeBombDescription[] = _(
    "Arroja residuos al rival.\n"
    "Puede llegar a envenenar.");

static const u8 sMudSlapDescription[] = _(
    "Echa lodo en la cara para\n"
    "bajar la Precisión.");

static const u8 sOctazookaDescription[] = _(
    "Dispara tinta a la cara.\n"
    "Puede bajar la Precisión.");

static const u8 sSpikesDescription[] = _(
    "Esparce púas que hieren al\n"
    "rival que entre en combate.");

static const u8 sZapCannonDescription[] = _(
    "No es certero, pero causa\n"
    "parálisis si atina.");

static const u8 sForesightDescription[] = _(
    "Anula los intentos del rival\n"
    "de aumentar la Evasión.");

static const u8 sDestinyBondDescription[] = _(
    "Si te debilitas, el enemigo\n"
    "se debilita contigo.");

static const u8 sPerishSongDescription[] = _(
    "A los 3 turnos del canto,\n"
    "caen rival y atacante.");

static const u8 sIcyWindDescription[] = _(
    "Ataque con aire helado que\n"
    "baja la Velocidad.");

static const u8 sDetectDescription[] = _(
    "Frena ataques, pero puede\n"
    "fallar si se usa sin parar.");

static const u8 sBoneRushDescription[] = _(
    "Hueso en ristre, aporrea al\n"
    "enemigo de 2 a 5 veces.");

static const u8 sLockOnDescription[] = _(
    "Fija el blanco para que el\n"
    "siguiente ataque no falle.");

static const u8 sOutrageDescription[] = _(
    "Embestida que dura 2 ó 3\n"
    "turnos y te confunde.");

static const u8 sSandstormDescription[] = _(
    "Tormenta de arena que dura\n"
    "varios turnos.");

static const u8 sGigaDrainDescription[] = _(
    "Absorbe la mitad del daño\n"
    "producido.");

static const u8 sEndureDescription[] = _(
    "Resiste el ataque de 1 turno\n"
    "y deja al menos 1 PS.");

static const u8 sCharmDescription[] = _(
    "Engatusa al objetivo y\n"
    "reduce bastante su Ataque.");

static const u8 sRolloutDescription[] = _(
    "Ataque de 5 turnos, con\n"
    "fuerza cada vez mayor.");

static const u8 sFalseSwipeDescription[] = _(
    "Deja al enemigo con al menos\n"
    "1 PS.");

static const u8 sSwaggerDescription[] = _(
    "Provoca confusión, pero\n"
    "también sube el Ataque.");

static const u8 sMilkDrinkDescription[] = _(
    "Restaura hasta la mitad de\n"
    "tus PS máximos.");

static const u8 sSparkDescription[] = _(
    "Ataque eléctrico que puede\n"
    "llegar a paralizar.");

static const u8 sFuryCutterDescription[] = _(
    "Crece en intensidad si se\n"
    "usa repetidas veces.");

static const u8 sSteelWingDescription[] = _(
    "Alas rígidas que golpean al\n"
    "rival.");

static const u8 sMeanLookDescription[] = _(
    "Mal de ojo que impide al\n"
    "rival huir o pedir el relevo.");

static const u8 sAttractDescription[] = _(
    "Reduce la posibilidad de que\n"
    "el enemigo ataque.");

static const u8 sSleepTalkDescription[] = _(
    "Mientras duerme, usa un\n"
    "ataque elegido al azar.");

static const u8 sHealBellDescription[] = _(
    "Repicar que cura los\n"
    "problemas de estado.");

static const u8 sReturnDescription[] = _(
    "Ataque que aumenta sus\n"
    "efectos con la amistad.");

static const u8 sPresentDescription[] = _(
    "Regalo con forma de bomba.\n"
    "Puede que restaure los PS.");

static const u8 sFrustrationDescription[] = _(
    "Es más fuerte si no se\n"
    "aprecia al Entrenador.");

static const u8 sSafeguardDescription[] = _(
    "Fuerza mística que evita\n"
    "problemas de estado.");

static const u8 sPainSplitDescription[] = _(
    "Une tus PS a los del rival y\n"
    "los reparte por igual.");

static const u8 sSacredFireDescription[] = _(
    "Fuego místico que puede\n"
    "causar quemaduras.");

static const u8 sMagnitudeDescription[] = _(
    "Sacudida sísmica de\n"
    "intensidad variable.");

static const u8 sDynamicPunchDescription[] = _(
    "No es certero, pero causa\n"
    "confusión si atina.");

static const u8 sMegahornDescription[] = _(
    "Violenta embestida con\n"
    "cuernos imponentes.");

static const u8 sDragonBreathDescription[] = _(
    "Fuerte ráfaga de aliento\n"
    "que golpea al enemigo.");

static const u8 sBatonPassDescription[] = _(
    "Cambia de compañero y\n"
    "mantiene los estados.");

static const u8 sEncoreDescription[] = _(
    "El rival repite el último\n"
    "ataque de 2 a 6 veces.");

static const u8 sPursuitDescription[] = _(
    "Hace mucho daño al rival que\n"
    "pide el relevo.");

static const u8 sRapidSpinDescription[] = _(
    "Ataque corporal giratorio\n"
    "de gran velocidad.");

static const u8 sSweetScentDescription[] = _(
    "Engatusa al rival para\n"
    "reducir su Evasión.");

static const u8 sIronTailDescription[] = _(
    "Ataca con una cola férrea y\n"
    "puede bajar la Defensa.");

static const u8 sMetalClawDescription[] = _(
    "Ataque con garra que puede\n"
    "aumentar tu Ataque.");

static const u8 sVitalThrowDescription[] = _(
    "El usuario ataca el último,\n"
    "pero no falla.");

static const u8 sMorningSunDescription[] = _(
    "Restaura PS. La cantidad\n"
    "varía según el clima.");

static const u8 sSynthesisDescription[] = _(
    "Restaura PS. La cantidad\n"
    "varía según el clima.");

static const u8 sMoonlightDescription[] = _(
    "Restaura PS. La cantidad\n"
    "varía según el clima.");

static const u8 sHiddenPowerDescription[] = _(
    "Su eficacia varía según el\n"
    "agresor.");

static const u8 sCrossChopDescription[] = _(
    "Corte doble que suele\n"
    "propinar un golpe crítico.");

static const u8 sTwisterDescription[] = _(
    "Crea un violento tornado\n"
    "para hacer trizas al rival.");

static const u8 sRainDanceDescription[] = _(
    "Refuerza los ataques de\n"
    "tipo Agua durante 5 turnos.");

static const u8 sSunnyDayDescription[] = _(
    "Sube los ataques de tipo\n"
    "Fuego durante 5 turnos.");

static const u8 sCrunchDescription[] = _(
    "Tritura con sus colmillos.\n"
#if B_UPDATED_MOVE_DATA >= GEN_4
    "Puede bajar la Defensa.");
#else
    "Puede bajar la Def. Esp.");
#endif

static const u8 sMirrorCoatDescription[] = _(
    "Responde a un Ataque\n"
    "Especial con doble fuerza.");

static const u8 sPsychUpDescription[] = _(
    "Copia los efectos del rival\n"
    "y te los adjudica.");

static const u8 sExtremeSpeedDescription[] = _(
    "Ataque extremadamente\n"
    "rápido y demoledor.");

static const u8 sAncientPowerDescription[] = _(
    "Puede subir todas las\n"
    "características.");

static const u8 sShadowBallDescription[] = _(
    "Lanza una bola negra que\n"
    "puede bajar la Def. Esp.");

static const u8 sFutureSightDescription[] = _(
    "Aumenta la energía interior\n"
    "para golpear a los 2 turnos.");

static const u8 sRockSmashDescription[] = _(
    "Ataque de fuerza brutal que\n"
    "puede bajar la Defensa.");

static const u8 sWhirlpoolDescription[] = _(
    "Atrapa y daña al rival en\n"
    "un remolino "BINDING_TURNS" turnos.");

static const u8 sBeatUpDescription[] = _(
    "Ataque de todo el equipo\n"
    "Pokémon.");

static const u8 sFakeOutDescription[] = _(
    "Ataca primero en un turno y\n"
    "puede causar retroceso.");

static const u8 sUproarDescription[] = _(
#if B_UPROAR_TURNS >= GEN_5
    "Arma alboroto de 2 a 5\n"
#else
    "Arma alboroto durante 3\n"
#endif
    "turnos. Nadie puede dormir.");

static const u8 sStockpileDescription[] = _(
    "Acumula energía hasta 3\n"
    "veces.");

static const u8 sSpitUpDescription[] = _(
    "Libera energía acumulada.\n"
    "Cuanta más, mejor.");

static const u8 sSwallowDescription[] = _(
    "Absorbe energía acumulada y\n"
    "restaura PS.");

static const u8 sHeatWaveDescription[] = _(
    "Provoca un viento abrasador\n"
    "que puede quemar al rival.");

static const u8 sHailDescription[] = _(
    "Tormenta de granizo que\n"
    "golpea en cada turno.");

static const u8 sTormentDescription[] = _(
    "Agobia e impide el uso\n"
    "reiterado de un ataque.");

static const u8 sFlatterDescription[] = _(
    "Confunde al rival, pero sube\n"
    "su At. Esp.");

static const u8 sWillOWispDescription[] = _(
    "Siniestra llama morada que\n"
    "produce quemaduras.");

static const u8 sMementoDescription[] = _(
    "Baja las habilidades del\n"
    "rival y te fulmina.");

static const u8 sFacadeDescription[] = _(
    "Potencia el Ataque al estar\n"
    "quemado, paraliz. o enven.");

static const u8 sFocusPunchDescription[] = _(
    "Es tardío, pero si el rival\n"
    "te golpea no te moverás.");

static const u8 sSmellingSaltsDescription[] = _(
    "Afecta a rivales paraliza-\n"
    "dos, pero también los cura.");

static const u8 sFollowMeDescription[] = _(
    "Llama la atención para\n"
    "concentrar los ataques.");

static const u8 sNaturePowerDescription[] = _(
    "El tipo de ataque varía\n"
    "según el sitio.");

static const u8 sChargeDescription[] = _(
    "Recarga energía y sube el\n"
    "ataque eléctrico posterior.");

static const u8 sTauntDescription[] = _(
    "Hace que el rival sólo use\n"
    "ataques.");

static const u8 sHelpingHandDescription[] = _(
    "Refuerza los ataques de un\n"
    "aliado en un combate doble.");

static const u8 sTrickDescription[] = _(
    "Engaña al rival y provoca un\n"
    "cambio de objeto.");

static const u8 sRolePlayDescription[] = _(
    "Imita al rival por completo\n"
    "y copia su habilidad.");

static const u8 sWishDescription[] = _(
    "Lleva tiempo, pero cumple el\n"
    "deseo de restaurar los PS.");

static const u8 sAssistDescription[] = _(
    "Ataque elegido al azar de un\n"
    "miembro del equipo.");

static const u8 sIngrainDescription[] = _(
    "Echa raíces para recuperar\n"
    "PS, pero impide el relevo.");

static const u8 sSuperpowerDescription[] = _(
    "Aumenta mucho la fuerza,\n"
    "pero las habilidades bajan.");

static const u8 sMagicCoatDescription[] = _(
    "El agresor recibe el reflejo\n"
    "de los efectos especiales.");

static const u8 sRecycleDescription[] = _(
    "Recicla un objeto usado\n"
    "para utilizarlo de nuevo.");

static const u8 sRevengeDescription[] = _(
    "Ataque que gana fuerza si el\n"
    "enemigo te hiere.");

static const u8 sBrickBreakDescription[] = _(
    "Destruye barreras como\n"
    "Reflejo y causa daño.");

static const u8 sYawnDescription[] = _(
    "Provoca el bostezo y\n"
    "después el sueño.");

static const u8 sKnockOffDescription[] = _(
    "Deja al rival desprovisto\n"
    "del objeto que lleva.");

static const u8 sEndeavorDescription[] = _(
    "Gana fuerza si el atacante\n"
    "tiene menos PS que el rival.");

static const u8 sEruptionDescription[] = _(
    "Cuanto mayor sea el número\n"
    "de tus PS, más daño harás.");

static const u8 sSkillSwapDescription[] = _(
    "Intercambia la habilidad\n"
    "especial con otro Pokémon.");

static const u8 sImprisonDescription[] = _(
    "Impide al rival usar ataques\n"
    "conocidos por el usuario.");

static const u8 sRefreshDescription[] = _(
    "Cura envenenamientos,\n"
    "parálisis y quemaduras.");

static const u8 sGrudgeDescription[] = _(
    "Si te debilitas, borra los PP\n"
    "del último ataque del rival.");

static const u8 sSnatchDescription[] = _(
    "Roba el efecto del ataque\n"
    "que el objetivo use después.");

static const u8 sSecretPowerDescription[] = _(
    "Los efectos de este ataque\n"
    "varían según la zona.");

static const u8 sDiveDescription[] = _(
    "Primer turno: bucea.\n"
    "Segundo turno: golpea.");

static const u8 sArmThrustDescription[] = _(
    "Se dan puñetazos directos\n"
    "de 2 a 5 veces.");

static const u8 sCamouflageDescription[] = _(
    "Modifica el tipo del Pokémon\n"
    "según la zona donde esté.");

static const u8 sTailGlowDescription[] = _(
    "Ráfaga de luz que sube\n"
    "muchísimo el At. Esp.");

static const u8 sLusterPurgeDescription[] = _(
    "Fogonazo de luz que puede\n"
    "bajar la Defensa Especial.");

static const u8 sMistBallDescription[] = _(
    "Banco de niebla que puede\n"
    "bajar el Ataque Especial.");

static const u8 sFeatherDanceDescription[] = _(
    "Envuelve al rival con plumón\n"
    "para reducir su Ataque.");

static const u8 sTeeterDanceDescription[] = _(
    "Confunde a todos los\n"
    "Pokémon que hay en escena.");

static const u8 sBlazeKickDescription[] = _(
    "Suele ser un golpe crítico y\n"
    "causar quemaduras.");

static const u8 sMudSportDescription[] = _(
    "Te cubre de lodo y mejora tu\n"
    "resistencia eléctrica.");

static const u8 sIceBallDescription[] = _(
    "Dura 5 turnos y gana fuerza\n"
    "en cada uno.");

static const u8 sNeedleArmDescription[] = _(
    "Pega con brazos de pinchos\n"
    "y puede causar retroceso.");

static const u8 sSlackOffDescription[] = _(
    "Te relaja y restaura la\n"
    "mitad de los PS máximos.");

static const u8 sHyperVoiceDescription[] = _(
    "Grito desgarrador que\n"
    "inflige daño al objetivo.");

static const u8 sPoisonFangDescription[] = _(
    "Incisivos colmillos que\n"
    "pueden envenenar al rival.");

static const u8 sCrushClawDescription[] = _(
    "Hace trizas al enemigo y\n"
    "puede bajar la Defensa.");

static const u8 sBlastBurnDescription[] = _(
    "Es muy eficaz, pero te\n"
    "inmoviliza 1 turno.");

static const u8 sHydroCannonDescription[] = _(
    "Es muy eficaz, pero te\n"
    "inmoviliza 1 turno.");

static const u8 sMeteorMashDescription[] = _(
    "Impacta como un meteorito y\n"
    "suele subir el Ataque.");

static const u8 sAstonishDescription[] = _(
    "Impresiona tanto que puede\n"
    "hacer retroceder al rival.");

static const u8 sWeatherBallDescription[] = _(
    "El tipo y fuerza del ataque\n"
    "varían según el clima.");

static const u8 sAromatherapyDescription[] = _(
    "Cura todos los problemas de\n"
    "estado con un suave aroma.");

static const u8 sFakeTearsDescription[] = _(
    "Lágrimas de cocodrilo que\n"
    "bajan mucho la Def. Esp.");

static const u8 sAirCutterDescription[] = _(
    "Viento cortante que azota.\n"
    "Suele ser un golpe crítico.");

static const u8 sOverheatDescription[] = _(
    "Ataque en toda regla que\n"
    "baja mucho tu At. Esp.");

static const u8 sOdorSleuthDescription[] = _(
    "Anula los intentos del rival\n"
    "de aumentar la Evasión.");

static const u8 sRockTombDescription[] = _(
    "Tira rocas que detienen al\n"
    "rival y bajan su Velocidad.");

static const u8 sSilverWindDescription[] = _(
    "Partículas de plata que\n"
    "quizá suban las habilidades.");

static const u8 sMetalSoundDescription[] = _(
    "Tremendo chirrido que baja\n"
    "mucho la Def. Esp.");

static const u8 sGrassWhistleDescription[] = _(
    "Agradable melodía que\n"
    "adormece al objetivo.");

static const u8 sTickleDescription[] = _(
    "Hace reír para bajar el\n"
    "Ataque y la Defensa.");

static const u8 sCosmicPowerDescription[] = _(
    "Energía mística que sube la\n"
    "Defensa y la Def. Esp.");

static const u8 sWaterSpoutDescription[] = _(
    "Si tienes muchos PS, el daño\n"
    "que causa es mucho mayor.");

static const u8 sSignalBeamDescription[] = _(
    "Rayo siniestro de luz. Puede\n"
    "causar confusión.");

static const u8 sShadowPunchDescription[] = _(
    "Puñetazo ineludible\n"
    "procedente de las sombras.");

static const u8 sExtrasensoryDescription[] = _(
    "Energía muy extraña que\n"
    "puede causar el retroceso.");

static const u8 sSkyUppercutDescription[] = _(
    "Gancho ascendente de gran\n"
    "ímpetu.");

static const u8 sSandTombDescription[] = _(
    "Atrapa y daña al rival en\n"
    "arena movediza "BINDING_TURNS" turnos.");

static const u8 sSheerColdDescription[] = _(
    "Ataque polar que debilita al\n"
    "rival si le alcanza.");

static const u8 sMuddyWaterDescription[] = _(
    "Ataque con agua lodosa que\n"
    "puede bajar la Precisión.");

static const u8 sBulletSeedDescription[] = _(
    "Dispara de 2 a 5 ráfagas\n"
    "consecutivas de semillas.");

static const u8 sAerialAceDescription[] = _(
    "El usuario lanza un ataque\n"
    "muy rápido e ineludible.");

static const u8 sIcicleSpearDescription[] = _(
    "Ataca lanzando de 2 a 5\n"
    "ráfagas de carámbanos.");

static const u8 sIronDefenseDescription[] = _(
    "Te fortalece y sube mucho la\n"
    "Defensa.");

static const u8 sBlockDescription[] = _(
    "Le corta el paso al rival\n"
    "para que no pueda escapar.");

static const u8 sHowlDescription[] = _(
    "Aullido que sube el ánimo y\n"
    "aumenta el Ataque.");

static const u8 sDragonClawDescription[] = _(
    "Araña al objetivo con\n"
    "garras afiladas.");

static const u8 sFrenzyPlantDescription[] = _(
    "Es muy eficaz, pero te\n"
    "inmoviliza 1 turno.");

static const u8 sBulkUpDescription[] = _(
    "Robustece el cuerpo para\n"
    "subir Ataque y Defensa.");

static const u8 sBounceDescription[] = _(
    "1.er turno: bota. 2.º:\n"
    "golpea. Puede paralizar.");

static const u8 sMudShotDescription[] = _(
    "Dispara lodo al rival y\n"
    "reduce su Velocidad.");

static const u8 sPoisonTailDescription[] = _(
    "Puede envenenar y dar un\n"
    "golpe crítico.");

static const u8 sCovetDescription[] = _(
    "Pide con ternura al rival el\n"
    "objeto que lleve.");

static const u8 sVoltTackleDescription[] = _(
    "Placaje de alto riesgo que\n"
    "hiere también al atacante.");

static const u8 sMagicalLeafDescription[] = _(
    "Ataca con una extraña hoja\n"
    "que no se puede esquivar.");

static const u8 sWaterSportDescription[] = _(
    "Te moja para que resistas\n"
    "más los ataques de fuego.");

static const u8 sCalmMindDescription[] = _(
    "Sube el At. Esp. y la\n"
    "Def. Esp. con concentración.");

static const u8 sLeafBladeDescription[] = _(
    "Acuchilla con una hoja fina.\n"
    "Suele dar un golpe crítico.");

static const u8 sDragonDanceDescription[] = _(
    "Danza mística que sube el\n"
    "Ataque y la Velocidad.");

static const u8 sRockBlastDescription[] = _(
    "Lanza pedruscos al rival de\n"
    "2 a 5 veces consecutivas.");

static const u8 sShockWaveDescription[] = _(
    "Ataque eléctrico muy rápido\n"
    "e ineludible.");

static const u8 sWaterPulseDescription[] = _(
    "Potente chorro de agua que\n"
    "puede confundir al rival.");

static const u8 sDoomDesireDescription[] = _(
    "Concentra intensa luz solar\n"
    "y ataca 2 turnos después.");

static const u8 sPsychoBoostDescription[] = _(
    "Ataque en toda regla que\n"
    "baja mucho tu At. Esp.");

static const u8 sRoostDescription[] = _(
    "Aterriza para descansar.\n"
    "Recupera la mitad de sus PS.");

static const u8 sGravityDescription[] = _(
    "Anula el vuelo y la\n"
    "levitación 5 turnos.");

static const u8 sMiracleEyeDescription[] = _(
    "Golpea a evasivos y a\n"
    "Pokémon de tipo Siniestro.");

static const u8 sWakeUpSlapDescription[] = _(
    "Gran daño a los dormidos,\n"
    "pero los despierta.");

static const u8 sHammerArmDescription[] = _(
    "Gira el puño y da un gran\n"
    "golpe. Baja la Velocidad.");

static const u8 sGyroBallDescription[] = _(
    "Giro veloz. Cuanto más lento\n"
    "sea el usuario, más daño.");

static const u8 sHealingWishDescription[] = _(
    "Se debilita; su sustituto\n"
    "recupera estado y PS.");

static const u8 sBrineDescription[] = _(
    "Doble de fuerza si al rival\n"
    "le queda media vida.");

static const u8 sNaturalGiftDescription[] = _(
    "Ataca con su baya. Su tipo y\n"
    "fuerza dependen de la baya.");

static const u8 sFeintDescription[] = _(
    "Golpea a quien se proteja y\n"
    "anula su efecto.");

static const u8 sPluckDescription[] = _(
    "Picotea. Si el objetivo\n"
    "lleva baya, la usa él.");

static const u8 sTailwindDescription[] = _(
    "Sube la Velocidad del equipo\n"
    "4 turnos.");

static const u8 sAcupressureDescription[] = _(
    "Presiona puntos clave. Sube\n"
    "mucho una característica.");

static const u8 sMetalBurstDescription[] = _(
    "Devuelve el último ataque\n"
    "recibido con más fuerza.");

static const u8 sUTurnDescription[] = _(
    "Tras atacar, vuelve para\n"
    "dar paso a otro Pokémon.");

static const u8 sCloseCombatDescription[] = _(
    "Lucha sin protegerse. Baja\n"
    "su Defensa y su Def. Esp.");

static const u8 sPaybackDescription[] = _(
    "Doble de fuerza si el\n"
    "objetivo actúa antes.");

static const u8 sAssuranceDescription[] = _(
    "Doble de fuerza si el\n"
    "objetivo ya sufrió daño.");

static const u8 sEmbargoDescription[] = _(
    "El objetivo no puede usar su\n"
    "objeto durante 5 turnos.");

static const u8 sFlingDescription[] = _(
    "Lanza su objeto. Fuerza y\n"
    "efecto según el objeto.");

static const u8 sPsychoShiftDescription[] = _(
    "Pasa al objetivo sus\n"
    "problemas de estado.");

static const u8 sTrumpCardDescription[] = _(
    "Cuantos menos PP le queden,\n"
    "más fuerza tendrá.");

static const u8 sHealBlockDescription[] = _(
    "Impide al objetivo\n"
    "recuperar PS 5 turnos.");

static const u8 sWringOutDescription[] = _(
    "Estruja al rival. Más fuerza\n"
    "cuantos más PS tenga.");

static const u8 sPowerTrickDescription[] = _(
    "Intercambia su Ataque con\n"
    "su Defensa.");

static const u8 sGastroAcidDescription[] = _(
    "Jugos biliares que anulan la\n"
    "habilidad del objetivo.");

static const u8 sLuckyChantDescription[] = _(
    "Protege al equipo de golpes\n"
    "críticos 5 turnos.");

static const u8 sMeFirstDescription[] = _(
    "Usa antes y más fuerte el\n"
    "ataque del rival.");

static const u8 sCopycatDescription[] = _(
    "Imita el movimiento usado\n"
    "justo antes.");

static const u8 sPowerSwapDescription[] = _(
    "Intercambia cambios de\n"
    "Ataque y At. Esp. con él.");

static const u8 sGuardSwapDescription[] = _(
    "Intercambia cambios de Def.\n"
    "y Def. Esp. con él.");

static const u8 sPunishmentDescription[] = _(
    "Más fuerza cuanto más haya\n"
    "mejorado el objetivo.");

static const u8 sLastResortDescription[] = _(
    "Solo puede usarse tras usar\n"
    "sus otros movimientos.");

static const u8 sWorrySeedDescription[] = _(
    "Planta una semilla: su\n"
    "habilidad pasa a Insomnio.");

static const u8 sSuckerPunchDescription[] = _(
    "Prioridad. Falla si el\n"
    "objetivo no va a atacar.");

static const u8 sToxicSpikesDescription[] = _(
    "Esparce púas tóxicas que\n"
    "envenenan al que entre.");

static const u8 sHeartSwapDescription[] = _(
    "Intercambia con él los\n"
    "cambios de características.");

static const u8 sAquaRingDescription[] = _(
    "Un manto de agua le cura\n"
    "algunos PS cada turno.");

static const u8 sMagnetRiseDescription[] = _(
    "Levita gracias a un campo\n"
    "magnético durante 5 turnos.");

static const u8 sFlareBlitzDescription[] = _(
    "Carga en llamas. También se\n"
    "daña. Puede quemar.");

static const u8 sForcePalmDescription[] = _(
    "Ataca con una onda de\n"
    "choque. Puede paralizar.");

static const u8 sAuraSphereDescription[] = _(
    "Libera una inmensa descarga\n"
    "de aura. Es infalible.");

static const u8 sRockPolishDescription[] = _(
    "Pule su cuerpo y aumenta\n"
    "mucho la Velocidad.");

static const u8 sPoisonJabDescription[] = _(
    "Pincha con un tentáculo\n"
    "venenoso. Puede envenenar.");

static const u8 sDarkPulseDescription[] = _(
    "Aura horrible que puede\n"
    "amedrentar.");

static const u8 sNightSlashDescription[] = _(
    "Ataca a la primera ocasión.\n"
    "Suele ser crítico.");

static const u8 sAquaTailDescription[] = _(
    "Ataca agitando la cola como\n"
    "una ola rabiosa.");

static const u8 sSeedBombDescription[] = _(
    "Descarga de semillas\n"
    "explosivas desde arriba.");

static const u8 sAirSlashDescription[] = _(
    "Viento afilado que corta el\n"
    "aire. Puede amedrentar.");

static const u8 sXScissorDescription[] = _(
    "Cruza guadañas o garras\n"
    "como si fueran tijeras.");

static const u8 sBugBuzzDescription[] = _(
    "Onda sónica dañina. Puede\n"
    "bajar la Def. Esp.");

static const u8 sDragonPulseDescription[] = _(
    "Abre la boca y libera una\n"
    "onda de choque.");

static const u8 sDragonRushDescription[] = _(
    "Ataque brutal e intimidante.\n"
    "Puede amedrentar.");

static const u8 sPowerGemDescription[] = _(
    "Rayo de luz que centellea\n"
    "como miles de joyas.");

static const u8 sVacuumWaveDescription[] = _(
    "Onda de vacío con los puños.\n"
    "Prioridad alta.");

static const u8 sFocusBlastDescription[] = _(
    "Concentra su mente. Puede\n"
    "bajar la Def. Esp.");

static const u8 sEnergyBallDescription[] = _(
    "Fuerza de la naturaleza.\n"
    "Puede bajar la Def. Esp.");

static const u8 sBraveBirdDescription[] = _(
    "Ataca con un vuelo rasante.\n"
    "El usuario se daña mucho.");

static const u8 sEarthPowerDescription[] = _(
    "La tierra erupciona. Puede\n"
    "bajar la Def. Esp.");

static const u8 sSwitcherooDescription[] = _(
    "Intercambia objetos con el\n"
    "objetivo al instante.");

static const u8 sNastyPlotDescription[] = _(
    "Piensa en cosas malas y\n"
    "aumenta mucho el At. Esp.");

static const u8 sBulletPunchDescription[] = _(
    "Puñetazos rápidos como\n"
    "proyectiles. Prioridad alta.");

static const u8 sIceShardDescription[] = _(
    "Lanza bolas de hielo a gran\n"
    "velocidad. Prioridad alta.");

static const u8 sShadowClawDescription[] = _(
    "Garra afilada de sombras.\n"
    "Suele ser crítico.");

static const u8 sThunderFangDescription[] = _(
    "Colmillos eléctricos. Puede\n"
    "amedrentar o paralizar.");

static const u8 sIceFangDescription[] = _(
    "Colmillos helados. Puede\n"
    "amedrentar o congelar.");

static const u8 sFireFangDescription[] = _(
    "Colmillos en llamas. Puede\n"
    "amedrentar o quemar.");

static const u8 sShadowSneakDescription[] = _(
    "Ataca por la espalda con su\n"
    "sombra. Prioridad alta.");

static const u8 sMudBombDescription[] = _(
    "Lanza una bola de fango.\n"
    "Puede bajar la Precisión.");

static const u8 sPsychoCutDescription[] = _(
    "Cuchillas de energía\n"
    "psíquica. Suele ser crítico.");

static const u8 sZenHeadbuttDescription[] = _(
    "Cabezazo con energía\n"
    "psíquica. Puede amedrentar.");

static const u8 sMirrorShotDescription[] = _(
    "Haz de energía de su cuerpo.\n"
    "Puede bajar la Precisión.");

static const u8 sFlashCannonDescription[] = _(
    "Libera la luz de su cuerpo.\n"
    "Puede bajar la Def. Esp.");

static const u8 sRockClimbDescription[] = _(
    "Ataca con una gran\n"
    "embestida. Puede confundir.");

static const u8 sDefogDescription[] = _(
    "Barre Reflejo y Pantalla de\n"
    "Luz. Baja la Evasión.");

static const u8 sTrickRoomDescription[] = _(
    "5 turnos: los Pokémon lentos\n"
    "se mueven primero.");

static const u8 sDracoMeteorDescription[] = _(
    "Hace caer cometas. Baja\n"
    "mucho su propio At. Esp.");

static const u8 sDischargeDescription[] = _(
    "Onda eléctrica a su\n"
    "alrededor. Puede paralizar.");

static const u8 sPowerWhipDescription[] = _(
    "Golpea agitando sus lianas o\n"
    "tentáculos.");

static const u8 sCrossPoisonDescription[] = _(
    "Tajo que puede envenenar al\n"
    "objetivo. Suele ser crítico.");

static const u8 sGunkShotDescription[] = _(
    "Lanza basura asquerosa.\n"
    "Puede envenenar.");

static const u8 sIronHeadDescription[] = _(
    "Ataca con su dura cabeza de\n"
    "hierro. Puede amedrentar.");

static const u8 sMagnetBombDescription[] = _(
    "Bombas de hierro que se\n"
    "pegan. No falla.");

static const u8 sStoneEdgeDescription[] = _(
    "Clava piedras muy afiladas\n"
    "al rival. Suele ser crítico.");

static const u8 sCaptivateDescription[] = _(
    "Si es del sexo opuesto, baja\n"
    "mucho su At. Esp.");

static const u8 sStealthRockDescription[] = _(
    "Rocas flotantes que dañan a\n"
    "los objetivos que entran.");

static const u8 sGrassKnotDescription[] = _(
    "Enreda y derriba con hierba.\n"
    "Más daño si pesa más.");

static const u8 sChatterDescription[] = _(
    "Onda sonora hecha de\n"
    "palabras que confunde.");

static const u8 sJudgmentDescription[] = _(
    "Haces de luz. Su tipo varía\n"
    "según la tabla.");

static const u8 sChargeBeamDescription[] = _(
    "Rayo eléctrico. Puede subir\n"
    "su At. Esp.");

static const u8 sWoodHammerDescription[] = _(
    "Arremete con su cuerpo. Él\n"
    "también se daña.");

static const u8 sAquaJetDescription[] = _(
    "Ataque rápido que permite\n"
    "golpear en primer lugar.");

static const u8 sAttackOrderDescription[] = _(
    "Sus súbditos atacan al\n"
    "objetivo. Suele ser crítico.");

static const u8 sDefendOrderDescription[] = _(
    "Sus súbditos lo protegen.\n"
    "Sube Def. y Def. Esp.");

static const u8 sHealOrderDescription[] = _(
    "Sus súbditos lo curan.\n"
    "Recupera la mitad de sus PS.");

static const u8 sHeadSmashDescription[] = _(
    "Cabezazo con toda su\n"
    "fuerza. Se daña mucho.");

static const u8 sDoubleHitDescription[] = _(
    "Golpea dos veces seguidas\n"
    "con la cola.");

static const u8 sRoarOfTimeDescription[] = _(
    "Es muy eficaz, pero te\n"
    "inmoviliza 1 turno.");

static const u8 sSpacialRendDescription[] = _(
    "Desgarra al objetivo y el\n"
    "espacio. Suele ser crítico.");

static const u8 sMagmaStormDescription[] = _(
    "Lo atrapa en un vórtice\n"
    "de fuego "BINDING_TURNS" turnos.");

static const u8 sDarkVoidDescription[] = _(
    "Envía al objetivo a un mundo\n"
    "de tinieblas y lo duerme.");

static const u8 sSeedFlareDescription[] = _(
    "Onda de choque. Puede bajar\n"
    "mucho la Def. Esp.");

static const u8 sOminousWindDescription[] = _(
    "Viento horripilante. Puede\n"
    "subir todo.");

static const u8 sShadowForceDescription[] = _(
    "Desaparece y luego golpea\n"
    "aunque se protejan.");

static const u8 sHoneClawsDescription[] = _(
    "Se afila las garras y sube\n"
    "su Ataque y Precisión.");

static const u8 sWideGuardDescription[] = _(
    "Bloquea los ataques de área\n"
    "contra el equipo un turno.");

static const u8 sGuardSplitDescription[] = _(
    "Promedia sus defensas con\n"
    "las del objetivo.");

static const u8 sPowerSplitDescription[] = _(
    "Hace la media de su Ataque y\n"
    "At. Esp. con el objetivo.");

static const u8 sWonderRoomDescription[] = _(
    "Intercambia Defensa y\n"
    "Def. Esp. de todos 5 turnos.");

static const u8 sPsyshockDescription[] = _(
    "Crea una onda psíquica que\n"
    "causa daño físico.");

static const u8 sTailSlapDescription[] = _(
    "Golpea con la cola de dos a\n"
    "cinco veces seguidas.");

static const u8 sVenoshockDescription[] = _(
    "Líquido venenoso. Hace el\n"
    "doble si ya está envenenado.");

static const u8 sAutotomizeDescription[] = _(
    "Se desprende de peso y\n"
    "aumenta mucho la Velocidad.");

static const u8 sRagePowderDescription[] = _(
    "Polvo irritante que atrae\n"
    "hacia él los ataques.");

static const u8 sTelekinesisDescription[] = _(
    "Hace flotar al objetivo y es\n"
    "un blanco fácil 3 turnos.");

static const u8 sMagicRoomDescription[] = _(
    "Inutiliza los objetos de\n"
    "todos durante 5 turnos.");

static const u8 sSmackDownDescription[] = _(
    "Lanza una piedra. Si el\n"
    "objetivo vuela, lo derriba.");

static const u8 sStormThrowDescription[] = _(
    "Golpe devastador. Siempre\n"
    "es un golpe crítico.");

static const u8 sFlameBurstDescription[] = _(
    "Llamarada que también\n"
    "afecta a los adyacentes.");

static const u8 sSludgeWaveDescription[] = _(
    "Onda tóxica que daña a los\n"
    "de alrededor. Envenena.");

static const u8 sQuiverDanceDescription[] = _(
    "Sube At. Esp., Def. Esp. y\n"
    "Velocidad.");

static const u8 sHeavySlamDescription[] = _(
    "Golpe corporal. Más daño si\n"
    "pesa más que el rival.");

static const u8 sSynchronoiseDescription[] = _(
    "Onda extraña que daña a los\n"
    "adyacentes de su mismo tipo.");

static const u8 sElectroBallDescription[] = _(
    "Bola eléctrica. Más daño si\n"
    "es más rápido.");

static const u8 sSoakDescription[] = _(
    "Potente lluvia que vuelve al\n"
    "objetivo de tipo Agua.");

static const u8 sFlameChargeDescription[] = _(
    "Llamas que golpean y suben\n"
    "la Velocidad del usuario.");

static const u8 sCoilDescription[] = _(
    "Se concentra y sube su\n"
    "Ataque, Defensa y Precisión.");

static const u8 sLowSweepDescription[] = _(
    "Ataque rápido a los pies que\n"
    "baja la Velocidad.");

static const u8 sAcidSprayDescription[] = _(
    "Líquido corrosivo. Baja\n"
    "mucho la Def. Esp.");

static const u8 sFoulPlayDescription[] = _(
    "Usa la fuerza del rival: más\n"
    "daño si su Ataque es alto.");

static const u8 sSimpleBeamDescription[] = _(
    "Onda psíquica: la habilidad\n"
    "del rival pasa a Simple.");

static const u8 sEntrainmentDescription[] = _(
    "Danza extraña: el objetivo\n"
    "copia su habilidad.");

static const u8 sAfterYouDescription[] = _(
    "Si es el más rápido, el\n"
    "objetivo actúa tras él.");

static const u8 sRoundDescription[] = _(
    "Canto que gana potencia si\n"
    "otros lo usan también.");

static const u8 sEchoedVoiceDescription[] = _(
    "Susurro que gana potencia\n"
    "al usarlo otros Pokémon.");

static const u8 sChipAwayDescription[] = _(
    "Ignora los cambios de\n"
    "características del rival.");

static const u8 sClearSmogDescription[] = _(
    "Bola de lodo que anula los\n"
    "cambios de características.");

static const u8 sStoredPowerDescription[] = _(
    "Más daño cuanto más hayan\n"
    "subido sus características.");

static const u8 sQuickGuardDescription[] = _(
    "Protege a su equipo de los\n"
    "movimientos con prioridad.");

static const u8 sAllySwitchDescription[] = _(
    "Intercambia su posición con\n"
    "la de un aliado.");

static const u8 sScaldDescription[] = _(
    "Arroja agua hirviendo.\n"
    "Puede quemar.");

static const u8 sShellSmashDescription[] = _(
    "Baja sus defensas y sube\n"
    "mucho Ataque, At. Esp. y Vel.");

static const u8 sHealPulseDescription[] = _(
    "Onda curativa: recupera la\n"
    "mitad de PS del objetivo.");

static const u8 sHexDescription[] = _(
    "Gran daño a objetivos con\n"
    "problemas de estado.");

static const u8 sSkyDropDescription[] = _(
    "Lanza al rival al aire y lo\n"
    "hace caer después.");

static const u8 sShiftGearDescription[] = _(
    "Gira los engranajes. Sube\n"
    "Ataque y mucho la Velocidad.");

static const u8 sCircleThrowDescription[] = _(
    "Lanza por los aires al rival\n"
    "y lo obliga a cambiarse.");

static const u8 sIncinerateDescription[] = _(
    "Llamas que queman las bayas\n"
    "del objetivo.");

static const u8 sQuashDescription[] = _(
    "Consigue que el objetivo\n"
    "sea el último en moverse.");

static const u8 sAcrobaticsDescription[] = _(
    "Golpe ágil. Mucho daño si el\n"
    "usuario no lleva objeto.");

static const u8 sReflectTypeDescription[] = _(
    "Adopta el mismo tipo que el\n"
    "objetivo.");

static const u8 sRetaliateDescription[] = _(
    "Venga a los caídos. Más\n"
    "fuerte si cayó un aliado.");

static const u8 sFinalGambitDescription[] = _(
    "Se sacrifica y causa daño\n"
    "igual a sus PS.");

static const u8 sBestowDescription[] = _(
    "Da su objeto al objetivo si\n"
    "este no lleva ninguno.");

static const u8 sInfernoDescription[] = _(
    "Gran ráfaga de fuego que\n"
    "causa quemaduras.");

static const u8 sWaterPledgeDescription[] = _(
    "Columnas de agua. Con Voto\n"
    "Fuego, crea un arcoíris.");

static const u8 sFirePledgeDescription[] = _(
    "Columnas de fuego. Con Voto\n"
    "Planta, mar de llamas.");

static const u8 sGrassPledgeDescription[] = _(
    "Columnas de hojas. Con Voto\n"
    "Agua, crea un pantano.");

static const u8 sStruggleBugDescription[] = _(
    "Resiste y ataca. Baja el\n"
    "At. Esp. de los rivales.");

static const u8 sBulldozeDescription[] = _(
    "Sacudida sísmica. Baja la\n"
    "Velocidad de los de al lado.");

static const u8 sWorkUpDescription[] = _(
    "Se concentra y sube su\n"
    "Ataque y At. Esp.");

static const u8 sElectrowebDescription[] = _(
    "Telaraña eléctrica. Baja la\n"
    "Velocidad de los rivales.");

static const u8 sWildChargeDescription[] = _(
    "Potente carga eléctrica. Él\n"
    "también se daña un poco.");

static const u8 sDrillRunDescription[] = _(
    "Golpea girando como un\n"
    "taladro. Suele ser crítico.");

static const u8 sDualChopDescription[] = _(
    "Golpea dos veces con sus\n"
    "partes más duras.");

static const u8 sHeartStampDescription[] = _(
    "Despista con monerías y\n"
    "golpea. Puede amedrentar.");

static const u8 sRazorShellDescription[] = _(
    "Una afilada vieira ataca.\n"
    "Puede bajar la Defensa.");

static const u8 sLeafTornadoDescription[] = _(
    "Tritura con hojas afiladas.\n"
    "Puede bajar la Precisión.");

static const u8 sSteamrollerDescription[] = _(
    "Arrolla hecho una bola.\n"
    "Puede hacer retroceder.");

static const u8 sCottonGuardDescription[] = _(
    "Se cubre de algodón. Sube\n"
    "muchísimo la Defensa.");

static const u8 sNightDazeDescription[] = _(
    "Onda siniestra. Puede bajar\n"
    "la Precisión.");

static const u8 sHurricaneDescription[] = _(
    "Torbellino que envuelve al\n"
    "rival. Puede confundirlo.");

static const u8 sHeadChargeDescription[] = _(
    "Tremendo cabezazo. También\n"
    "daña un poco al usuario.");

static const u8 sGearGrindDescription[] = _(
    "Dos engranajes de hierro\n"
    "que golpean dos veces.");

static const u8 sTechnoBlastDescription[] = _(
    "Gran láser. Su tipo depende\n"
    "del disco que lleve.");

static const u8 sRelicSongDescription[] = _(
    "Antiguo canto que conmueve.\n"
    "Puede dormir a los rivales.");

static const u8 sSecretSwordDescription[] = _(
    "Cuerno largo con poder\n"
    "místico. Causa daño físico.");

static const u8 sGlaciateDescription[] = _(
    "Aire helado que baja la\n"
    "Velocidad del objetivo.");

static const u8 sBoltStrikeDescription[] = _(
    "Embiste con una gran carga\n"
    "eléctrica. Puede paralizar.");

static const u8 sBlueFlareDescription[] = _(
    "Bella pero potente llama\n"
    "azul. Puede quemar.");

static const u8 sFieryDanceDescription[] = _(
    "Envuelve en llamas. Puede\n"
    "subir el At. Esp. propio.");

static const u8 sFreezeShockDescription[] = _(
    "Hielo con electricidad.\n"
    "Puede paralizar.");

static const u8 sIceBurnDescription[] = _(
    "Ataca en el 2.º turno con\n"
    "aire gélido. Puede quemar.");

static const u8 sSnarlDescription[] = _(
    "Chillido desagradable que\n"
    "baja el At. Esp. del rival.");

static const u8 sIcicleCrashDescription[] = _(
    "Lanza grandes carámbanos.\n"
    "Puede amedrentar.");

static const u8 sVCreateDescription[] = _(
    "Llamas en V. Baja su Def.,\n"
    "Def. Esp. y Velocidad.");

static const u8 sFusionFlareDescription[] = _(
    "Llamarada gigante. Más\n"
    "fuerte tras una descarga.");

static const u8 sFusionBoltDescription[] = _(
    "Gran descarga. Más fuerte\n"
    "tras una gran llamarada.");

static const u8 sFlyingPressDescription[] = _(
    "Se lanza sobre el rival. Es\n"
    "de tipo Lucha y Volador.");

static const u8 sMatBlockDescription[] = _(
    "Se escuda con un tatami\n"
    "junto a sus aliados.");

static const u8 sBelchDescription[] = _(
    "Lanza un eructo. Antes debe\n"
    "comerse una baya.");

static const u8 sRototillerDescription[] = _(
    "Labra la tierra. Sube Ataque\n"
    "y At. Esp. de los Planta.");

static const u8 sStickyWebDescription[] = _(
    "Red pegajosa que frena a\n"
    "los rivales que entren.");

static const u8 sFellStingerDescription[] = _(
    "Si derrota al objetivo, sube\n"
    "muchísimo el Ataque.");

static const u8 sTrickOrTreatDescription[] = _(
    "Invita a celebrar Halloween:\n"
    "añade el tipo Fantasma.");

static const u8 sNobleRoarDescription[] = _(
    "Rugido de guerra que baja\n"
    "Ataque y At. Esp. del rival.");

static const u8 sIonDelugeDescription[] = _(
    "Los ataques Normal pasan a\n"
    "ser Eléctrico.");

static const u8 sParabolicChargeDescription[] = _(
    "Daña a los de alrededor y\n"
    "absorbe la mitad.");

static const u8 sForestsCurseDescription[] = _(
    "Maldición del bosque: el\n"
    "objetivo pasa a ser Planta.");

static const u8 sPetalBlizzardDescription[] = _(
    "Vendaval de pétalos que\n"
    "daña a los de alrededor.");

static const u8 sFreezeDryDescription[] = _(
    "Puede congelar. Muy eficaz\n"
    "contra el tipo Agua.");

static const u8 sDisarmingVoiceDescription[] = _(
    "Voz fascinante que siempre\n"
    "acierta.");

static const u8 sPartingShotDescription[] = _(
    "Baja Ataque y At. Esp. del\n"
    "rival y se cambia.");

static const u8 sTopsyTurvyDescription[] = _(
    "Invierte los cambios de\n"
    "características del rival.");

static const u8 sDrainingKissDescription[] = _(
    "Absorbe PS con un beso y se\n"
    "cura con ellos.");

static const u8 sCraftyShieldDescription[] = _(
    "Protege a su equipo de los\n"
    "movimientos de estado.");

static const u8 sFlowerShieldDescription[] = _(
    "Sube la Defensa de todos los\n"
    "Pokémon de tipo Planta.");

static const u8 sGrassyTerrainDescription[] = _(
    "5 turnos: potencia Planta y\n"
    "cura a los del suelo.");

static const u8 sMistyTerrainDescription[] = _(
    "5 turnos: los del suelo no\n"
    "sufren estados.");

static const u8 sElectrifyDescription[] = _(
    "El próximo movimiento del\n"
    "objetivo será Eléctrico.");

static const u8 sPlayRoughDescription[] = _(
    "Hace cucamonas y ataca.\n"
    "Puede bajar el Ataque.");

static const u8 sFairyWindDescription[] = _(
    "Desata un vendaval feérico\n"
    "contra el objetivo.");

static const u8 sMoonblastDescription[] = _(
    "Poder de la luna. Puede\n"
    "bajar el At. Esp. del rival.");

static const u8 sBoomburstDescription[] = _(
    "Onda sonora que ataca a\n"
    "todos a su alrededor.");

static const u8 sFairyLockDescription[] = _(
    "Echa un cerrojo: nadie\n"
    "podrá huir el próximo turno.");

static const u8 sKingsShieldDescription[] = _(
    "Se protege y baja el Ataque\n"
    "de quien le toque.");

static const u8 sPlayNiceDescription[] = _(
    "Se hace amigo del rival y\n"
    "baja su Ataque.");

static const u8 sConfideDescription[] = _(
    "Le cuenta un secreto al\n"
    "rival y baja su At. Esp.");

static const u8 sDiamondStormDescription[] = _(
    "Vendaval de diamantes.\n"
    "Puede subir la Defensa.");

static const u8 sSteamEruptionDescription[] = _(
    "Vapor muy caliente que\n"
    "puede quemar al rival.");

static const u8 sHyperspaceHoleDescription[] = _(
    "Ataca desde otra dimensión.\n"
    "Atraviesa Protección.");

static const u8 sWaterShurikenDescription[] = _(
    "Estrellas de mucosidad de 2\n"
    "a 5 veces. Prioridad alta.");

static const u8 sMysticalFireDescription[] = _(
    "Llama singular muy caliente.\n"
    "Baja el At. Esp.");

static const u8 sSpikyShieldDescription[] = _(
    "Se protege y daña a quien le\n"
    "ataque por contacto.");

static const u8 sAromaticMistDescription[] = _(
    "Fragancia que sube la\n"
    "Def. Esp. de un aliado.");

static const u8 sEerieImpulseDescription[] = _(
    "Ondas raras que bajan mucho\n"
    "el At. Esp. del rival.");

static const u8 sVenomDrenchDescription[] = _(
    "Baja Ataque, At. Esp. y Vel.\n"
    "de rivales envenenados.");

static const u8 sPowderDescription[] = _(
    "Polvo que explota si el\n"
    "rival usa un ataque Fuego.");

static const u8 sGeomancyDescription[] = _(
    "Carga un turno y sube mucho\n"
    "At. Esp., Def. Esp. y Vel.");

static const u8 sMagneticFluxDescription[] = _(
    "Sube las defensas de\n"
    "aliados con Más o Menos.");

static const u8 sHappyHourDescription[] = _(
    "Duplica la recompensa\n"
    "recibida tras el combate.");

static const u8 sElectricTerrainDescription[] = _(
    "5 turnos: potencia\n"
    "Eléctrico y nadie se duerme.");

static const u8 sDazzlingGleamDescription[] = _(
    "Inflige daño a los oponentes\n"
    "con una potente luz.");

static const u8 sCelebrateDescription[] = _(
    "El Pokémon te felicita en un\n"
    "día muy especial para ti.");

static const u8 sHoldHandsDescription[] = _(
    "Da la mano a un aliado y\n"
    "ambos se sienten felices.");

static const u8 sBabyDollEyesDescription[] = _(
    "Mirada acaramelada que baja\n"
    "el Ataque. Prioridad alta.");

static const u8 sNuzzleDescription[] = _(
    "Frota sus mofletes\n"
    "eléctricos y paraliza.");

static const u8 sInfestationDescription[] = _(
    "Infesta al rival y lo ataca\n"
    "durante "BINDING_TURNS" turnos.");

static const u8 sPowerUpPunchDescription[] = _(
    "Sus puños se endurecen al\n"
    "golpear. Sube su Ataque.");

static const u8 sThousandArrowsDescription[] = _(
    "Acierta a los Pokémon en el\n"
    "aire y los hace caer.");

static const u8 sThousandWavesDescription[] = _(
    "Ondas sísmicas. Los\n"
    "alcanzados no podrán huir.");

static const u8 sLandsWrathDescription[] = _(
    "Concentra la energía de la\n"
    "tierra contra los rivales.");

static const u8 sLightOfRuinDescription[] = _(
    "Rayo de la Flor Eterna. El\n"
    "usuario sufre mucho daño.");

static const u8 sOriginPulseDescription[] = _(
    "Infinidad de rayos de luz\n"
    "azulada contra el objetivo.");

static const u8 sPrecipiceBladesDescription[] = _(
    "Hojas afiladas con el poder\n"
    "latente de la tierra.");

static const u8 sLavaPlumeDescription[] = _(
    "Infierno de llamas a su\n"
    "alrededor. Puede quemar.");

static const u8 sLeafStormDescription[] = _(
    "Lluvia de hojas afiladas.\n"
    "Baja mucho su At. Esp.");

static const u8 sShoreUpDescription[] = _(
    "Cura la mitad de sus PS. Más\n"
    "en tormenta de arena.");

static const u8 sFirstImpressionDescription[] = _(
    "Muy potente, pero solo el\n"
    "turno en que sale.");

static const u8 sBanefulBunkerDescription[] = _(
    "Se protege y envenena a\n"
    "quien le toque.");

static const u8 sSpiritShackleDescription[] = _(
    "Ataca y fija su sombra para\n"
    "que el rival no huya.");

static const u8 sDarkestLariatDescription[] = _(
    "Golpe giratorio que ignora\n"
    "los cambios del rival.");

static const u8 sSparklingAriaDescription[] = _(
    "Canta con burbujas. Cura\n"
    "las quemaduras al dañar.");

static const u8 sIceHammerDescription[] = _(
    "Terrible puñetazo. Baja la\n"
    "Velocidad del usuario.");

static const u8 sFloralHealingDescription[] = _(
    "Cura media vida al objetivo.\n"
    "Más con Campo de Hierba.");

static const u8 sHighHorsepowerDescription[] = _(
    "Asesta un golpe devastador\n"
    "usando todo su cuerpo.");

static const u8 sStrengthSapDescription[] = _(
    "Cura PS según el Ataque del\n"
    "rival y se lo baja.");

static const u8 sSolarBladeDescription[] = _(
    "Absorbe luz un turno y\n"
    "ataca con una hoja de luz.");

static const u8 sLeafageDescription[] = _(
    "Ataca al oponente lanzando\n"
    "hojas.");

static const u8 sSpotlightDescription[] = _(
    "Pone a un Pokémon en el\n"
    "foco: todos le atacarán.");

static const u8 sToxicThreadDescription[] = _(
    "Hilos venenosos: envenena y\n"
    "baja la Velocidad.");

static const u8 sLaserFocusDescription[] = _(
    "Se concentra: su siguiente\n"
    "ataque será crítico.");

static const u8 sGearUpDescription[] = _(
    "Sube Ataque y At. Esp. de\n"
    "aliados con Más o Menos.");

static const u8 sThroatChopDescription[] = _(
    "Dolor abrumador: impide\n"
    "usar sonidos 2 turnos.");

static const u8 sPollenPuffDescription[] = _(
    "Bola explosiva. Si alcanza a\n"
    "un aliado, le cura PS.");

static const u8 sAnchorShotDescription[] = _(
    "Lanza un ancla que atrapa al\n"
    "rival y le impide huir.");

static const u8 sPsychicTerrainDescription[] = _(
    "5 turnos: potencia Psíquico\n"
    "y protege de la prioridad.");

static const u8 sLungeDescription[] = _(
    "Se abalanza con todas sus\n"
    "fuerzas y baja el Ataque.");

static const u8 sFireLashDescription[] = _(
    "Látigo incandescente que\n"
    "baja la Defensa del rival.");

static const u8 sPowerTripDescription[] = _(
    "Presume de fuerza: más daño\n"
    "cuanto más haya mejorado.");

static const u8 sBurnUpDescription[] = _(
    "Usa todas sus llamas y deja\n"
    "de ser de tipo Fuego.");

static const u8 sSpeedSwapDescription[] = _(
    "Intercambia su Velocidad\n"
    "por la del oponente.");

static const u8 sSmartStrikeDescription[] = _(
    "Ensarta con su afilada\n"
    "cornamenta. No falla.");

static const u8 sPurifyDescription[] = _(
    "Cura el estado del rival y\n"
    "recupera PS propios.");

static const u8 sRevelationDanceDescription[] = _(
    "Baile enérgico. Su tipo es el\n"
    "del usuario.");

static const u8 sCoreEnforcerDescription[] = _(
    "Si el rival ya se ha movido,\n"
    "pierde su habilidad.");

static const u8 sTropKickDescription[] = _(
    "Patada con la fuerza del\n"
    "trópico. Baja el Ataque.");

static const u8 sInstructDescription[] = _(
    "Obliga al objetivo a repetir\n"
    "su último movimiento.");

static const u8 sBeakBlastDescription[] = _(
    "Calienta el pico y ataca.\n"
    "Quema a quien le toque.");

static const u8 sClangingScalesDescription[] = _(
    "Frota sus escamas y ataca.\n"
    "Luego baja su Defensa.");

static const u8 sDragonHammerDescription[] = _(
    "Se abalanza usando el\n"
    "cuerpo como un martillo.");

static const u8 sBrutalSwingDescription[] = _(
    "Hace pivotar su cuerpo para\n"
    "causar daño a su alrededor.");

static const u8 sAuroraVeilDescription[] = _(
    "5 turnos: reduce el daño\n"
    "recibido. Solo con granizo.");

static const u8 sShellTrapDescription[] = _(
    "Coraza trampa: estalla si\n"
    "recibe un ataque físico.");

static const u8 sFleurCannonDescription[] = _(
    "Potente rayo. Baja mucho su\n"
    "At. Esp.");

static const u8 sPsychicFangsDescription[] = _(
    "Rompe Pantalla de Luz y\n"
    "Reflejo con su mente.");

static const u8 sStompingTantrumDescription[] = _(
    "Pisotea con rabia. Doble si\n"
    "su último ataque falló.");

static const u8 sShadowBoneDescription[] = _(
    "Hueso poseído. Puede bajar\n"
    "la Defensa.");

static const u8 sAccelerockDescription[] = _(
    "Se lanza a gran velocidad.\n"
    "Prioridad alta.");

static const u8 sLiquidationDescription[] = _(
    "Golpea con fuerza acuática.\n"
    "Puede bajar la Defensa.");

static const u8 sPrismaticLaserDescription[] = _(
    "Rayo potente con un prisma.\n"
    "Luego no puede moverse.");

static const u8 sSpectralThiefDescription[] = _(
    "Roba las mejoras del\n"
    "objetivo y le ataca.");

static const u8 sSunsteelStrikeDescription[] = _(
    "Potencia de un meteoro que\n"
    "ignora la habilidad rival.");

static const u8 sMoongeistBeamDescription[] = _(
    "Rayo misterioso que ignora\n"
    "la habilidad del objetivo.");

static const u8 sTearfulLookDescription[] = _(
    "Ojos llorosos: baja el\n"
    "Ataque y At. Esp. del rival.");

static const u8 sZingZapDescription[] = _(
    "Potente descarga eléctrica.\n"
    "Puede amedrentar.");

static const u8 sNaturesMadnessDescription[] = _(
    "La furia de la naturaleza\n"
    "reduce sus PS a la mitad.");

static const u8 sMultiAttackDescription[] = _(
    "Energía potente. Su tipo\n"
    "depende del disco que lleve.");

static const u8 sMindBlownDescription[] = _(
    "Hace explotar su cabeza.\n"
    "Daña a todos y a sí mismo.");

static const u8 sPlasmaFistsDescription[] = _(
    "Puños eléctricos. Normal\n"
    "pasa a ser Eléctrico.");

static const u8 sPhotonGeyserDescription[] = _(
    "Columna de luz. Físico o\n"
    "especial, el más alto.");

static const u8 sZippyZapDescription[] = _(
    "Rayo que ataca primero.\n"
    "Sube la Evasión.");

static const u8 sSplishySplashDescription[] = _(
    "Ola gigante electrificada.\n"
    "Puede paralizar.");

static const u8 sFloatyFallDescription[] = _(
    "Se suspende en el aire y\n"
    "cae. Puede amedrentar.");

static const u8 sPikaPapowDescription[] = _(
    "Infalible. Más fuerte cuanto\n"
    "más cariño tenga.");

static const u8 sBouncyBubbleDescription[] = _(
    "Burbujas que absorben todo\n"
    "el daño causado.");

static const u8 sBuzzyBuzzDescription[] = _(
    "Potente descarga eléctrica\n"
    "que paraliza al rival.");

static const u8 sSizzlySlideDescription[] = _(
    "Arrolla envuelto en llamas y\n"
    "quema al rival.");

static const u8 sGlitzyGlowDescription[] = _(
    "Ondas psíquicas y un muro\n"
    "contra ataques especiales.");

static const u8 sBaddyBadDescription[] = _(
    "Ataque umbrío y un muro\n"
    "contra ataques físicos.");

static const u8 sSappySeedDescription[] = _(
    "Un tallo gigante lanza\n"
    "semillas que drenan PS.");

static const u8 sFreezyFrostDescription[] = _(
    "Cristales de niebla helada\n"
    "que anulan los cambios.");

static const u8 sSparklySwirlDescription[] = _(
    "Aroma asfixiante. Cura el\n"
    "estado de sus aliados.");

static const u8 sVeeveeVolleyDescription[] = _(
    "Placaje infalible. Más\n"
    "fuerte cuanto más le quiera.");

static const u8 sDoubleIronBashDescription[] = _(
    "Gira y golpea dos veces.\n"
    "Puede amedrentar.");

// GEN 8
static const u8 sDynamaxCannonDescription[] = _(
    "Rayo de su núcleo. Doble\n"
    "daño a rivales Dinamax.");

static const u8 sSnipeShotDescription[] = _(
    "Ignora los efectos que\n"
    "atraen los ataques.");

static const u8 sJawLockDescription[] = _(
    "Ni atacante ni defensor\n"
    "podrán ser cambiados.");

static const u8 sStuffCheeksDescription[] = _(
    "Se come su baya y aumenta\n"
    "mucho la Defensa.");

static const u8 sNoRetreatDescription[] = _(
    "Lo sube todo, pero ya no\n"
    "puede huir.");

static const u8 sTarShotDescription[] = _(
    "Alquitrán pegajoso: baja\n"
    "Velocidad y débil al fuego.");

static const u8 sMagicPowderDescription[] = _(
    "Polvo mágico que vuelve de\n"
    "tipo Psíquico al objetivo.");

static const u8 sDragonDartsDescription[] = _(
    "Lanza a ambos Dreepy. Con 2\n"
    "rivales, uno a cada uno.");

static const u8 sTeatimeDescription[] = _(
    "Todos toman el té y se comen\n"
    "sus bayas.");

static const u8 sOctolockDescription[] = _(
    "Impide huir; baja Def. y\n"
    "Def. Esp. cada turno.");

static const u8 sBoltBeakDescription[] = _(
    "Pico eléctrico. Doble de\n"
    "fuerza si ataca primero.");

static const u8 sFishiousRendDescription[] = _(
    "Pico eléctrico. Doble de\n"
    "fuerza si ataca primero.");

static const u8 sCourtChangeDescription[] = _(
    "Intercambia los efectos de\n"
    "ambos lados del campo.");

static const u8 sClangorousSoulDescription[] = _(
    "Gasta PS para subir sus\n"
    "características.");

static const u8 sBodyPressDescription[] = _(
    "Ataca con el cuerpo. Más\n"
    "daño cuanta más Defensa.");

static const u8 sDecorateDescription[] = _(
    "Decora al objetivo: sube\n"
    "mucho su Ataque y At. Esp.");

static const u8 sDrumBeatingDescription[] = _(
    "Toca un tocón como tambor.\n"
    "Baja la Velocidad.");

static const u8 sSnapTrapDescription[] = _(
    "Cepo que atrapa y daña al\n"
    "objetivo 4 o 5 turnos.");

static const u8 sPyroBallDescription[] = _(
    "Bola de fuego hecha con una\n"
    "piedra. Puede quemar.");

static const u8 sBehemothBladeDescription[] = _(
    "Espada gigante. Doble daño a\n"
    "rivales Dinamax.");

static const u8 sBehemothBashDescription[] = _(
    "Se vuelve un escudo gigante.\n"
    "Doble daño a Dinamax.");

static const u8 sAuraWheelDescription[] = _(
    "Sube Velocidad. Su tipo va\n"
    "según la forma.");

static const u8 sBreakingSwipeDescription[] = _(
    "Sacude su enorme cola. Baja\n"
    "el Ataque rival.");

static const u8 sBranchPokeDescription[] = _(
    "Ataca pinchando al objetivo\n"
    "con una rama afilada.");

static const u8 sOverdriveDescription[] = _(
    "Rasguea la guitarra y crea\n"
    "enormes vibraciones.");

static const u8 sAppleAcidDescription[] = _(
    "Fluido de manzana ácida.\n"
    "Baja la Def. Esp.");

static const u8 sGravAppleDescription[] = _(
    "Deja caer una manzana. Baja\n"
    "la Defensa del rival.");

static const u8 sSpiritBreakDescription[] = _(
    "Ataca con ímpetu y baja el\n"
    "At. Esp. del rival.");

static const u8 sStrangeSteamDescription[] = _(
    "Desprende humo que puede\n"
    "confundir.");

static const u8 sLifeDewDescription[] = _(
    "Agua balsámica que cura PS a\n"
    "él y a sus aliados.");

static const u8 sObstructDescription[] = _(
    "Frena ataques y baja mucho\n"
    "la Defensa del que toque.");

static const u8 sFalseSurrenderDescription[] = _(
    "Finge una reverencia y\n"
    "ensarta. Siempre acierta.");

static const u8 sMeteorAssaultDescription[] = _(
    "Agita su puerro. Luego está\n"
    "mareado y no se mueve.");

static const u8 sEternabeamDescription[] = _(
    "Mayor ataque de Eternatus.\n"
    "Luego no puede moverse.");

static const u8 sSteelBeamDescription[] = _(
    "Rayo de acero de su cuerpo.\n"
    "También hiere al usuario.");

static const u8 sExpandingForceDescription[] = _(
    "Con Campo Psíquico es más\n"
    "fuerte y daña a todos.");

static const u8 sSteelRollerDescription[] = _(
    "Destruye el campo activo.\n"
    "Falla si no hay ninguno.");

static const u8 sScaleShotDescription[] = _(
    "Escamas de 2 a 5 veces. Sube\n"
    "Velocidad y baja Defensa.");

static const u8 sMeteorBeamDescription[] = _(
    "Sube el At. Esp. con energía\n"
    "cósmica y ataca después.");

static const u8 sShellSideArmDescription[] = _(
    "Físico o especial, el que\n"
    "dañe más. Puede envenenar.");

static const u8 sMistyExplosionDescription[] = _(
    "Ataca a todos y se debilita.\n"
    "Mejor con Campo de Niebla.");

static const u8 sGrassyGlideDescription[] = _(
    "Se desliza. Prioridad alta\n"
    "con Campo de Hierba.");

static const u8 sRisingVoltageDescription[] = _(
    "Descarga del suelo. Doble\n"
    "con Campo Eléctrico.");

static const u8 sTerrainPulseDescription[] = _(
    "Tipo y potencia según el\n"
    "campo activo.");

static const u8 sSkitterSmackDescription[] = _(
    "Ataca por la espalda y baja\n"
    "el At. Esp.");

static const u8 sBurningJealousyDescription[] = _(
    "Energía de la envidia. Quema\n"
    "a quien se haya potenciado.");

static const u8 sLashOutDescription[] = _(
    "Ataca con rabia. Doble si le\n"
    "bajaron características.");

static const u8 sPoltergeistDescription[] = _(
    "Ataca con el objeto del\n"
    "rival. Falla si no tiene.");

static const u8 sCorrosiveGasDescription[] = _(
    "Gas cáustico que derrite\n"
    "los objetos de los cercanos.");

static const u8 sCoachingDescription[] = _(
    "Instruye a sus aliados. Sube\n"
    "Ataque y Defensa.");

static const u8 sFlipTurnDescription[] = _(
    "Tras atacar, da paso a otro\n"
    "Pokémon del equipo.");

static const u8 sTripleAxelDescription[] = _(
    "Patea hasta tres veces,\n"
    "cada vez más fuerte.");

static const u8 sDualWingbeatDescription[] = _(
    "Golpea al rival dos veces\n"
    "con las alas.");

static const u8 sScorchingSandsDescription[] = _(
    "Arena a gran temperatura.\n"
    "Puede quemar.");

static const u8 sJungleHealingDescription[] = _(
    "En armonía con la selva,\n"
    "cura PS y estado al equipo.");

static const u8 sWickedBlowDescription[] = _(
    "Dominio del estilo\n"
    "Siniestro. Siempre crítico.");

static const u8 sSurgingStrikesDescription[] = _(
    "Tres golpes del estilo Agua.\n"
    "Siempre son críticos.");

static const u8 sThunderCageDescription[] = _(
    "Atrapa al rival en una jaula\n"
    "eléctrica "BINDING_TURNS" turnos.");

static const u8 sDragonEnergyDescription[] = _(
    "Usa su fuerza vital. Menos\n"
    "potencia con menos PS.");

static const u8 sFreezingGlareDescription[] = _(
    "Poderes psíquicos por los\n"
    "ojos. Puede congelar.");

static const u8 sFieryWrathDescription[] = _(
    "Aura flamígera de ira. Puede\n"
    "amedrentar.");

static const u8 sThunderousKickDescription[] = _(
    "Patada centelleante. Baja\n"
    "la Defensa del rival.");

static const u8 sGlacialLanceDescription[] = _(
    "Lanza un carámbano envuelto\n"
    "en una ventisca.");

static const u8 sAstralBarrageDescription[] = _(
    "Lanza una ingente cantidad\n"
    "de pequeños fantasmas.");

static const u8 sEerieSpellDescription[] = _(
    "Poder psíquico que quita 3\n"
    "PP al último ataque rival.");

static const u8 sDireClawDescription[] = _(
    "Crítico alto. Puede dormir,\n"
    "paralizar o envenenar.");

static const u8 sPsyshieldBashDescription[] = _(
    "Golpea con energía psíquica.\n"
    "Puede subir la Defensa.");

static const u8 sPowerShiftDescription[] = _(
    "Intercambia su Ataque con\n"
    "su Defensa.");

static const u8 sStoneAxeDescription[] = _(
    "Crítico alto. Deja astillas\n"
    "que dañan al rival.");

static const u8 sSpringtideStormDescription[] = _(
    "Envuelve al rival en viento.\n"
    "Varía según la forma.");

static const u8 sMysticalPowerDescription[] = _(
    "Un poder misterioso golpea\n"
    "y sube el At. Esp.");

static const u8 sRagingFuryDescription[] = _(
    "Embestida que dura 2 ó 3\n"
    "turnos y te confunde.");

static const u8 sWaveCrashDescription[] = _(
    "Embestida envuelta en agua.\n"
    "También daña al usuario.");

static const u8 sChloroblastDescription[] = _(
    "Estallido de clorofila que\n"
    "también daña al usuario.");

static const u8 sMountainGaleDescription[] = _(
    "Grandes bloques de hielo.\n"
    "Puede hacer retroceder.");

static const u8 sVictoryDanceDescription[] = _(
    "Baila para subir el Ataque,\n"
    "la Defensa y la Velocidad.");

static const u8 sHeadlongRushDescription[] = _(
    "Placaje con todo el cuerpo.\n"
    "Baja sus defensas.");

static const u8 sBarbBarrageDescription[] = _(
    "Puede envenenar. Más fuerte\n"
    "contra rivales envenenados.");

static const u8 sEsperWingDescription[] = _(
    "Índice de crítico alto. Sube\n"
    "la Velocidad.");

static const u8 sBitterMaliceDescription[] = _(
    "Un rencor escalofriante.\n"
    "Puede bajar el Ataque.");

static const u8 sShelterDescription[] = _(
    "Endurece la piel y sube\n"
    "mucho la Defensa.");

static const u8 sTripleArrowsDescription[] = _(
    "Crítico alto. Puede bajar la\n"
    "Defensa o hacer retroceder.");

static const u8 sInfernalParadeDescription[] = _(
    "Más daño si el rival tiene un\n"
    "estado. Puede quemar.");

static const u8 sCeaselessEdgeDescription[] = _(
    "Crítico alto. Deja astillas\n"
    "que dañan al rival.");

static const u8 sBleakwindStormDescription[] = _(
    "Vientos gélidos brutales.\n"
    "Puede bajar la Velocidad.");

static const u8 sWildboltStormDescription[] = _(
    "Tempestad brutal. Puede\n"
    "paralizar.");

static const u8 sSandsearStormDescription[] = _(
    "Arena ardiente brutal.\n"
    "Puede quemar.");

static const u8 sLunarBlessingDescription[] = _(
    "Cura PS y estado al usuario\n"
    "y a su aliado.");

static const u8 sTakeHeartDescription[] = _(
    "Se anima para curarse y\n"
    "fortalecerse.");

static const u8 sTeraBlastDescription[] = _(
    "Si está teracristalizado,\n"
    "usa su teratipo.");

static const u8 sSilkTrapDescription[] =_(
    "Se protege y baja la\n"
    "Velocidad de quien le toque.");

static const u8 sAxeKickDescription[] = _(
    "Si falla, se hace daño. Puede\n"
    "confundir al usuario.");

static const u8 sLastRespectsDescription[] = _(
    "Más daño por cada aliado\n"
    "debilitado.");

static const u8 sLuminaCrashDescription[] = _(
    "Luz que afecta la mente y\n"
    "baja mucho la Def. Esp.");

static const u8 sOrderUpDescription[] = _(
    "Mejora al usuario según la\n"
    "forma de Tatsugiri.");

static const u8 sJetPunchDescription[] = _(
    "Puñetazo cegador que golpea\n"
    "primero.");

static const u8 sSpicyExtractDescription[] = _(
    "Sube mucho el Ataque del\n"
    "objetivo y baja su Defensa.");

static const u8 sSpinOutDescription[] = _(
    "Fuerza las piernas. Baja\n"
    "mucho su Velocidad.");

static const u8 sPopulationBombDescription[] = _(
    "Sus compañeros golpean de 1\n"
    "a 10 veces seguidas.");

static const u8 sIceSpinnerDescription[] = _(
    "Golpea con pies helados y\n"
    "destruye el campo.");

static const u8 sGlaiveRushDescription[] = _(
    "Luego, los ataques rivales\n"
    "no fallan y hacen el doble.");

static const u8 sRevivalBlessingDescription[] = _(
    "Revive a un {PKMN} del equipo\n"
    "con la mitad de sus PS.");

static const u8 sSaltCureDescription[] = _(
    "Daña cada turno. Doble\n"
    "contra tipos Acero y Agua.");

static const u8 sTripleDiveDescription[] = _(
    "Salpica agua al objetivo 3\n"
    "veces seguidas.");

static const u8 sMortalSpinDescription[] = _(
    "Quita trampas y Drenadoras.\n"
    "Envenena a los rivales.");

static const u8 sDoodleDescription[] = _(
    "Su aliado y él copian la\n"
    "habilidad del objetivo.");

static const u8 sFilletAwayDescription[] = _(
    "Gasta PS para subir mucho\n"
    "sus ataques y Velocidad.");

static const u8 sKowtowCleaveDescription[] = _(
    "Hace una reverencia y\n"
    "golpea. Nunca falla.");

static const u8 sFlowerTrickDescription[] = _(
    "Ramo trucado. Siempre es\n"
    "crítico y nunca falla.");

static const u8 sTorchSongDescription[] = _(
    "Llamas que abrasan al\n"
    "objetivo. Sube el At. Esp.");

static const u8 sAquaStepDescription[] = _(
    "Pasos de baile fluidos. Sube\n"
    "la Velocidad.");

static const u8 sRagingBullDescription[] = _(
    "Placaje que rompe barreras.\n"
    "Su tipo depende de la forma.");

static const u8 sMakeItRainDescription[] = _(
    "Baja el At. Esp. del usuario.\n"
    "Se recupera el dinero.");

static const u8 sRuinationDescription[] = _(
    "Provoca una catástrofe que\n"
    "quita la mitad de los PS.");

static const u8 sCollisionCourseDescription[] = _(
    "Explosión prehistórica. Más\n"
    "fuerte si es súper eficaz.");

static const u8 sElectroDriftDescription[] = _(
    "Electricidad futurista. Más\n"
    "fuerte si es súper eficaz.");

static const u8 sShedTailDescription[] = _(
    "Crea un sustituto para sí\n"
    "antes de retirarse.");

static const u8 sChillyReceptionDescription[] =_(
    "Un chiste malo invoca nieve.\n"
    "Luego se retira.");

static const u8 sTidyUpDescription[] = _(
    "Limpia las trampas y sube su\n"
    "Ataque y Velocidad.");

static const u8 sSnowscapeDescription[] = _(
    "Provoca una nevada que dura\n"
    "cinco turnos.");

static const u8 sPounceDescription[] = _(
    "Se abalanza sobre el rival y\n"
    "baja su Velocidad.");

static const u8 sTrailblazeDescription[] = _(
    "Ataca de repente y sube su\n"
    "Velocidad.");

static const u8 sChillingWaterDescription[] = _(
    "Ducha de agua helada que\n"
    "baja el Ataque del objetivo.");

static const u8 sHyperDrillDescription[] = _(
    "Una punta giratoria que\n"
    "atraviesa Protección.");

static const u8 sTwinBeamDescription[] = _(
    "Rayos místicos de los ojos\n"
    "que golpean dos veces.");

static const u8 sRageFistDescription[] = _(
    "Más fuerte cuantas más\n"
    "veces haya recibido golpes.");

static const u8 sArmorCannonDescription[] = _(
    "Lucha sin protegerse. Baja\n"
    "su Defensa y su Def. Esp.");

static const u8 sBitterBladeDescription[] = _(
    "Absorbe la mitad del daño\n"
    "producido.");

static const u8 sDoubleShockDescription[] = _(
    "Suelta toda su electricidad\n"
    "y deja de ser Eléctrico.");

static const u8 sGigatonHammerDescription[] = _(
    "Golpe con un martillo\n"
    "enorme. No se puede repetir.");

static const u8 sComeuppanceDescription[] = _(
    "Se venga con fuerza de\n"
    "quien le hirió el último.");

static const u8 sAquaCutterDescription[] = _(
    "Corte de agua a presión.\n"
    "Índice de crítico alto.");

static const u8 sBlazingTorqueDescription[] = _(
    "---");

static const u8 sWickedTorqueDescription[] = _(
    "---");

static const u8 sNoxiousTorqueDescription[] = _(
    "---");

static const u8 sCombatTorqueDescription[] = _(
    "---");

static const u8 sMagicalTorqueDescription[] = _(
    "---");

static const u8 sPsybladeDescription[] = _(
    "Su potencia aumenta con\n"
    "Campo Eléctrico.");

static const u8 sHydroSteamDescription[] = _(
    "Su potencia aumenta con sol\n"
    "intenso.");

static const u8 sBloodMoonDescription[] = _(
    "Desata la luna de sangre. No\n"
    "se puede repetir.");

static const u8 sMatchaGotchaDescription[] = _(
    "Absorbe la mitad del daño\n"
    "causado. Puede quemar.");

static const u8 sSyrupBombDescription[] = _(
    "Baja la Velocidad del rival\n"
    "durante 3 turnos.");

static const u8 sIvyCudgelDescription[] = _(
    "Su tipo depende de la\n"
    "máscara. Crítico alto.");

static const u8 sElectroShotDescription[] = _(
    "Absorbe electricidad y\n"
    "ataca al turno siguiente.");

static const u8 sTeraStarstormDescription[] = _(
    "Daña a todos los rivales si\n"
    "es Terapagos Astral.");

static const u8 sFickleBeamDescription[] = _(
    "Dispara un rayo de luz. A\n"
    "veces el doble de fuerte.");

static const u8 sBurningBulwarkDescription[] = _(
    "Evita el ataque y quema a\n"
    "quien le toque.");

static const u8 sTachyonCutterDescription[] = _(
    "Lanza cuchillas de\n"
    "partículas. Da 2 golpes.");

static const u8 sDragonCheerDescription[] = _(
    "Sube el crítico de los\n"
    "aliados, más a los Dragón.");

static const u8 sAlluringVoiceDescription[] = _(
    "Confunde si el objetivo se\n"
    "ha potenciado este turno.");

static const u8 sTemperFlareDescription[] = _(
    "Ataque desesperado. Doble\n"
    "si su último ataque falló.");

static const u8 sSupercellSlamDescription[] = _(
    "Golpe eléctrico. Si falla, el\n"
    "usuario se hace daño.");

static const u8 sPsychicNoiseDescription[] = _(
    "Ondas sonoras molestas que\n"
    "dañan e impiden curarse.");

static const u8 sUpperHandDescription[] = _(
    "Hace retroceder al objetivo\n"
    "si prepara un ataque rápido.");

static const u8 sMalignantChainDescription[] = _(
    "Cadena corrosiva que puede\n"
    "envenenar gravemente.");

const u8 gNotDoneYetDescription[] = _(
    "No se puede usar. Su efecto\n"
    "está en desarrollo.");

#undef BINDING_TURNS

// MOVE_NONE is ignored in this table. Make sure to always subtract 1 before getting the right pointer.
const u8 *const gMoveDescriptionPointers[MOVES_COUNT - 1] =
{
    [MOVE_POUND - 1] = sPoundDescription,
    [MOVE_KARATE_CHOP - 1] = sKarateChopDescription,
    [MOVE_DOUBLE_SLAP - 1] = sDoubleSlapDescription,
    [MOVE_COMET_PUNCH - 1] = sCometPunchDescription,
    [MOVE_MEGA_PUNCH - 1] = sMegaPunchDescription,
    [MOVE_PAY_DAY - 1] = sPayDayDescription,
    [MOVE_FIRE_PUNCH - 1] = sFirePunchDescription,
    [MOVE_ICE_PUNCH - 1] = sIcePunchDescription,
    [MOVE_THUNDER_PUNCH - 1] = sThunderPunchDescription,
    [MOVE_SCRATCH - 1] = sScratchDescription,
    [MOVE_VISE_GRIP - 1] = sViseGripDescription,
    [MOVE_GUILLOTINE - 1] = sGuillotineDescription,
    [MOVE_RAZOR_WIND - 1] = sRazorWindDescription,
    [MOVE_SWORDS_DANCE - 1] = sSwordsDanceDescription,
    [MOVE_CUT - 1] = sCutDescription,
    [MOVE_GUST - 1] = sGustDescription,
    [MOVE_WING_ATTACK - 1] = sWingAttackDescription,
    [MOVE_WHIRLWIND - 1] = sWhirlwindDescription,
    [MOVE_FLY - 1] = sFlyDescription,
    [MOVE_BIND - 1] = sBindDescription,
    [MOVE_SLAM - 1] = sSlamDescription,
    [MOVE_VINE_WHIP - 1] = sVineWhipDescription,
    [MOVE_STOMP - 1] = sStompDescription,
    [MOVE_DOUBLE_KICK - 1] = sDoubleKickDescription,
    [MOVE_MEGA_KICK - 1] = sMegaKickDescription,
    [MOVE_JUMP_KICK - 1] = sJumpKickDescription,
    [MOVE_ROLLING_KICK - 1] = sRollingKickDescription,
    [MOVE_SAND_ATTACK - 1] = sSandAttackDescription,
    [MOVE_HEADBUTT - 1] = sHeadbuttDescription,
    [MOVE_HORN_ATTACK - 1] = sHornAttackDescription,
    [MOVE_FURY_ATTACK - 1] = sFuryAttackDescription,
    [MOVE_HORN_DRILL - 1] = sHornDrillDescription,
    [MOVE_TACKLE - 1] = sTackleDescription,
    [MOVE_BODY_SLAM - 1] = sBodySlamDescription,
    [MOVE_WRAP - 1] = sWrapDescription,
    [MOVE_TAKE_DOWN - 1] = sTakeDownDescription,
    [MOVE_THRASH - 1] = sThrashDescription,
    [MOVE_DOUBLE_EDGE - 1] = sDoubleEdgeDescription,
    [MOVE_TAIL_WHIP - 1] = sTailWhipDescription,
    [MOVE_POISON_STING - 1] = sPoisonStingDescription,
    [MOVE_TWINEEDLE - 1] = sTwineedleDescription,
    [MOVE_PIN_MISSILE - 1] = sPinMissileDescription,
    [MOVE_LEER - 1] = sLeerDescription,
    [MOVE_BITE - 1] = sBiteDescription,
    [MOVE_GROWL - 1] = sGrowlDescription,
    [MOVE_ROAR - 1] = sRoarDescription,
    [MOVE_SING - 1] = sSingDescription,
    [MOVE_SUPERSONIC - 1] = sSupersonicDescription,
    [MOVE_SONIC_BOOM - 1] = sSonicBoomDescription,
    [MOVE_DISABLE - 1] = sDisableDescription,
    [MOVE_ACID - 1] = sAcidDescription,
    [MOVE_EMBER - 1] = sEmberDescription,
    [MOVE_FLAMETHROWER - 1] = sFlamethrowerDescription,
    [MOVE_MIST - 1] = sMistDescription,
    [MOVE_WATER_GUN - 1] = sWaterGunDescription,
    [MOVE_HYDRO_PUMP - 1] = sHydroPumpDescription,
    [MOVE_SURF - 1] = sSurfDescription,
    [MOVE_ICE_BEAM - 1] = sIceBeamDescription,
    [MOVE_BLIZZARD - 1] = sBlizzardDescription,
    [MOVE_PSYBEAM - 1] = sPsybeamDescription,
    [MOVE_BUBBLE_BEAM - 1] = sBubbleBeamDescription,
    [MOVE_AURORA_BEAM - 1] = sAuroraBeamDescription,
    [MOVE_HYPER_BEAM - 1] = sHyperBeamDescription,
    [MOVE_PECK - 1] = sPeckDescription,
    [MOVE_DRILL_PECK - 1] = sDrillPeckDescription,
    [MOVE_SUBMISSION - 1] = sSubmissionDescription,
    [MOVE_LOW_KICK - 1] = sLowKickDescription,
    [MOVE_COUNTER - 1] = sCounterDescription,
    [MOVE_SEISMIC_TOSS - 1] = sSeismicTossDescription,
    [MOVE_STRENGTH - 1] = sStrengthDescription,
    [MOVE_ABSORB - 1] = sAbsorbDescription,
    [MOVE_MEGA_DRAIN - 1] = sMegaDrainDescription,
    [MOVE_LEECH_SEED - 1] = sLeechSeedDescription,
    [MOVE_GROWTH - 1] = sGrowthDescription,
    [MOVE_RAZOR_LEAF - 1] = sRazorLeafDescription,
    [MOVE_SOLAR_BEAM - 1] = sSolarBeamDescription,
    [MOVE_POISON_POWDER - 1] = sPoisonPowderDescription,
    [MOVE_STUN_SPORE - 1] = sStunSporeDescription,
    [MOVE_SLEEP_POWDER - 1] = sSleepPowderDescription,
    [MOVE_PETAL_DANCE - 1] = sPetalDanceDescription,
    [MOVE_STRING_SHOT - 1] = sStringShotDescription,
    [MOVE_DRAGON_RAGE - 1] = sDragonRageDescription,
    [MOVE_FIRE_SPIN - 1] = sFireSpinDescription,
    [MOVE_THUNDER_SHOCK - 1] = sThunderShockDescription,
    [MOVE_THUNDERBOLT - 1] = sThunderboltDescription,
    [MOVE_THUNDER_WAVE - 1] = sThunderWaveDescription,
    [MOVE_THUNDER - 1] = sThunderDescription,
    [MOVE_ROCK_THROW - 1] = sRockThrowDescription,
    [MOVE_EARTHQUAKE - 1] = sEarthquakeDescription,
    [MOVE_FISSURE - 1] = sFissureDescription,
    [MOVE_DIG - 1] = sDigDescription,
    [MOVE_TOXIC - 1] = sToxicDescription,
    [MOVE_CONFUSION - 1] = sConfusionDescription,
    [MOVE_PSYCHIC - 1] = sPsychicDescription,
    [MOVE_HYPNOSIS - 1] = sHypnosisDescription,
    [MOVE_MEDITATE - 1] = sMeditateDescription,
    [MOVE_AGILITY - 1] = sAgilityDescription,
    [MOVE_QUICK_ATTACK - 1] = sQuickAttackDescription,
    [MOVE_RAGE - 1] = sRageDescription,
    [MOVE_TELEPORT - 1] = sTeleportDescription,
    [MOVE_NIGHT_SHADE - 1] = sNightShadeDescription,
    [MOVE_MIMIC - 1] = sMimicDescription,
    [MOVE_SCREECH - 1] = sScreechDescription,
    [MOVE_DOUBLE_TEAM - 1] = sDoubleTeamDescription,
    [MOVE_RECOVER - 1] = sRecoverDescription,
    [MOVE_HARDEN - 1] = sHardenDescription,
    [MOVE_MINIMIZE - 1] = sMinimizeDescription,
    [MOVE_SMOKESCREEN - 1] = sSmokescreenDescription,
    [MOVE_CONFUSE_RAY - 1] = sConfuseRayDescription,
    [MOVE_WITHDRAW - 1] = sWithdrawDescription,
    [MOVE_DEFENSE_CURL - 1] = sDefenseCurlDescription,
    [MOVE_BARRIER - 1] = sBarrierDescription,
    [MOVE_LIGHT_SCREEN - 1] = sLightScreenDescription,
    [MOVE_HAZE - 1] = sHazeDescription,
    [MOVE_REFLECT - 1] = sReflectDescription,
    [MOVE_FOCUS_ENERGY - 1] = sFocusEnergyDescription,
    [MOVE_BIDE - 1] = sBideDescription,
    [MOVE_METRONOME - 1] = sMetronomeDescription,
    [MOVE_MIRROR_MOVE - 1] = sMirrorMoveDescription,
    [MOVE_SELF_DESTRUCT - 1] = sSelfDestructDescription,
    [MOVE_EGG_BOMB - 1] = sEggBombDescription,
    [MOVE_LICK - 1] = sLickDescription,
    [MOVE_SMOG - 1] = sSmogDescription,
    [MOVE_SLUDGE - 1] = sSludgeDescription,
    [MOVE_BONE_CLUB - 1] = sBoneClubDescription,
    [MOVE_FIRE_BLAST - 1] = sFireBlastDescription,
    [MOVE_WATERFALL - 1] = sWaterfallDescription,
    [MOVE_CLAMP - 1] = sClampDescription,
    [MOVE_SWIFT - 1] = sSwiftDescription,
    [MOVE_SKULL_BASH - 1] = sSkullBashDescription,
    [MOVE_SPIKE_CANNON - 1] = sSpikeCannonDescription,
    [MOVE_CONSTRICT - 1] = sConstrictDescription,
    [MOVE_AMNESIA - 1] = sAmnesiaDescription,
    [MOVE_KINESIS - 1] = sKinesisDescription,
    [MOVE_SOFT_BOILED - 1] = sSoftBoiledDescription,
    [MOVE_HIGH_JUMP_KICK - 1] = sHighJumpKickDescription,
    [MOVE_GLARE - 1] = sGlareDescription,
    [MOVE_DREAM_EATER - 1] = sDreamEaterDescription,
    [MOVE_POISON_GAS - 1] = sPoisonGasDescription,
    [MOVE_BARRAGE - 1] = sBarrageDescription,
    [MOVE_LEECH_LIFE - 1] = sLeechLifeDescription,
    [MOVE_LOVELY_KISS - 1] = sLovelyKissDescription,
    [MOVE_SKY_ATTACK - 1] = sSkyAttackDescription,
    [MOVE_TRANSFORM - 1] = sTransformDescription,
    [MOVE_BUBBLE - 1] = sBubbleDescription,
    [MOVE_DIZZY_PUNCH - 1] = sDizzyPunchDescription,
    [MOVE_SPORE - 1] = sSporeDescription,
    [MOVE_FLASH - 1] = sFlashDescription,
    [MOVE_PSYWAVE - 1] = sPsywaveDescription,
    [MOVE_SPLASH - 1] = sSplashDescription,
    [MOVE_ACID_ARMOR - 1] = sAcidArmorDescription,
    [MOVE_CRABHAMMER - 1] = sCrabhammerDescription,
    [MOVE_EXPLOSION - 1] = sExplosionDescription,
    [MOVE_FURY_SWIPES - 1] = sFurySwipesDescription,
    [MOVE_BONEMERANG - 1] = sBonemerangDescription,
    [MOVE_REST - 1] = sRestDescription,
    [MOVE_ROCK_SLIDE - 1] = sRockSlideDescription,
    [MOVE_HYPER_FANG - 1] = sHyperFangDescription,
    [MOVE_SHARPEN - 1] = sSharpenDescription,
    [MOVE_CONVERSION - 1] = sConversionDescription,
    [MOVE_TRI_ATTACK - 1] = sTriAttackDescription,
    [MOVE_SUPER_FANG - 1] = sSuperFangDescription,
    [MOVE_SLASH - 1] = sSlashDescription,
    [MOVE_SUBSTITUTE - 1] = sSubstituteDescription,
    [MOVE_STRUGGLE - 1] = sStruggleDescription,
    [MOVE_SKETCH - 1] = sSketchDescription,
    [MOVE_TRIPLE_KICK - 1] = sTripleKickDescription,
    [MOVE_THIEF - 1] = sThiefDescription,
    [MOVE_SPIDER_WEB - 1] = sSpiderWebDescription,
    [MOVE_MIND_READER - 1] = sMindReaderDescription,
    [MOVE_NIGHTMARE - 1] = sNightmareDescription,
    [MOVE_FLAME_WHEEL - 1] = sFlameWheelDescription,
    [MOVE_SNORE - 1] = sSnoreDescription,
    [MOVE_CURSE - 1] = sCurseDescription,
    [MOVE_FLAIL - 1] = sFlailDescription,
    [MOVE_CONVERSION_2 - 1] = sConversion2Description,
    [MOVE_AEROBLAST - 1] = sAeroblastDescription,
    [MOVE_COTTON_SPORE - 1] = sCottonSporeDescription,
    [MOVE_REVERSAL - 1] = sReversalDescription,
    [MOVE_SPITE - 1] = sSpiteDescription,
    [MOVE_POWDER_SNOW - 1] = sPowderSnowDescription,
    [MOVE_PROTECT - 1] = sProtectDescription,
    [MOVE_MACH_PUNCH - 1] = sMachPunchDescription,
    [MOVE_SCARY_FACE - 1] = sScaryFaceDescription,
    [MOVE_FEINT_ATTACK - 1] = sFeintAttackDescription,
    [MOVE_SWEET_KISS - 1] = sSweetKissDescription,
    [MOVE_BELLY_DRUM - 1] = sBellyDrumDescription,
    [MOVE_SLUDGE_BOMB - 1] = sSludgeBombDescription,
    [MOVE_MUD_SLAP - 1] = sMudSlapDescription,
    [MOVE_OCTAZOOKA - 1] = sOctazookaDescription,
    [MOVE_SPIKES - 1] = sSpikesDescription,
    [MOVE_ZAP_CANNON - 1] = sZapCannonDescription,
    [MOVE_FORESIGHT - 1] = sForesightDescription,
    [MOVE_DESTINY_BOND - 1] = sDestinyBondDescription,
    [MOVE_PERISH_SONG - 1] = sPerishSongDescription,
    [MOVE_ICY_WIND - 1] = sIcyWindDescription,
    [MOVE_DETECT - 1] = sDetectDescription,
    [MOVE_BONE_RUSH - 1] = sBoneRushDescription,
    [MOVE_LOCK_ON - 1] = sLockOnDescription,
    [MOVE_OUTRAGE - 1] = sOutrageDescription,
    [MOVE_SANDSTORM - 1] = sSandstormDescription,
    [MOVE_GIGA_DRAIN - 1] = sGigaDrainDescription,
    [MOVE_ENDURE - 1] = sEndureDescription,
    [MOVE_CHARM - 1] = sCharmDescription,
    [MOVE_ROLLOUT - 1] = sRolloutDescription,
    [MOVE_FALSE_SWIPE - 1] = sFalseSwipeDescription,
    [MOVE_SWAGGER - 1] = sSwaggerDescription,
    [MOVE_MILK_DRINK - 1] = sMilkDrinkDescription,
    [MOVE_SPARK - 1] = sSparkDescription,
    [MOVE_FURY_CUTTER - 1] = sFuryCutterDescription,
    [MOVE_STEEL_WING - 1] = sSteelWingDescription,
    [MOVE_MEAN_LOOK - 1] = sMeanLookDescription,
    [MOVE_ATTRACT - 1] = sAttractDescription,
    [MOVE_SLEEP_TALK - 1] = sSleepTalkDescription,
    [MOVE_HEAL_BELL - 1] = sHealBellDescription,
    [MOVE_RETURN - 1] = sReturnDescription,
    [MOVE_PRESENT - 1] = sPresentDescription,
    [MOVE_FRUSTRATION - 1] = sFrustrationDescription,
    [MOVE_SAFEGUARD - 1] = sSafeguardDescription,
    [MOVE_PAIN_SPLIT - 1] = sPainSplitDescription,
    [MOVE_SACRED_FIRE - 1] = sSacredFireDescription,
    [MOVE_MAGNITUDE - 1] = sMagnitudeDescription,
    [MOVE_DYNAMIC_PUNCH - 1] = sDynamicPunchDescription,
    [MOVE_MEGAHORN - 1] = sMegahornDescription,
    [MOVE_DRAGON_BREATH - 1] = sDragonBreathDescription,
    [MOVE_BATON_PASS - 1] = sBatonPassDescription,
    [MOVE_ENCORE - 1] = sEncoreDescription,
    [MOVE_PURSUIT - 1] = sPursuitDescription,
    [MOVE_RAPID_SPIN - 1] = sRapidSpinDescription,
    [MOVE_SWEET_SCENT - 1] = sSweetScentDescription,
    [MOVE_IRON_TAIL - 1] = sIronTailDescription,
    [MOVE_METAL_CLAW - 1] = sMetalClawDescription,
    [MOVE_VITAL_THROW - 1] = sVitalThrowDescription,
    [MOVE_MORNING_SUN - 1] = sMorningSunDescription,
    [MOVE_SYNTHESIS - 1] = sSynthesisDescription,
    [MOVE_MOONLIGHT - 1] = sMoonlightDescription,
    [MOVE_HIDDEN_POWER - 1] = sHiddenPowerDescription,
    [MOVE_CROSS_CHOP - 1] = sCrossChopDescription,
    [MOVE_TWISTER - 1] = sTwisterDescription,
    [MOVE_RAIN_DANCE - 1] = sRainDanceDescription,
    [MOVE_SUNNY_DAY - 1] = sSunnyDayDescription,
    [MOVE_CRUNCH - 1] = sCrunchDescription,
    [MOVE_MIRROR_COAT - 1] = sMirrorCoatDescription,
    [MOVE_PSYCH_UP - 1] = sPsychUpDescription,
    [MOVE_EXTREME_SPEED - 1] = sExtremeSpeedDescription,
    [MOVE_ANCIENT_POWER - 1] = sAncientPowerDescription,
    [MOVE_SHADOW_BALL - 1] = sShadowBallDescription,
    [MOVE_FUTURE_SIGHT - 1] = sFutureSightDescription,
    [MOVE_ROCK_SMASH - 1] = sRockSmashDescription,
    [MOVE_WHIRLPOOL - 1] = sWhirlpoolDescription,
    [MOVE_BEAT_UP - 1] = sBeatUpDescription,
    [MOVE_FAKE_OUT - 1] = sFakeOutDescription,
    [MOVE_UPROAR - 1] = sUproarDescription,
    [MOVE_STOCKPILE - 1] = sStockpileDescription,
    [MOVE_SPIT_UP - 1] = sSpitUpDescription,
    [MOVE_SWALLOW - 1] = sSwallowDescription,
    [MOVE_HEAT_WAVE - 1] = sHeatWaveDescription,
    [MOVE_HAIL - 1] = sHailDescription,
    [MOVE_TORMENT - 1] = sTormentDescription,
    [MOVE_FLATTER - 1] = sFlatterDescription,
    [MOVE_WILL_O_WISP - 1] = sWillOWispDescription,
    [MOVE_MEMENTO - 1] = sMementoDescription,
    [MOVE_FACADE - 1] = sFacadeDescription,
    [MOVE_FOCUS_PUNCH - 1] = sFocusPunchDescription,
    [MOVE_SMELLING_SALTS - 1] = sSmellingSaltsDescription,
    [MOVE_FOLLOW_ME - 1] = sFollowMeDescription,
    [MOVE_NATURE_POWER - 1] = sNaturePowerDescription,
    [MOVE_CHARGE - 1] = sChargeDescription,
    [MOVE_TAUNT - 1] = sTauntDescription,
    [MOVE_HELPING_HAND - 1] = sHelpingHandDescription,
    [MOVE_TRICK - 1] = sTrickDescription,
    [MOVE_ROLE_PLAY - 1] = sRolePlayDescription,
    [MOVE_WISH - 1] = sWishDescription,
    [MOVE_ASSIST - 1] = sAssistDescription,
    [MOVE_INGRAIN - 1] = sIngrainDescription,
    [MOVE_SUPERPOWER - 1] = sSuperpowerDescription,
    [MOVE_MAGIC_COAT - 1] = sMagicCoatDescription,
    [MOVE_RECYCLE - 1] = sRecycleDescription,
    [MOVE_REVENGE - 1] = sRevengeDescription,
    [MOVE_BRICK_BREAK - 1] = sBrickBreakDescription,
    [MOVE_YAWN - 1] = sYawnDescription,
    [MOVE_KNOCK_OFF - 1] = sKnockOffDescription,
    [MOVE_ENDEAVOR - 1] = sEndeavorDescription,
    [MOVE_ERUPTION - 1] = sEruptionDescription,
    [MOVE_SKILL_SWAP - 1] = sSkillSwapDescription,
    [MOVE_IMPRISON - 1] = sImprisonDescription,
    [MOVE_REFRESH - 1] = sRefreshDescription,
    [MOVE_GRUDGE - 1] = sGrudgeDescription,
    [MOVE_SNATCH - 1] = sSnatchDescription,
    [MOVE_SECRET_POWER - 1] = sSecretPowerDescription,
    [MOVE_DIVE - 1] = sDiveDescription,
    [MOVE_ARM_THRUST - 1] = sArmThrustDescription,
    [MOVE_CAMOUFLAGE - 1] = sCamouflageDescription,
    [MOVE_TAIL_GLOW - 1] = sTailGlowDescription,
    [MOVE_LUSTER_PURGE - 1] = sLusterPurgeDescription,
    [MOVE_MIST_BALL - 1] = sMistBallDescription,
    [MOVE_FEATHER_DANCE - 1] = sFeatherDanceDescription,
    [MOVE_TEETER_DANCE - 1] = sTeeterDanceDescription,
    [MOVE_BLAZE_KICK - 1] = sBlazeKickDescription,
    [MOVE_MUD_SPORT - 1] = sMudSportDescription,
    [MOVE_ICE_BALL - 1] = sIceBallDescription,
    [MOVE_NEEDLE_ARM - 1] = sNeedleArmDescription,
    [MOVE_SLACK_OFF - 1] = sSlackOffDescription,
    [MOVE_HYPER_VOICE - 1] = sHyperVoiceDescription,
    [MOVE_POISON_FANG - 1] = sPoisonFangDescription,
    [MOVE_CRUSH_CLAW - 1] = sCrushClawDescription,
    [MOVE_BLAST_BURN - 1] = sBlastBurnDescription,
    [MOVE_HYDRO_CANNON - 1] = sHydroCannonDescription,
    [MOVE_METEOR_MASH - 1] = sMeteorMashDescription,
    [MOVE_ASTONISH - 1] = sAstonishDescription,
    [MOVE_WEATHER_BALL - 1] = sWeatherBallDescription,
    [MOVE_AROMATHERAPY - 1] = sAromatherapyDescription,
    [MOVE_FAKE_TEARS - 1] = sFakeTearsDescription,
    [MOVE_AIR_CUTTER - 1] = sAirCutterDescription,
    [MOVE_OVERHEAT - 1] = sOverheatDescription,
    [MOVE_ODOR_SLEUTH - 1] = sOdorSleuthDescription,
    [MOVE_ROCK_TOMB - 1] = sRockTombDescription,
    [MOVE_SILVER_WIND - 1] = sSilverWindDescription,
    [MOVE_METAL_SOUND - 1] = sMetalSoundDescription,
    [MOVE_GRASS_WHISTLE - 1] = sGrassWhistleDescription,
    [MOVE_TICKLE - 1] = sTickleDescription,
    [MOVE_COSMIC_POWER - 1] = sCosmicPowerDescription,
    [MOVE_WATER_SPOUT - 1] = sWaterSpoutDescription,
    [MOVE_SIGNAL_BEAM - 1] = sSignalBeamDescription,
    [MOVE_SHADOW_PUNCH - 1] = sShadowPunchDescription,
    [MOVE_EXTRASENSORY - 1] = sExtrasensoryDescription,
    [MOVE_SKY_UPPERCUT - 1] = sSkyUppercutDescription,
    [MOVE_SAND_TOMB - 1] = sSandTombDescription,
    [MOVE_SHEER_COLD - 1] = sSheerColdDescription,
    [MOVE_MUDDY_WATER - 1] = sMuddyWaterDescription,
    [MOVE_BULLET_SEED - 1] = sBulletSeedDescription,
    [MOVE_AERIAL_ACE - 1] = sAerialAceDescription,
    [MOVE_ICICLE_SPEAR - 1] = sIcicleSpearDescription,
    [MOVE_IRON_DEFENSE - 1] = sIronDefenseDescription,
    [MOVE_BLOCK - 1] = sBlockDescription,
    [MOVE_HOWL - 1] = sHowlDescription,
    [MOVE_DRAGON_CLAW - 1] = sDragonClawDescription,
    [MOVE_FRENZY_PLANT - 1] = sFrenzyPlantDescription,
    [MOVE_BULK_UP - 1] = sBulkUpDescription,
    [MOVE_BOUNCE - 1] = sBounceDescription,
    [MOVE_MUD_SHOT - 1] = sMudShotDescription,
    [MOVE_POISON_TAIL - 1] = sPoisonTailDescription,
    [MOVE_COVET - 1] = sCovetDescription,
    [MOVE_VOLT_TACKLE - 1] = sVoltTackleDescription,
    [MOVE_MAGICAL_LEAF - 1] = sMagicalLeafDescription,
    [MOVE_WATER_SPORT - 1] = sWaterSportDescription,
    [MOVE_CALM_MIND - 1] = sCalmMindDescription,
    [MOVE_LEAF_BLADE - 1] = sLeafBladeDescription,
    [MOVE_DRAGON_DANCE - 1] = sDragonDanceDescription,
    [MOVE_ROCK_BLAST - 1] = sRockBlastDescription,
    [MOVE_SHOCK_WAVE - 1] = sShockWaveDescription,
    [MOVE_WATER_PULSE - 1] = sWaterPulseDescription,
    [MOVE_DOOM_DESIRE - 1] = sDoomDesireDescription,
    [MOVE_PSYCHO_BOOST - 1] = sPsychoBoostDescription,
    [MOVE_ROOST - 1] = sRoostDescription,
    [MOVE_GRAVITY - 1] = sGravityDescription,
    [MOVE_MIRACLE_EYE - 1] = sMiracleEyeDescription,
    [MOVE_WAKE_UP_SLAP - 1] = sWakeUpSlapDescription,
    [MOVE_HAMMER_ARM - 1] = sHammerArmDescription,
    [MOVE_GYRO_BALL - 1] = sGyroBallDescription,
    [MOVE_HEALING_WISH - 1] = sHealingWishDescription,
    [MOVE_BRINE - 1] = sBrineDescription,
    [MOVE_NATURAL_GIFT - 1] = sNaturalGiftDescription,
    [MOVE_FEINT - 1] = sFeintDescription,
    [MOVE_PLUCK - 1] = sPluckDescription,
    [MOVE_TAILWIND - 1] = sTailwindDescription,
    [MOVE_ACUPRESSURE - 1] = sAcupressureDescription,
    [MOVE_METAL_BURST - 1] = sMetalBurstDescription,
    [MOVE_U_TURN - 1] = sUTurnDescription,
    [MOVE_CLOSE_COMBAT - 1] = sCloseCombatDescription,
    [MOVE_PAYBACK - 1] = sPaybackDescription,
    [MOVE_ASSURANCE - 1] = sAssuranceDescription,
    [MOVE_EMBARGO - 1] = sEmbargoDescription,
    [MOVE_FLING - 1] = sFlingDescription,
    [MOVE_PSYCHO_SHIFT - 1] = sPsychoShiftDescription,
    [MOVE_TRUMP_CARD - 1] = sTrumpCardDescription,
    [MOVE_HEAL_BLOCK - 1] = sHealBlockDescription,
    [MOVE_WRING_OUT - 1] = sWringOutDescription,
    [MOVE_POWER_TRICK - 1] = sPowerTrickDescription,
    [MOVE_GASTRO_ACID - 1] = sGastroAcidDescription,
    [MOVE_LUCKY_CHANT - 1] = sLuckyChantDescription,
    [MOVE_ME_FIRST - 1] = sMeFirstDescription,
    [MOVE_COPYCAT - 1] = sCopycatDescription,
    [MOVE_POWER_SWAP - 1] = sPowerSwapDescription,
    [MOVE_GUARD_SWAP - 1] = sGuardSwapDescription,
    [MOVE_PUNISHMENT - 1] = sPunishmentDescription,
    [MOVE_LAST_RESORT - 1] = sLastResortDescription,
    [MOVE_WORRY_SEED - 1] = sWorrySeedDescription,
    [MOVE_SUCKER_PUNCH - 1] = sSuckerPunchDescription,
    [MOVE_TOXIC_SPIKES - 1] = sToxicSpikesDescription,
    [MOVE_HEART_SWAP - 1] = sHeartSwapDescription,
    [MOVE_AQUA_RING - 1] = sAquaRingDescription,
    [MOVE_MAGNET_RISE - 1] = sMagnetRiseDescription,
    [MOVE_FLARE_BLITZ - 1] = sFlareBlitzDescription,
    [MOVE_FORCE_PALM - 1] = sForcePalmDescription,
    [MOVE_AURA_SPHERE - 1] = sAuraSphereDescription,
    [MOVE_ROCK_POLISH - 1] = sRockPolishDescription,
    [MOVE_POISON_JAB - 1] = sPoisonJabDescription,
    [MOVE_DARK_PULSE - 1] = sDarkPulseDescription,
    [MOVE_NIGHT_SLASH - 1] = sNightSlashDescription,
    [MOVE_AQUA_TAIL - 1] = sAquaTailDescription,
    [MOVE_SEED_BOMB - 1] = sSeedBombDescription,
    [MOVE_AIR_SLASH - 1] = sAirSlashDescription,
    [MOVE_X_SCISSOR - 1] = sXScissorDescription,
    [MOVE_BUG_BUZZ - 1] = sBugBuzzDescription,
    [MOVE_DRAGON_PULSE - 1] = sDragonPulseDescription,
    [MOVE_DRAGON_RUSH - 1] = sDragonRushDescription,
    [MOVE_POWER_GEM - 1] = sPowerGemDescription,
    [MOVE_DRAIN_PUNCH - 1] = sMegaDrainDescription,
    [MOVE_VACUUM_WAVE - 1] = sVacuumWaveDescription,
    [MOVE_FOCUS_BLAST - 1] = sFocusBlastDescription,
    [MOVE_ENERGY_BALL - 1] = sEnergyBallDescription,
    [MOVE_BRAVE_BIRD - 1] = sBraveBirdDescription,
    [MOVE_EARTH_POWER - 1] = sEarthPowerDescription,
    [MOVE_SWITCHEROO - 1] = sSwitcherooDescription,
    [MOVE_GIGA_IMPACT - 1] = sHyperBeamDescription,
    [MOVE_NASTY_PLOT - 1] = sNastyPlotDescription,
    [MOVE_BULLET_PUNCH - 1] = sBulletPunchDescription,
    [MOVE_AVALANCHE - 1] = sRevengeDescription,
    [MOVE_ICE_SHARD - 1] = sIceShardDescription,
    [MOVE_SHADOW_CLAW - 1] = sShadowClawDescription,
    [MOVE_THUNDER_FANG - 1] = sThunderFangDescription,
    [MOVE_ICE_FANG - 1] = sIceFangDescription,
    [MOVE_FIRE_FANG - 1] = sFireFangDescription,
    [MOVE_SHADOW_SNEAK - 1] = sShadowSneakDescription,
    [MOVE_MUD_BOMB - 1] = sMudBombDescription,
    [MOVE_PSYCHO_CUT - 1] = sPsychoCutDescription,
    [MOVE_ZEN_HEADBUTT - 1] = sZenHeadbuttDescription,
    [MOVE_MIRROR_SHOT - 1] = sMirrorShotDescription,
    [MOVE_FLASH_CANNON - 1] = sFlashCannonDescription,
    [MOVE_ROCK_CLIMB - 1] = sRockClimbDescription,
    [MOVE_DEFOG - 1] = sDefogDescription,
    [MOVE_TRICK_ROOM - 1] = sTrickRoomDescription,
    [MOVE_DRACO_METEOR - 1] = sDracoMeteorDescription,
    [MOVE_DISCHARGE - 1] = sDischargeDescription,
    [MOVE_LAVA_PLUME - 1] = sLavaPlumeDescription,
    [MOVE_LEAF_STORM - 1] = sLeafStormDescription,
    [MOVE_POWER_WHIP - 1] = sPowerWhipDescription,
    [MOVE_ROCK_WRECKER - 1] = sHyperBeamDescription,
    [MOVE_CROSS_POISON - 1] = sCrossPoisonDescription,
    [MOVE_GUNK_SHOT - 1] = sGunkShotDescription,
    [MOVE_IRON_HEAD - 1] = sIronHeadDescription,
    [MOVE_MAGNET_BOMB - 1] = sMagnetBombDescription,
    [MOVE_STONE_EDGE - 1] = sStoneEdgeDescription,
    [MOVE_CAPTIVATE - 1] = sCaptivateDescription,
    [MOVE_STEALTH_ROCK - 1] = sStealthRockDescription,
    [MOVE_GRASS_KNOT - 1] = sGrassKnotDescription,
    [MOVE_CHATTER - 1] = sChatterDescription,
    [MOVE_JUDGMENT - 1] = sJudgmentDescription,
    [MOVE_BUG_BITE - 1] = sPluckDescription,
    [MOVE_CHARGE_BEAM - 1] = sChargeBeamDescription,
    [MOVE_WOOD_HAMMER - 1] = sWoodHammerDescription,
    [MOVE_AQUA_JET - 1] = sAquaJetDescription,
    [MOVE_ATTACK_ORDER - 1] = sAttackOrderDescription,
    [MOVE_DEFEND_ORDER - 1] = sDefendOrderDescription,
    [MOVE_HEAL_ORDER - 1] = sHealOrderDescription,
    [MOVE_HEAD_SMASH - 1] = sHeadSmashDescription,
    [MOVE_DOUBLE_HIT - 1] = sDoubleHitDescription,
    [MOVE_ROAR_OF_TIME - 1] = sRoarOfTimeDescription,
    [MOVE_SPACIAL_REND - 1] = sSpacialRendDescription,
    [MOVE_LUNAR_DANCE - 1] = sHealingWishDescription,
    [MOVE_CRUSH_GRIP - 1] = sWringOutDescription,
    [MOVE_MAGMA_STORM - 1] = sMagmaStormDescription,
    [MOVE_DARK_VOID - 1] = sDarkVoidDescription,
    [MOVE_SEED_FLARE - 1] = sSeedFlareDescription,
    [MOVE_OMINOUS_WIND - 1] = sOminousWindDescription,
    [MOVE_SHADOW_FORCE - 1] = sShadowForceDescription,
    [MOVE_HONE_CLAWS - 1] = sHoneClawsDescription,
    [MOVE_WIDE_GUARD - 1] = sWideGuardDescription,
    [MOVE_GUARD_SPLIT - 1] = sGuardSplitDescription,
    [MOVE_POWER_SPLIT - 1] = sPowerSplitDescription,
    [MOVE_WONDER_ROOM - 1] = sWonderRoomDescription,
    [MOVE_PSYSHOCK - 1] = sPsyshockDescription,
    [MOVE_VENOSHOCK - 1] = sVenoshockDescription,
    [MOVE_AUTOTOMIZE - 1] = sAutotomizeDescription,
    [MOVE_RAGE_POWDER - 1] = sRagePowderDescription,
    [MOVE_TELEKINESIS - 1] = sTelekinesisDescription,
    [MOVE_MAGIC_ROOM - 1] = sMagicRoomDescription,
    [MOVE_SMACK_DOWN - 1] = sSmackDownDescription,
    [MOVE_STORM_THROW - 1] = sStormThrowDescription,
    [MOVE_FLAME_BURST - 1] = sFlameBurstDescription,
    [MOVE_SLUDGE_WAVE - 1] = sSludgeWaveDescription,
    [MOVE_QUIVER_DANCE - 1] = sQuiverDanceDescription,
    [MOVE_HEAVY_SLAM - 1] = sHeavySlamDescription,
    [MOVE_SYNCHRONOISE - 1] = sSynchronoiseDescription,
    [MOVE_ELECTRO_BALL - 1] = sElectroBallDescription,
    [MOVE_SOAK - 1] = sSoakDescription,
    [MOVE_FLAME_CHARGE - 1] = sFlameChargeDescription,
    [MOVE_COIL - 1] = sCoilDescription,
    [MOVE_LOW_SWEEP - 1] = sLowSweepDescription,
    [MOVE_ACID_SPRAY - 1] = sAcidSprayDescription,
    [MOVE_FOUL_PLAY - 1] = sFoulPlayDescription,
    [MOVE_SIMPLE_BEAM - 1] = sSimpleBeamDescription,
    [MOVE_ENTRAINMENT - 1] = sEntrainmentDescription,
    [MOVE_AFTER_YOU - 1] = sAfterYouDescription,
    [MOVE_ROUND - 1] = sRoundDescription,
    [MOVE_ECHOED_VOICE - 1] = sEchoedVoiceDescription,
    [MOVE_CHIP_AWAY - 1] = sChipAwayDescription,
    [MOVE_CLEAR_SMOG - 1] = sClearSmogDescription,
    [MOVE_STORED_POWER - 1] = sStoredPowerDescription,
    [MOVE_QUICK_GUARD - 1] = sQuickGuardDescription,
    [MOVE_ALLY_SWITCH - 1] = sAllySwitchDescription,
    [MOVE_SCALD - 1] = sScaldDescription,
    [MOVE_SHELL_SMASH - 1] = sShellSmashDescription,
    [MOVE_HEAL_PULSE - 1] = sHealPulseDescription,
    [MOVE_HEX - 1] = sHexDescription,
    [MOVE_SKY_DROP - 1] = sSkyDropDescription,
    [MOVE_SHIFT_GEAR - 1] = sShiftGearDescription,
    [MOVE_CIRCLE_THROW - 1] = sCircleThrowDescription,
    [MOVE_INCINERATE - 1] = sIncinerateDescription,
    [MOVE_QUASH - 1] = sQuashDescription,
    [MOVE_ACROBATICS - 1] = sAcrobaticsDescription,
    [MOVE_REFLECT_TYPE - 1] = sReflectTypeDescription,
    [MOVE_RETALIATE - 1] = sRetaliateDescription,
    [MOVE_FINAL_GAMBIT - 1] = sFinalGambitDescription,
    [MOVE_BESTOW - 1] = sBestowDescription,
    [MOVE_INFERNO - 1] = sInfernoDescription,
    [MOVE_WATER_PLEDGE - 1] = sWaterPledgeDescription,
    [MOVE_FIRE_PLEDGE - 1] = sFirePledgeDescription,
    [MOVE_GRASS_PLEDGE - 1] = sGrassPledgeDescription,
    [MOVE_VOLT_SWITCH - 1] = sUTurnDescription,
    [MOVE_STRUGGLE_BUG - 1] = sStruggleBugDescription,
    [MOVE_BULLDOZE - 1] = sBulldozeDescription,
    [MOVE_FROST_BREATH - 1] = sStormThrowDescription,
    [MOVE_DRAGON_TAIL - 1] = sCircleThrowDescription,
    [MOVE_WORK_UP - 1] = sWorkUpDescription,
    [MOVE_ELECTROWEB - 1] = sElectrowebDescription,
    [MOVE_WILD_CHARGE - 1] = sWildChargeDescription,
    [MOVE_DRILL_RUN - 1] = sDrillRunDescription,
    [MOVE_DUAL_CHOP - 1] = sDualChopDescription,
    [MOVE_HEART_STAMP - 1] = sHeartStampDescription,
    [MOVE_HORN_LEECH - 1] = sMegaDrainDescription,
    [MOVE_SACRED_SWORD - 1] = sChipAwayDescription,
    [MOVE_RAZOR_SHELL - 1] = sRazorShellDescription,
    [MOVE_HEAT_CRASH - 1] = sHeavySlamDescription,
    [MOVE_LEAF_TORNADO - 1] = sLeafTornadoDescription,
    [MOVE_STEAMROLLER - 1] = sSteamrollerDescription,
    [MOVE_COTTON_GUARD - 1] = sCottonGuardDescription,
    [MOVE_NIGHT_DAZE - 1] = sNightDazeDescription,
    [MOVE_PSYSTRIKE - 1] = sPsyshockDescription,
    [MOVE_TAIL_SLAP - 1] = sTailSlapDescription,
    [MOVE_HURRICANE - 1] = sHurricaneDescription,
    [MOVE_HEAD_CHARGE - 1] = sHeadChargeDescription,
    [MOVE_GEAR_GRIND - 1] = sGearGrindDescription,
    [MOVE_SEARING_SHOT - 1] = sLavaPlumeDescription,
    [MOVE_TECHNO_BLAST - 1] = sTechnoBlastDescription,
    [MOVE_RELIC_SONG - 1] = sRelicSongDescription,
    [MOVE_SECRET_SWORD - 1] = sSecretSwordDescription,
    [MOVE_GLACIATE - 1] = sGlaciateDescription,
    [MOVE_BOLT_STRIKE - 1] = sBoltStrikeDescription,
    [MOVE_BLUE_FLARE - 1] = sBlueFlareDescription,
    [MOVE_FIERY_DANCE - 1] = sFieryDanceDescription,
    [MOVE_FREEZE_SHOCK - 1] = sFreezeShockDescription,
    [MOVE_ICE_BURN - 1] = sIceBurnDescription,
    [MOVE_SNARL - 1] = sSnarlDescription,
    [MOVE_ICICLE_CRASH - 1] = sIcicleCrashDescription,
    [MOVE_V_CREATE - 1] = sVCreateDescription,
    [MOVE_FUSION_FLARE - 1] = sFusionFlareDescription,
    [MOVE_FUSION_BOLT - 1] = sFusionBoltDescription,
    [MOVE_FLYING_PRESS - 1] = sFlyingPressDescription,
    [MOVE_MAT_BLOCK - 1] = sMatBlockDescription,
    [MOVE_BELCH - 1] = sBelchDescription,
    [MOVE_ROTOTILLER - 1] = sRototillerDescription,
    [MOVE_STICKY_WEB - 1] = sStickyWebDescription,
    [MOVE_FELL_STINGER - 1] = sFellStingerDescription,
    [MOVE_PHANTOM_FORCE - 1] = sShadowForceDescription,
    [MOVE_TRICK_OR_TREAT - 1] = sTrickOrTreatDescription,
    [MOVE_NOBLE_ROAR - 1] = sNobleRoarDescription,
    [MOVE_ION_DELUGE - 1] = sIonDelugeDescription,
    [MOVE_PARABOLIC_CHARGE - 1] = sParabolicChargeDescription,
    [MOVE_FORESTS_CURSE - 1] = sForestsCurseDescription,
    [MOVE_PETAL_BLIZZARD - 1] = sPetalBlizzardDescription,
    [MOVE_FREEZE_DRY - 1] = sFreezeDryDescription,
    [MOVE_DISARMING_VOICE - 1] = sDisarmingVoiceDescription,
    [MOVE_PARTING_SHOT - 1] = sPartingShotDescription,
    [MOVE_TOPSY_TURVY - 1] = sTopsyTurvyDescription,
    [MOVE_DRAINING_KISS - 1] = sDrainingKissDescription,
    [MOVE_CRAFTY_SHIELD - 1] = sCraftyShieldDescription,
    [MOVE_FLOWER_SHIELD - 1] = sFlowerShieldDescription,
    [MOVE_GRASSY_TERRAIN - 1] = sGrassyTerrainDescription,
    [MOVE_MISTY_TERRAIN - 1] = sMistyTerrainDescription,
    [MOVE_ELECTRIFY - 1] = sElectrifyDescription,
    [MOVE_PLAY_ROUGH - 1] = sPlayRoughDescription,
    [MOVE_FAIRY_WIND - 1] = sFairyWindDescription,
    [MOVE_MOONBLAST - 1] = sMoonblastDescription,
    [MOVE_BOOMBURST - 1] = sBoomburstDescription,
    [MOVE_FAIRY_LOCK - 1] = sFairyLockDescription,
    [MOVE_KINGS_SHIELD - 1] = sKingsShieldDescription,
    [MOVE_PLAY_NICE - 1] = sPlayNiceDescription,
    [MOVE_CONFIDE - 1] = sConfideDescription,
    [MOVE_DIAMOND_STORM - 1] = sDiamondStormDescription,
    [MOVE_STEAM_ERUPTION - 1] = sSteamEruptionDescription,
    [MOVE_HYPERSPACE_HOLE - 1] = sHyperspaceHoleDescription,
    [MOVE_WATER_SHURIKEN - 1] = sWaterShurikenDescription,
    [MOVE_MYSTICAL_FIRE - 1] = sMysticalFireDescription,
    [MOVE_SPIKY_SHIELD - 1] = sSpikyShieldDescription,
    [MOVE_AROMATIC_MIST - 1] = sAromaticMistDescription,
    [MOVE_EERIE_IMPULSE - 1] = sEerieImpulseDescription,
    [MOVE_VENOM_DRENCH - 1] = sVenomDrenchDescription,
    [MOVE_POWDER - 1] = sPowderDescription,
    [MOVE_GEOMANCY - 1] = sGeomancyDescription,
    [MOVE_MAGNETIC_FLUX - 1] = sMagneticFluxDescription,
    [MOVE_HAPPY_HOUR - 1] = sHappyHourDescription,
    [MOVE_ELECTRIC_TERRAIN - 1] = sElectricTerrainDescription,
    [MOVE_DAZZLING_GLEAM - 1] = sDazzlingGleamDescription,
    [MOVE_CELEBRATE - 1] = sCelebrateDescription,
    [MOVE_HOLD_HANDS - 1] = sHoldHandsDescription,
    [MOVE_BABY_DOLL_EYES - 1] = sBabyDollEyesDescription,
    [MOVE_NUZZLE - 1] = sNuzzleDescription,
    [MOVE_HOLD_BACK - 1] = sFalseSwipeDescription,
    [MOVE_INFESTATION - 1] = sInfestationDescription,
    [MOVE_POWER_UP_PUNCH - 1] = sPowerUpPunchDescription,
    [MOVE_OBLIVION_WING - 1] = sDrainingKissDescription,
    [MOVE_THOUSAND_ARROWS - 1] = sThousandArrowsDescription,
    [MOVE_THOUSAND_WAVES - 1] = sThousandWavesDescription,
    [MOVE_LANDS_WRATH - 1] = sLandsWrathDescription,
    [MOVE_LIGHT_OF_RUIN - 1] = sLightOfRuinDescription,
    [MOVE_ORIGIN_PULSE - 1] = sOriginPulseDescription,
    [MOVE_PRECIPICE_BLADES - 1] = sPrecipiceBladesDescription,
    [MOVE_DRAGON_ASCENT - 1] = sCloseCombatDescription,
    [MOVE_HYPERSPACE_FURY - 1] = sHyperspaceHoleDescription,
    [MOVE_SHORE_UP - 1] = sShoreUpDescription,
    [MOVE_FIRST_IMPRESSION - 1] = sFirstImpressionDescription,
    [MOVE_BANEFUL_BUNKER - 1] = sBanefulBunkerDescription,
    [MOVE_SPIRIT_SHACKLE - 1] = sSpiritShackleDescription,
    [MOVE_DARKEST_LARIAT - 1] = sDarkestLariatDescription,
    [MOVE_SPARKLING_ARIA - 1] = sSparklingAriaDescription,
    [MOVE_ICE_HAMMER - 1] = sIceHammerDescription,
    [MOVE_FLORAL_HEALING - 1] = sFloralHealingDescription,
    [MOVE_HIGH_HORSEPOWER - 1] = sHighHorsepowerDescription,
    [MOVE_STRENGTH_SAP - 1] = sStrengthSapDescription,
    [MOVE_SOLAR_BLADE - 1] = sSolarBladeDescription,
    [MOVE_LEAFAGE - 1] = sLeafageDescription,
    [MOVE_SPOTLIGHT - 1] = sSpotlightDescription,
    [MOVE_TOXIC_THREAD - 1] = sToxicThreadDescription,
    [MOVE_LASER_FOCUS - 1] = sLaserFocusDescription,
    [MOVE_GEAR_UP - 1] = sGearUpDescription,
    [MOVE_THROAT_CHOP - 1] = sThroatChopDescription,
    [MOVE_POLLEN_PUFF - 1] = sPollenPuffDescription,
    [MOVE_ANCHOR_SHOT - 1] = sAnchorShotDescription,
    [MOVE_PSYCHIC_TERRAIN - 1] = sPsychicTerrainDescription,
    [MOVE_LUNGE - 1] = sLungeDescription,
    [MOVE_FIRE_LASH - 1] = sFireLashDescription,
    [MOVE_POWER_TRIP - 1] = sPowerTripDescription,
    [MOVE_BURN_UP - 1] = sBurnUpDescription,
    [MOVE_SPEED_SWAP - 1] = sSpeedSwapDescription,
    [MOVE_SMART_STRIKE - 1] = sSmartStrikeDescription,
    [MOVE_PURIFY - 1] = sPurifyDescription,
    [MOVE_REVELATION_DANCE - 1] = sRevelationDanceDescription,
    [MOVE_CORE_ENFORCER - 1] = sCoreEnforcerDescription,
    [MOVE_TROP_KICK - 1] = sTropKickDescription,
    [MOVE_INSTRUCT - 1] = sInstructDescription,
    [MOVE_BEAK_BLAST - 1] = sBeakBlastDescription,
    [MOVE_CLANGING_SCALES - 1] = sClangingScalesDescription,
    [MOVE_DRAGON_HAMMER - 1] = sDragonHammerDescription,
    [MOVE_BRUTAL_SWING - 1] = sBrutalSwingDescription,
    [MOVE_AURORA_VEIL - 1] = sAuroraVeilDescription,
    [MOVE_SHELL_TRAP - 1] = sShellTrapDescription,
    [MOVE_FLEUR_CANNON - 1] = sFleurCannonDescription,
    [MOVE_PSYCHIC_FANGS - 1] = sPsychicFangsDescription,
    [MOVE_STOMPING_TANTRUM - 1] = sStompingTantrumDescription,
    [MOVE_SHADOW_BONE - 1] = sShadowBoneDescription,
    [MOVE_ACCELEROCK - 1] = sAccelerockDescription,
    [MOVE_LIQUIDATION - 1] = sLiquidationDescription,
    [MOVE_PRISMATIC_LASER - 1] = sPrismaticLaserDescription,
    [MOVE_SPECTRAL_THIEF - 1] = sSpectralThiefDescription,
    [MOVE_SUNSTEEL_STRIKE - 1] = sSunsteelStrikeDescription,
    [MOVE_MOONGEIST_BEAM - 1] = sMoongeistBeamDescription,
    [MOVE_TEARFUL_LOOK - 1] = sTearfulLookDescription,
    [MOVE_ZING_ZAP - 1] = sZingZapDescription,
    [MOVE_NATURES_MADNESS - 1] = sNaturesMadnessDescription,
    [MOVE_MULTI_ATTACK - 1] = sMultiAttackDescription,
    [MOVE_MIND_BLOWN - 1] = sMindBlownDescription,
    [MOVE_PLASMA_FISTS - 1] = sPlasmaFistsDescription,
    [MOVE_PHOTON_GEYSER - 1] = sPhotonGeyserDescription,
    [MOVE_ZIPPY_ZAP - 1] = sZippyZapDescription,
    [MOVE_SPLISHY_SPLASH - 1] = sSplishySplashDescription,
    [MOVE_FLOATY_FALL - 1] = sFloatyFallDescription,
    [MOVE_PIKA_PAPOW - 1] = sPikaPapowDescription,
    [MOVE_BOUNCY_BUBBLE - 1] = sBouncyBubbleDescription,
    [MOVE_BUZZY_BUZZ - 1] = sBuzzyBuzzDescription,
    [MOVE_SIZZLY_SLIDE - 1] = sSizzlySlideDescription,
    [MOVE_GLITZY_GLOW - 1] = sGlitzyGlowDescription,
    [MOVE_BADDY_BAD - 1] = sBaddyBadDescription,
    [MOVE_SAPPY_SEED - 1] = sSappySeedDescription,
    [MOVE_FREEZY_FROST - 1] = sFreezyFrostDescription,
    [MOVE_SPARKLY_SWIRL - 1] = sSparklySwirlDescription,
    [MOVE_VEEVEE_VOLLEY - 1] = sVeeveeVolleyDescription,
    [MOVE_DOUBLE_IRON_BASH - 1] = sDoubleIronBashDescription,

    //GEN 8
    [MOVE_DYNAMAX_CANNON - 1] = sDynamaxCannonDescription,
    [MOVE_SNIPE_SHOT - 1] = sSnipeShotDescription,
    [MOVE_JAW_LOCK - 1] = sJawLockDescription,
    [MOVE_STUFF_CHEEKS - 1] = sStuffCheeksDescription,
    [MOVE_NO_RETREAT - 1] = sNoRetreatDescription,
    [MOVE_TAR_SHOT - 1] = sTarShotDescription,
    [MOVE_MAGIC_POWDER - 1] = sMagicPowderDescription,
    [MOVE_DRAGON_DARTS - 1] = sDragonDartsDescription,
    [MOVE_TEATIME - 1] = sTeatimeDescription,
    [MOVE_OCTOLOCK - 1] = sOctolockDescription,
    [MOVE_BOLT_BEAK - 1] = sBoltBeakDescription,
    [MOVE_FISHIOUS_REND - 1] = sFishiousRendDescription,
    [MOVE_COURT_CHANGE - 1] = sCourtChangeDescription,
    [MOVE_CLANGOROUS_SOUL - 1] = sClangorousSoulDescription,
    [MOVE_BODY_PRESS - 1] = sBodyPressDescription,
    [MOVE_DECORATE - 1] = sDecorateDescription,
    [MOVE_DRUM_BEATING - 1] = sDrumBeatingDescription,
    [MOVE_SNAP_TRAP - 1] = sSnapTrapDescription,
    [MOVE_PYRO_BALL - 1] = sPyroBallDescription,
    [MOVE_BEHEMOTH_BLADE - 1] = sBehemothBladeDescription,
    [MOVE_BEHEMOTH_BASH - 1] = sBehemothBashDescription,
    [MOVE_AURA_WHEEL - 1] = sAuraWheelDescription,
    [MOVE_BREAKING_SWIPE - 1] = sBreakingSwipeDescription,
    [MOVE_BRANCH_POKE - 1] = sBranchPokeDescription,
    [MOVE_OVERDRIVE - 1] = sOverdriveDescription,
    [MOVE_APPLE_ACID - 1] = sAppleAcidDescription,
    [MOVE_GRAV_APPLE - 1] = sGravAppleDescription,
    [MOVE_SPIRIT_BREAK - 1] = sSpiritBreakDescription,
    [MOVE_STRANGE_STEAM - 1] = sStrangeSteamDescription,
    [MOVE_LIFE_DEW - 1] = sLifeDewDescription,
    [MOVE_OBSTRUCT - 1] = sObstructDescription,
    [MOVE_FALSE_SURRENDER - 1] = sFalseSurrenderDescription,
    [MOVE_METEOR_ASSAULT - 1] = sMeteorAssaultDescription,
    [MOVE_ETERNABEAM - 1] = sEternabeamDescription,
    [MOVE_STEEL_BEAM - 1] = sSteelBeamDescription,
    [MOVE_EXPANDING_FORCE - 1] = sExpandingForceDescription,
    [MOVE_STEEL_ROLLER - 1] = sSteelRollerDescription,
    [MOVE_SCALE_SHOT - 1] = sScaleShotDescription,
    [MOVE_METEOR_BEAM - 1] = sMeteorBeamDescription,
    [MOVE_SHELL_SIDE_ARM - 1] = sShellSideArmDescription,
    [MOVE_MISTY_EXPLOSION - 1] = sMistyExplosionDescription,
    [MOVE_GRASSY_GLIDE - 1] = sGrassyGlideDescription,
    [MOVE_RISING_VOLTAGE - 1] = sRisingVoltageDescription,
    [MOVE_TERRAIN_PULSE - 1] = sTerrainPulseDescription,
    [MOVE_SKITTER_SMACK - 1] = sSkitterSmackDescription,
    [MOVE_BURNING_JEALOUSY - 1] = sBurningJealousyDescription,
    [MOVE_LASH_OUT - 1] = sLashOutDescription,
    [MOVE_POLTERGEIST - 1] = sPoltergeistDescription,
    [MOVE_CORROSIVE_GAS - 1] = sCorrosiveGasDescription,
    [MOVE_COACHING - 1] = sCoachingDescription,
    [MOVE_FLIP_TURN - 1] = sFlipTurnDescription,
    [MOVE_TRIPLE_AXEL - 1] = sTripleAxelDescription,
    [MOVE_DUAL_WINGBEAT - 1] = sDualWingbeatDescription,
    [MOVE_SCORCHING_SANDS - 1] = sScorchingSandsDescription,
    [MOVE_JUNGLE_HEALING - 1] = sJungleHealingDescription,
    [MOVE_WICKED_BLOW - 1] = sWickedBlowDescription,
    [MOVE_SURGING_STRIKES - 1] = sSurgingStrikesDescription,
    [MOVE_THUNDER_CAGE - 1] = sThunderCageDescription,
    [MOVE_DRAGON_ENERGY - 1] = sDragonEnergyDescription,
    [MOVE_FREEZING_GLARE - 1] = sFreezingGlareDescription,
    [MOVE_FIERY_WRATH - 1] = sFieryWrathDescription,
    [MOVE_THUNDEROUS_KICK - 1] = sThunderousKickDescription,
    [MOVE_GLACIAL_LANCE - 1] = sGlacialLanceDescription,
    [MOVE_ASTRAL_BARRAGE - 1] = sAstralBarrageDescription,
    [MOVE_EERIE_SPELL - 1] = sEerieSpellDescription,
    [MOVE_DIRE_CLAW - 1] = sDireClawDescription,
    [MOVE_PSYSHIELD_BASH - 1] = sPsyshieldBashDescription,
    [MOVE_POWER_SHIFT - 1] = sPowerShiftDescription,
    [MOVE_STONE_AXE - 1] = sStoneAxeDescription,
    [MOVE_SPRINGTIDE_STORM - 1] = sSpringtideStormDescription,
    [MOVE_MYSTICAL_POWER - 1] = sMysticalPowerDescription,
    [MOVE_RAGING_FURY - 1] = sRagingFuryDescription,
    [MOVE_WAVE_CRASH - 1] = sWaveCrashDescription,
    [MOVE_CHLOROBLAST - 1] = sChloroblastDescription,
    [MOVE_MOUNTAIN_GALE - 1] = sMountainGaleDescription,
    [MOVE_VICTORY_DANCE - 1] = sVictoryDanceDescription,
    [MOVE_HEADLONG_RUSH - 1] = sHeadlongRushDescription,
    [MOVE_BARB_BARRAGE - 1] = sBarbBarrageDescription,
    [MOVE_ESPER_WING - 1] = sEsperWingDescription,
    [MOVE_BITTER_MALICE - 1] = sBitterMaliceDescription,
    [MOVE_SHELTER - 1] = sShelterDescription,
    [MOVE_TRIPLE_ARROWS - 1] = sTripleArrowsDescription,
    [MOVE_INFERNAL_PARADE - 1] = sInfernalParadeDescription,
    [MOVE_CEASELESS_EDGE - 1] = sCeaselessEdgeDescription,
    [MOVE_BLEAKWIND_STORM - 1] = sBleakwindStormDescription,
    [MOVE_WILDBOLT_STORM - 1] = sWildboltStormDescription,
    [MOVE_SANDSEAR_STORM - 1] = sSandsearStormDescription,
    [MOVE_LUNAR_BLESSING - 1] = sLunarBlessingDescription,
    [MOVE_TAKE_HEART - 1] = sTakeHeartDescription,
    [MOVE_TERA_BLAST - 1] = sTeraBlastDescription,
    [MOVE_SILK_TRAP - 1] = sSilkTrapDescription,
    [MOVE_AXE_KICK - 1] = sAxeKickDescription,
    [MOVE_LAST_RESPECTS - 1] = sLastRespectsDescription,
    [MOVE_LUMINA_CRASH - 1] = sLuminaCrashDescription,
    [MOVE_ORDER_UP - 1] = sOrderUpDescription,
    [MOVE_JET_PUNCH - 1] = sJetPunchDescription,
    [MOVE_SPICY_EXTRACT - 1] = sSpicyExtractDescription,
    [MOVE_SPIN_OUT - 1] = sSpinOutDescription,
    [MOVE_POPULATION_BOMB - 1] = sPopulationBombDescription,
    [MOVE_ICE_SPINNER - 1] = sIceSpinnerDescription,
    [MOVE_GLAIVE_RUSH - 1] = sGlaiveRushDescription,
    [MOVE_REVIVAL_BLESSING - 1] = sRevivalBlessingDescription,
    [MOVE_SALT_CURE - 1] = sSaltCureDescription,
    [MOVE_TRIPLE_DIVE - 1] = sTripleDiveDescription,
    [MOVE_MORTAL_SPIN - 1] = sMortalSpinDescription,
    [MOVE_DOODLE - 1] = sDoodleDescription,
    [MOVE_FILLET_AWAY - 1] = sFilletAwayDescription,
    [MOVE_KOWTOW_CLEAVE - 1] = sKowtowCleaveDescription,
    [MOVE_FLOWER_TRICK - 1] = sFlowerTrickDescription,
    [MOVE_TORCH_SONG - 1] = sTorchSongDescription,
    [MOVE_AQUA_STEP - 1] = sAquaStepDescription,
    [MOVE_RAGING_BULL - 1] = sRagingBullDescription,
    [MOVE_MAKE_IT_RAIN - 1] = sMakeItRainDescription,
    [MOVE_RUINATION - 1] = sRuinationDescription,
    [MOVE_COLLISION_COURSE - 1] = sCollisionCourseDescription,
    [MOVE_ELECTRO_DRIFT - 1] = sElectroDriftDescription,
    [MOVE_SHED_TAIL - 1] = sShedTailDescription,
    [MOVE_CHILLY_RECEPTION - 1] = sChillyReceptionDescription,
    [MOVE_TIDY_UP - 1] = sTidyUpDescription,
    [MOVE_SNOWSCAPE - 1] = sSnowscapeDescription,
    [MOVE_POUNCE - 1] = sPounceDescription,
    [MOVE_TRAILBLAZE - 1] = sTrailblazeDescription,
    [MOVE_CHILLING_WATER - 1] = sChillingWaterDescription,
    [MOVE_HYPER_DRILL - 1] = sHyperDrillDescription,
    [MOVE_TWIN_BEAM - 1] = sTwinBeamDescription,
    [MOVE_RAGE_FIST - 1] = sRageFistDescription,
    [MOVE_ARMOR_CANNON - 1] = sArmorCannonDescription,
    [MOVE_BITTER_BLADE - 1] = sBitterBladeDescription,
    [MOVE_DOUBLE_SHOCK - 1] = sDoubleShockDescription,
    [MOVE_GIGATON_HAMMER - 1] = sGigatonHammerDescription,
    [MOVE_COMEUPPANCE - 1] = sComeuppanceDescription,
    [MOVE_AQUA_CUTTER - 1] = sAquaCutterDescription,
    [MOVE_BLAZING_TORQUE - 1] = sBlazingTorqueDescription,
    [MOVE_WICKED_TORQUE - 1] = sWickedTorqueDescription,
    [MOVE_NOXIOUS_TORQUE - 1] = sNoxiousTorqueDescription,
    [MOVE_COMBAT_TORQUE - 1] = sCombatTorqueDescription,
    [MOVE_MAGICAL_TORQUE - 1] = sMagicalTorqueDescription,
    [MOVE_PSYBLADE - 1] = sPsybladeDescription,
    [MOVE_HYDRO_STEAM - 1] = sHydroSteamDescription,
    [MOVE_BLOOD_MOON - 1] = sBloodMoonDescription,
    [MOVE_MATCHA_GOTCHA - 1] = sMatchaGotchaDescription,
    [MOVE_SYRUP_BOMB - 1] = sSyrupBombDescription,
    [MOVE_IVY_CUDGEL - 1] = sIvyCudgelDescription,
    [MOVE_ELECTRO_SHOT - 1] = sElectroShotDescription,
    [MOVE_TERA_STARSTORM - 1] = sTeraStarstormDescription,
    [MOVE_FICKLE_BEAM - 1] = sFickleBeamDescription,
    [MOVE_BURNING_BULWARK - 1] = sBurningBulwarkDescription,
    [MOVE_THUNDERCLAP - 1] = sSuckerPunchDescription,
    [MOVE_MIGHTY_CLEAVE - 1] = sFeintDescription,
    [MOVE_TACHYON_CUTTER - 1] = sTachyonCutterDescription,
    [MOVE_HARD_PRESS - 1] = sWringOutDescription,
    [MOVE_DRAGON_CHEER - 1] = sDragonCheerDescription,
    [MOVE_ALLURING_VOICE - 1] = sAlluringVoiceDescription,
    [MOVE_TEMPER_FLARE - 1] = sTemperFlareDescription,
    [MOVE_SUPERCELL_SLAM - 1] = sSupercellSlamDescription,
    [MOVE_PSYCHIC_NOISE - 1] = sPsychicNoiseDescription,
    [MOVE_UPPER_HAND - 1] = sUpperHandDescription,
    [MOVE_MALIGNANT_CHAIN - 1] = sMalignantChainDescription,

    [MOVE_SWIRLING_BLADE - 1] = sNullDescription,
};
