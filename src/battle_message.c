#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

#include "rogue_controller.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

static void ChooseMoveUsedParticle(u8 *textPtr);
static void ChooseTypeOfMoveUsedString(u8 *dst);

static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_Trainer1LoseText[] = _("{B_TRAINER1_LOSE_TEXT}");
//static const u8 sText_PkmnGainedEXP[] = _("¡El equipo ha ganado puntos de EXP.!\p");
//static const u8 sText_PkmnGainedEXP[] = _("¡{B_BUFF1} ha ganado{B_BUFF2}\n{B_BUFF3} puntos de EXP.!\p");
static const u8 sText_PkmnGainedEXP[] = _("¡{B_BUFF1} ha ganado{B_BUFF2}\nalgunos puntos de EXP.!\p");
static const u8 sText_EmptyString4[] = _("");
static const u8 sText_ABoosted[] = _(" extra");
static const u8 sText_PkmnGrewToLv[] = _("¡{B_BUFF1} ha subido al\nNV. {B_BUFF2}!\p");
static const u8 sText_TeamGrewToLv[] = _("¡Todos han subido al\nNV. {B_BUFF2}!\p");
static const u8 sText_PkmnLearnedMove[] = _("¡{B_BUFF1} ha aprendido\n{B_BUFF2}!\p");
static const u8 sText_TryToLearnMove1[] = _("{B_BUFF1} quiere\naprender {B_BUFF2}.\p");
static const u8 sText_TryToLearnMove2[] = _("Pero {B_BUFF1} no puede saber\nmás de cuatro movimientos.\p");
static const u8 sText_TryToLearnMove3[] = _("¿Olvidar un movimiento para\ndejar sitio a {B_BUFF2}?");
static const u8 sText_PkmnForgotMove[] = _("{B_BUFF1} ha olvidado\n{B_BUFF2}.\p");
static const u8 sText_StopLearningMove[] = _("{PAUSE 32}¿Dejar de aprender\n{B_BUFF2}?");
static const u8 sText_DidNotLearnMove[] = _("{B_BUFF1} no ha aprendido\n{B_BUFF2}.\p");
static const u8 sText_UseNextPkmn[] = _("¿Usar otro Pokémon?");
static const u8 sText_AttackMissed[] = _("¡El ataque de\n{B_ATK_NAME_WITH_PREFIX} ha fallado!");
static const u8 sText_PkmnProtectedItself[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nse ha protegido!");
static const u8 sText_AvoidedDamage[] = _("¡{B_DEF_NAME_WITH_PREFIX} evita el\ndaño con {B_DEF_ABILITY}!");
static const u8 sText_PkmnMakesGroundMiss[] = _("¡{B_DEF_NAME_WITH_PREFIX} esquiva los movs.\nde TIERRA con {B_DEF_ABILITY}!");
static const u8 sText_PkmnAvoidedAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nesquivado el ataque!");
static const u8 sText_ItDoesntAffect[] = _("No afecta a\n{B_DEF_NAME_WITH_PREFIX}…");
static const u8 sText_AttackerFainted[] = _("¡{B_ATK_NAME_WITH_PREFIX}\nse ha debilitado!\p");
static const u8 sText_TargetFainted[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nse ha debilitado!\p");
static const u8 sText_PlayerGotMoney[] = _("¡{B_PLAYER_NAME} ha ganado\n¥{B_BUFF1} por la victoria!\p");
static const u8 sText_PlayerLostToEnemyTrainer[] = _("¡A {B_PLAYER_NAME} no le quedan\nPokémon que puedan luchar!\p¡Has perdido contra\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerPaidPrizeMoney[] = _("… … … …\p¡{B_PLAYER_NAME} se ha desmayado!{PAUSE_UNTIL_PRESS}");
static const u8 sText_PlayerWhiteout[] = _("¡A {B_PLAYER_NAME} no le quedan\nPokémon que puedan luchar!\p");
#if B_WHITEOUT_MONEY >= GEN_4
static const u8 sText_PlayerWhiteout2[] = _("{B_PLAYER_NAME} se asusta y pierde ¥{B_BUFF1}…\p… … … …\p¡{B_PLAYER_NAME} se ha desmayado!{PAUSE_UNTIL_PRESS}");
#else
static const u8 sText_PlayerWhiteout2[] = _("¡{B_PLAYER_NAME} se ha desmayado!{PAUSE_UNTIL_PRESS}");
#endif
static const u8 sText_PreventsEscape[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} impide huir\ncon {B_SCR_ACTIVE_ABILITY}!\p");
static const u8 sText_CantEscape2[] = _("¡No puedes huir!\p");
static const u8 sText_AttackerCantEscape[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede huir!");
static const u8 sText_HitXTimes[] = _("¡Número de golpes: {B_BUFF1}!");
static const u8 sText_PkmnFellAsleep[] = _("¡{B_EFF_NAME_WITH_PREFIX}\nse ha dormido!");
static const u8 sText_PkmnMadeSleep[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha dormido a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyAsleep[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nestá dormido!");
static const u8 sText_PkmnAlreadyAsleep2[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya\nestá dormido!");
static const u8 sText_PkmnWasntAffected[] = _("¡A {B_DEF_NAME_WITH_PREFIX}\nno le ha afectado!");
static const u8 sText_PkmnWasPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX}\nha sido envenenado!");
static const u8 sText_PkmnPoisonedBy[] = _("¡{B_EFF_NAME_WITH_PREFIX} ha sido envenenado\npor {B_BUFF1} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByPoison[] = _("¡El veneno resta PS a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyPoisoned[] = _("{B_DEF_NAME_WITH_PREFIX} ya está\nenvenenado.");
static const u8 sText_PkmnBadlyPoisoned[] = _("¡{B_EFF_NAME_WITH_PREFIX} está\ngravemente envenenado!");
static const u8 sText_PkmnEnergyDrained[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha perdido\nenergía!");
static const u8 sText_PkmnWasBurned[] = _("¡{B_EFF_NAME_WITH_PREFIX} se ha quemado!");
static const u8 sText_PkmnGotFrostbite[] = _("¡{B_EFF_NAME_WITH_PREFIX} tiene congelación!");
static const u8 sText_PkmnBurnedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha quemado a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByBurn[] = _("¡La quemadura resta PS a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtByFrostbite[] = _("¡La congelación resta PS a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAlreadyHasBurn[] = _("{B_DEF_NAME_WITH_PREFIX} ya\nestá quemado.");
static const u8 sText_PkmnWasFrozen[] = _("¡{B_EFF_NAME_WITH_PREFIX} se ha\nquedado congelado!");
static const u8 sText_PkmnFrozenBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha congelado a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIsFrozen[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\ncongelado!");
static const u8 sText_PkmnWasDefrosted[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha\ndescongelado!");
static const u8 sText_PkmnWasDefrosted2[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\ndescongelado!");
static const u8 sText_PkmnWasDefrostedBy[] = _("¡{B_CURRENT_MOVE} ha descongelado\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFrostbiteHealed[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha\ncurado de la congelación!");
static const u8 sText_PkmnFrostbiteHealed2[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\ncurado de la congelación!");
static const u8 sText_PkmnFrostbiteHealedBy[] = _("¡{B_CURRENT_MOVE} ha curado la\ncongelación de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWasParalyzed[] = _("¡{B_EFF_NAME_WITH_PREFIX} está paralizado!\n¡Puede que no se mueva!");
static const u8 sText_PkmnWasParalyzedBy[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha paralizado a {B_EFF_NAME_WITH_PREFIX}!\l¡Puede que no se mueva!");
static const u8 sText_PkmnIsParalyzed[] = _("¡{B_ATK_NAME_WITH_PREFIX} está paralizado!\n¡No se puede mover!");
static const u8 sText_PkmnIsAlreadyParalyzed[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nestá paralizado!");
static const u8 sText_PkmnHealedParalysis[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya no\nestá paralizado!");
static const u8 sText_PkmnDreamEaten[] = _("¡Se han comido el sueño de\n{B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_StatsWontIncrease[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\nno puede subir más!");
static const u8 sText_StatsWontDecrease[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nno puede bajar más!");
static const u8 sText_TeamStoppedWorking[] = _("¡{B_BUFF1} de tu equipo\nha dejado de funcionar!");
static const u8 sText_FoeStoppedWorking[] = _("¡{B_BUFF1} del rival\nha dejado de funcionar!");
static const u8 sText_PkmnIsConfused[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nconfuso!");
static const u8 sText_PkmnHealedConfusion[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya no\nestá confuso!");
static const u8 sText_PkmnWasConfused[] = _("¡{B_EFF_NAME_WITH_PREFIX} se ha\nquedado confuso!");
static const u8 sText_PkmnAlreadyConfused[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya\nestá confuso!");
static const u8 sText_PkmnFellInLove[] = _("¡{B_DEF_NAME_WITH_PREFIX}\nse ha enamorado!");
static const u8 sText_PkmnInLove[] = _("¡{B_ATK_NAME_WITH_PREFIX} está enamorado\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnImmobilizedByLove[] = _("¡El amor impide atacar a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBlownAway[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nsalido despedido!");
static const u8 sText_PkmnChangedType[] = _("¡{B_ATK_NAME_WITH_PREFIX} ahora es\nde tipo {B_BUFF1}!");
static const u8 sText_PkmnFlinched[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha retrocedido!");
static const u8 sText_PkmnRegainedHealth[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nrecuperado salud!");
static const u8 sText_PkmnHPFull[] = _("¡{B_DEF_NAME_WITH_PREFIX} tiene\nlos PS al máximo!");
static const u8 sText_PkmnRaisedSpDef[] = _("¡{B_CURRENT_MOVE} del equipo\n{B_ATK_PREFIX2} sube la DEF. ESP.!");
static const u8 sText_PkmnRaisedSpDefALittle[] = _("¡{B_CURRENT_MOVE} del equipo {B_ATK_PREFIX2}\nsube un poco la DEF. ESP.!");
static const u8 sText_PkmnRaisedDef[] = _("¡{B_CURRENT_MOVE} del equipo\n{B_ATK_PREFIX2} sube la DEFENSA!");
static const u8 sText_PkmnRaisedDefALittle[] = _("¡{B_CURRENT_MOVE} del equipo {B_ATK_PREFIX2}\nsube un poco la DEFENSA!");
static const u8 sText_PkmnCoveredByVeil[] = _("¡Un velo cubre al\nequipo {B_ATK_PREFIX2}!");
static const u8 sText_PkmnUsedSafeguard[] = _("¡Velo Sagrado protege al\nequipo de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSafeguardExpired[] = _("¡Velo Sagrado ya no protege\nal equipo {B_ATK_PREFIX3}!");
static const u8 sText_PkmnWentToSleep[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\ndormido!");
static const u8 sText_PkmnSleptHealthy[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha dormido\ny se ha recuperado!");
static const u8 sText_PkmnWhippedWhirlwind[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha levantado\nun remolino!");
static const u8 sText_PkmnTookSunlight[] = _("¡{B_ATK_NAME_WITH_PREFIX} absorbe\nla luz del sol!");
static const u8 sText_PkmnLoweredHead[] = _("¡{B_ATK_NAME_WITH_PREFIX} agacha\nla cabeza!");
static const u8 sText_PkmnIsGlowing[] = _("¡{B_ATK_NAME_WITH_PREFIX} está brillando!");
static const u8 sText_PkmnFlewHigh[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha volado\nmuy alto!");
static const u8 sText_PkmnDugHole[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha cavado un hoyo!");
static const u8 sText_PkmnHidUnderwater[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nsumergido!");
static const u8 sText_PkmnSprangUp[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha saltado!");
static const u8 sText_PkmnSqueezedByBind[] = _("¡ATADURA de {B_ATK_NAME_WITH_PREFIX}\noprime a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnInSnapTrap[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha caído\nen un cepo!");
static const u8 sText_PkmnTrappedInVortex[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha quedado\natrapado en el torbellino!");
static const u8 sText_PkmnTrappedBySandTomb[] = _("¡BUCLE ARENA ha atrapado\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWrappedBy[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha ENROSCADO\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnClamped[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha atenazado\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnHurtBy[] = _("¡{B_BUFF1} resta PS a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFreedFrom[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nliberado de {B_BUFF1}!");
static const u8 sText_PkmnCrashed[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha seguido\ny se ha estrellado!");
const u8 gText_PkmnShroudedInMist[] = _("¡La NEBLINA envuelve al\nequipo {B_ATK_PREFIX2}!");
static const u8 sText_PkmnProtectedByMist[] = _("¡La NEBLINA protege a\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
const u8 gText_PkmnGettingPumped[] = _("¡{B_DEF_NAME_WITH_PREFIX} se está\nconcentrando!");
static const u8 sText_PkmnHitWithRecoil[] = _("¡{B_ATK_NAME_WITH_PREFIX} sufre\nel retroceso!");
static const u8 sText_PkmnProtectedItself2[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nprotegido!");
static const u8 sText_PkmnBuffetedBySandstorm[] = _("¡La tormenta de arena golpea\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPeltedByHail[] = _("¡El GRANIZO golpea a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXWoreOff[] = _("¡{B_BUFF1} del equipo {B_ATK_PREFIX1}\nha terminado!");
static const u8 sText_PkmnSeeded[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha sido plantado!");
static const u8 sText_PkmnEvadedAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nesquivado el ataque!");
static const u8 sText_PkmnSappedByLeechSeed[] = _("¡DRENADORAS resta salud a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnFastAsleep[] = _("{B_ATK_NAME_WITH_PREFIX} está\nprofundamente dormido.");
static const u8 sText_PkmnWokeUp[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha despertado!");
static const u8 sText_PkmnUproarKeptAwake[] = _("¡Pero el ALBOROTO de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlo mantiene despierto!");
static const u8 sText_PkmnWokeUpInUproar[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\ndespertado con el ALBOROTO!");
static const u8 sText_PkmnCausedUproar[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nmontado un ALBOROTO!");
static const u8 sText_PkmnMakingUproar[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nmontando un ALBOROTO!");
static const u8 sText_PkmnCalmedDown[] = _("{B_ATK_NAME_WITH_PREFIX} se ha calmado.");
static const u8 sText_PkmnCantSleepInUproar[] = _("¡Pero {B_DEF_NAME_WITH_PREFIX} no puede\ndormir con el ALBOROTO!");
static const u8 sText_PkmnStockpiled[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nreservado {B_BUFF1}!");
static const u8 sText_PkmnCantStockpile[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede\nreservar más!");
static const u8 sText_PkmnCantSleepInUproar2[] = _("¡Pero {B_DEF_NAME_WITH_PREFIX} no puede\ndormir con el ALBOROTO!");
static const u8 sText_UproarKeptPkmnAwake[] = _("¡Pero el ALBOROTO mantiene\ndespierto a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnStayedAwakeUsing[] = _("¡{B_DEF_NAME_WITH_PREFIX} sigue despierto\ngracias a {B_DEF_ABILITY}!");
static const u8 sText_PkmnStoringEnergy[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nacumulando energía!");
static const u8 sText_PkmnUnleashedEnergy[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha liberado\nsu energía!");
static const u8 sText_PkmnFatigueConfusion[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nconfuso por el cansancio!");
static const u8 sText_PlayerPickedUpMoney[] = _("¡{B_PLAYER_NAME} ha recogido\n¥{B_BUFF1}!\p");
static const u8 sText_PkmnUnaffected[] = _("¡A {B_DEF_NAME_WITH_PREFIX}\nno le afecta!");
static const u8 sText_PkmnTransformedInto[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\ntransformado en {B_BUFF1}!");
static const u8 sText_PkmnMadeSubstitute[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha creado\nun SUSTITUTO!");
static const u8 sText_PkmnHasSubstitute[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya\ntiene un SUSTITUTO!");
static const u8 sText_SubstituteDamaged[] = _("¡El SUSTITUTO recibe el daño\nen lugar de {B_DEF_NAME_WITH_PREFIX}!\p");
static const u8 sText_PkmnSubstituteFaded[] = _("¡El SUSTITUTO de\n{B_DEF_NAME_WITH_PREFIX} ha desaparecido!\p");
static const u8 sText_PkmnMustRecharge[] = _("¡{B_ATK_NAME_WITH_PREFIX} necesita\nrecargar energía!");
static const u8 sText_PkmnRageBuilding[] = _("¡La FURIA de\n{B_DEF_NAME_WITH_PREFIX} aumenta!");
static const u8 sText_PkmnMoveWasDisabled[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nha quedado anulado!");
static const u8 sText_PkmnMoveDisabledNoMore[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya no\ntiene movs. anulados!");
static const u8 sText_PkmnGotEncore[] = _("¡{B_DEF_NAME_WITH_PREFIX} tiene\nque repetir por OTRA VEZ!");
static const u8 sText_PkmnEncoreEnded[] = _("¡Se ha acabado OTRA VEZ\nde {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTookAim[] = _("¡{B_ATK_NAME_WITH_PREFIX} apunta\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSketchedMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nESQUEMATIZADO {B_BUFF1}!");
static const u8 sText_PkmnTryingToTakeFoe[] = _("¡{B_ATK_NAME_WITH_PREFIX} intenta\nllevarse al rival con él!");
static const u8 sText_PkmnTookFoe[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha llevado\na {B_ATK_NAME_WITH_PREFIX} con él!");
static const u8 sText_PkmnReducedPP[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\npierde {B_BUFF2} PP!");
static const u8 sText_PkmnStoleItem[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha robado\n{B_LAST_ITEM} a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetCantEscapeNow[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya no\npuede huir!");
static const u8 sText_PkmnFellIntoNightmare[] = _("¡{B_DEF_NAME_WITH_PREFIX} tiene\nuna PESADILLA!");
static const u8 sText_PkmnLockedInNightmare[] = _("¡{B_ATK_NAME_WITH_PREFIX} sigue\nen una PESADILLA!");
static const u8 sText_PkmnLaidCurse[] = _("¡{B_ATK_NAME_WITH_PREFIX} sacrifica PS y\nMALDICE a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAfflictedByCurse[] = _("¡La MALDICIÓN afecta a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_SpikesScattered[] = _("¡Hay púas esparcidas alrededor\ndel equipo {B_DEF_TEAM2}!");
static const u8 sText_PkmnHurtBySpikes[] = _("¡Las púas hieren a\n{B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnIdentified[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nidentificado a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPerishCountFell[] = _("¡La cuenta de CANTO MORTAL de\n{B_ATK_NAME_WITH_PREFIX} baja a {B_BUFF1}!");
static const u8 sText_PkmnBracedItself[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nprepara para aguantar!");
static const u8 sText_PkmnEnduredHit[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nAGUANTADO el golpe!");
static const u8 sText_MagnitudeStrength[] = _("¡MAGNITUD {B_BUFF1}!");
static const u8 sText_PkmnCutHPMaxedAttack[] = _("¡{B_ATK_NAME_WITH_PREFIX} sacrifica PS\ny maximiza su ATAQUE!");
static const u8 sText_PkmnCopiedStatChanges[] = _("¡{B_ATK_NAME_WITH_PREFIX} copia los cambios\nde características de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnGotFree[] = _("¡{B_ATK_NAME_WITH_PREFIX} se libra de\n{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnShedLeechSeed[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nquitado DRENADORAS!");
static const u8 sText_PkmnBlewAwaySpikes[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nbarrido las púas!");
static const u8 sText_PkmnFledFromBattle[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha huido\ndel combate!");
static const u8 sText_PkmnForesawAttack[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nprevisto un ataque!");
static const u8 sText_PkmnTookAttack[] = _("¡{B_DEF_NAME_WITH_PREFIX} recibe\nel ataque {B_BUFF1}!");
static const u8 sText_PkmnChoseXAsDestiny[] = _("¡{B_ATK_NAME_WITH_PREFIX} confía su\ndestino a {B_CURRENT_MOVE}!");
static const u8 sText_PkmnAttack[] = _("¡Ataque de {B_BUFF1}!");
static const u8 sText_PkmnCenterAttention[] = _("¡{B_DEF_NAME_WITH_PREFIX} es el\ncentro de atención!");
static const u8 sText_PkmnChargingPower[] = _("¡{B_ATK_NAME_WITH_PREFIX} empieza\na cargar energía!");
static const u8 sText_NaturePowerTurnedInto[] = _("¡ADAPTACIÓN se ha convertido\nen {B_CURRENT_MOVE}!");
static const u8 sText_PkmnStatusNormal[] = _("¡El estado de {B_ATK_NAME_WITH_PREFIX}\nha vuelto a la normalidad!");
static const u8 sText_PkmnSubjectedToTorment[] = _("¡{B_DEF_NAME_WITH_PREFIX} sufre\nun TORMENTO!");
static const u8 sText_PkmnTighteningFocus[] = _("¡{B_ATK_NAME_WITH_PREFIX} se está\nconcentrando!");
static const u8 sText_PkmnFellForTaunt[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha caído\nen la Mofa!");
static const u8 sText_PkmnReadyToHelp[] = _("¡{B_ATK_NAME_WITH_PREFIX} está listo\npara ayudar a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwitchedItems[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha cambiado\nel objeto con su rival!");
static const u8 sText_PkmnObtainedX[] = _("{B_ATK_NAME_WITH_PREFIX} ha obtenido\n{B_BUFF1}.");
static const u8 sText_PkmnObtainedX2[] = _("{B_DEF_NAME_WITH_PREFIX} ha obtenido\n{B_BUFF2}.");
static const u8 sText_PkmnObtainedXYObtainedZ[] = _("{B_ATK_NAME_WITH_PREFIX} ha obtenido\n{B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} ha obtenido\n{B_BUFF2}.");
static const u8 sText_PkmnCopiedFoe[] = _("¡{B_ATK_NAME_WITH_PREFIX} copia\n{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnMadeWish[] = _("¡{B_ATK_NAME_WITH_PREFIX} pide un DESEO!");
static const u8 sText_PkmnWishCameTrue[] = _("¡El DESEO de {B_BUFF1}\nse ha cumplido!");
static const u8 sText_PkmnPlantedRoots[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha echado raíces!");
static const u8 sText_PkmnAbsorbedNutrients[] = _("¡{B_ATK_NAME_WITH_PREFIX} absorbe\nnutrientes con sus raíces!");
static const u8 sText_PkmnAnchoredItself[] = _("¡{B_DEF_NAME_WITH_PREFIX} se agarra\ncon sus raíces!");
static const u8 sText_PkmnWasMadeDrowsy[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nadormecido a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnKnockedOff[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha tirado\n{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnSwappedAbilities[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha cambiado\nla habilidad con su rival!");
static const u8 sText_PkmnSealedOpponentMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha sellado\nmovimientos del rival!");
static const u8 sText_PkmnWantsGrudge[] = _("¡{B_ATK_NAME_WITH_PREFIX} quiere que\nel rival sufra su RABIA!");
static const u8 sText_PkmnLostPPGrudge[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX} pierde\ntodos sus PP por la RABIA!");
static const u8 sText_PkmnShroudedItself[] = _("¡{B_ATK_NAME_WITH_PREFIX} se envuelve\nen {B_CURRENT_MOVE}!");
static const u8 sText_PkmnMoveBounced[] = _("¡CAPA MÁGICA devuelve\n{B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnWaitsForTarget[] = _("¡{B_ATK_NAME_WITH_PREFIX} espera a que\nel rival haga un movimiento!");
static const u8 sText_PkmnSnatchedMove[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha ROBADO el\nmovimiento de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricityWeakened[] = _("¡La potencia eléctrica\nse ha debilitado!");
static const u8 sText_FireWeakened[] = _("¡La potencia del fuego\nse ha debilitado!");
static const u8 sText_XFoundOneY[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nencontrado {B_LAST_ITEM}!");
static const u8 sText_SoothingAroma[] = _("¡Un aroma relajante\nse extiende por la zona!");
static const u8 sText_ItemsCantBeUsedNow[] = _("Ahora no se pueden usar objetos.{PAUSE 64}");
static const u8 sText_ForXCommaYZ[] = _("Para {B_SCR_ACTIVE_NAME_WITH_PREFIX},\n{B_LAST_ITEM} {B_BUFF1}");
static const u8 sText_PkmnUsedXToGetPumped[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha usado\n{B_LAST_ITEM} para concentrarse!");
static const u8 sText_PkmnLostFocus[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha perdido la\nconcentración y no se mueve!");
static const u8 sText_PkmnWasDraggedOut[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha sido\narrastrado al combate!\p");
static const u8 sText_TheWallShattered[] = _("¡La barrera se ha roto!");
static const u8 sText_ButNoEffect[] = _("¡Pero no ha tenido efecto!");
static const u8 sText_PkmnHasNoMovesLeft[] = _("¡A {B_ATK_NAME_WITH_PREFIX} no le\nquedan movimientos!\p");
static const u8 sText_PkmnMoveIsDisabled[] = _("¡{B_CURRENT_MOVE} de {B_ATK_NAME_WITH_PREFIX}\nestá anulado!\p");
static const u8 sText_PkmnCantUseMoveTorment[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede repetir\nmovimiento por el Tormento!\p");
static const u8 sText_PkmnCantUseMoveTaunt[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} por la Mofa!\p");
static const u8 sText_PkmnCantUseMoveSealed[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} porque está sellado!\p");
static const u8 sText_PkmnCantUseMoveThroatChop[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} por Golpe Mordaza!\p");
static const u8 sText_PkmnMadeItRain[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha hecho llover!");
static const u8 sText_PkmnRaisedSpeed[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha subido su VELOCIDAD!");
static const u8 sText_PkmnProtectedBy[] = _("¡{B_DEF_ABILITY} ha protegido\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsUsage[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide que {B_ATK_NAME_WITH_PREFIX}\luse {B_CURRENT_MOVE}!");
static const u8 sText_PkmnRestoredHPUsing[] = _("¡{B_DEF_NAME_WITH_PREFIX} recupera PS\ngracias a {B_DEF_ABILITY}!");
static const u8 sText_PkmnsXMadeYUseless[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nanula {B_CURRENT_MOVE}!");
static const u8 sText_PkmnChangedTypeWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nlo ha vuelto de tipo {B_BUFF1}!");
static const u8 sText_PkmnPreventsParalysisWith[] = _("¡{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide la parálisis!");
static const u8 sText_PkmnPreventsRomanceWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide el enamoramiento!");
static const u8 sText_PkmnPreventsPoisoningWith[] = _("¡{B_DEF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide el envenenamiento!");
static const u8 sText_PkmnPreventsConfusionWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide la confusión!");
static const u8 sText_PkmnRaisedFirePowerWith[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\npotencia sus ataques de FUEGO!");
static const u8 sText_PkmnAnchorsItselfWith[] = _("¡{B_DEF_NAME_WITH_PREFIX} se sujeta\ncon {B_DEF_ABILITY}!");
static const u8 sText_PkmnCutsAttackWith[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbaja el ataque de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnPreventsStatLossWith[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita que bajen sus características!");
static const u8 sText_PkmnHurtsWith[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nha herido a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnTraced[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha RASTREADO\n{B_BUFF2} de {B_BUFF1}!");
static const u8 sText_PkmnsXPreventsBurns[] = _("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nimpide las quemaduras!");
static const u8 sText_PkmnsXBlocksY[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nbloquea {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXBlocksY2[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbloquea {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXRestoredHPALittle2[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nle devuelve algunos PS!");
static const u8 sText_PkmnsXWhippedUpSandstorm[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlevanta una tormenta de arena!");
static const u8 sText_PkmnsXIntensifiedSun[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nintensifica el sol!");
static const u8 sText_PkmnsXPreventsYLoss[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nevita que baje {B_BUFF1}!");
static const u8 sText_PkmnsXInfatuatedY[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nenamora a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeYIneffective[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nanula {B_CURRENT_MOVE}!");
static const u8 sText_PkmnsXCuredYProblem[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura su problema de {B_BUFF1}!");
static const u8 sText_ItSuckedLiquidOoze[] = _("¡Ha absorbido el\nlodo líquido!");
static const u8 sText_PkmnTransformed[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se ha transformado!");
static const u8 sText_PkmnsXTookAttack[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nha atraído el ataque!");
const u8 gText_PkmnsXPreventsSwitching[] = _("¡{B_LAST_ABILITY} de {B_BUFF1}\nimpide el cambio!\p");
static const u8 sText_PreventedFromWorking[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nimpide que funcione {B_BUFF1}\lde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXMadeItIneffective[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlo ha anulado!");
static const u8 sText_PkmnsXPreventsFlinching[] = _("¡{B_EFF_ABILITY} de {B_EFF_NAME_WITH_PREFIX}\nevita que retroceda!");
static const u8 sText_PkmnsXPreventsYsZ[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nanula {B_DEF_ABILITY}\lde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsAbilityPreventsAbility[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nanula {B_DEF_ABILITY}\lde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnsXCuredItsYProblem[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura su problema de {B_BUFF1}!");
static const u8 sText_PkmnsXHadNoEffectOnY[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nno afecta a {B_EFF_NAME_WITH_PREFIX}!");
const u8 gText_StatSharply[] = _("mucho ");
const u8 gText_StatRose[] = _("¡ha subido!");
static const u8 sText_StatHarshly[] = _("mucho ");
static const u8 sText_StatFell[] = _("¡ha bajado!");
static const u8 sText_AttackersStatRose[] = _("{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
const u8 gText_DefendersStatRose[] = _("{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_UsingItemTheStatOfPkmnRose[] = _("Con {B_LAST_ITEM}, {B_BUFF1}\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_AttackersStatFell[] = _("{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_DefendersStatFell[] = _("{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\n{B_BUFF2}");
static const u8 sText_StatsWontIncrease2[] = _("¡Las características de {B_ATK_NAME_WITH_PREFIX}\nno pueden subir más!");
static const u8 sText_StatsWontDecrease2[] = _("¡Las características de {B_DEF_NAME_WITH_PREFIX}\nno pueden bajar más!");
static const u8 sText_CriticalHit[] = _("¡Un golpe crítico!");
static const u8 sText_OneHitKO[] = _("¡KO de un golpe!");
static const u8 sText_123Poof[] = _("{PLAY_SE SE_BALL_BOUNCE_1}¡Puf!\p");
static const u8 sText_AndEllipsis[] = _("Y…\p");
static const u8 sText_HMMovesCantBeForgotten[] = _("Ahora no se pueden\nolvidar movs. MO.\p");
static const u8 sText_NotVeryEffective[] = _("No es muy eficaz…");
static const u8 sText_SuperEffective[] = _("¡Es súper eficaz!");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}¡Has escapado sin problemas!\p");
static const u8 sText_PkmnFledUsingIts[] = _("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} ha huido\ncon {B_LAST_ITEM}!\p");
static const u8 sText_PkmnFledUsing[] = _("{PLAY_SE SE_FLEE}¡{B_ATK_NAME_WITH_PREFIX} ha huido\ngracias a {B_ATK_ABILITY}!\p");
static const u8 sText_WildPkmnFled[] = _("{PLAY_SE SE_FLEE}¡{B_BUFF1} salvaje ha huido!");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("¡Has derrotado a\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("¡Has vencido a {B_LINK_OPPONENT1_NAME}\ny a {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("¡Has perdido contra\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerLostToTwo[] = _("¡Has perdido contra {B_LINK_OPPONENT1_NAME}\ny {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("¡Has empatado contra\n{B_LINK_OPPONENT1_NAME}!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("¡Has empatado contra\n{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} ha huido!");
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}¡{B_LINK_OPPONENT1_NAME} y\n{B_LINK_OPPONENT2_NAME} han huido!");
static const u8 sText_NoRunningFromTrainers[] = _("¡No! ¡No se puede huir de\nun combate contra un ENTRENADOR!\p");
static const u8 sText_CantEscape[] = _("¡No puedes huir!\p");
static const u8 sText_DontLeaveBirch[] = _("PROF. ABEDUL: ¡No me dejes así!\p");
static const u8 sText_ButNothingHappened[] = _("¡Pero no ha pasado nada!");
static const u8 sText_ButItFailed[] = _("¡Pero ha fallado!");
static const u8 sText_ItHurtConfusion[] = _("¡Está tan confuso que\nse hiere a sí mismo!");
static const u8 sText_MirrorMoveFailed[] = _("¡Mov. Espejo ha fallado!");
static const u8 sText_StartedToRain[] = _("¡Ha empezado a llover!");
static const u8 sText_DownpourStarted[] = _("¡Ha empezado a diluviar!"); // corresponds to DownpourText in pokegold and pokecrystal and is used by Rain Dance in GSC
static const u8 sText_RainContinues[] = _("Sigue lloviendo.");
static const u8 sText_DownpourContinues[] = _("Sigue diluviando."); // unused
static const u8 sText_RainStopped[] = _("Ha dejado de llover.");
static const u8 sText_SandstormBrewed[] = _("¡Se ha levantado una tormenta de arena!");
static const u8 sText_SandstormRages[] = _("La tormenta de arena arrecia.");
static const u8 sText_SandstormSubsided[] = _("La tormenta de arena ha amainado.");
static const u8 sText_SunlightGotBright[] = _("¡El sol brilla con fuerza!");
static const u8 sText_SunlightStrong[] = _("El sol pega fuerte.");
static const u8 sText_SunlightFaded[] = _("El sol se ha debilitado.");
static const u8 sText_StartedHail[] = _("¡Ha empezado a granizar!");
static const u8 sText_HailContinues[] = _("Sigue granizando.");
static const u8 sText_HailStopped[] = _("Ha dejado de granizar.");
static const u8 sText_StartedSnow[] = _("¡Ha empezado a nevar!");
static const u8 sText_SnowContinues[] = _("Sigue nevando.");
static const u8 sText_SnowStopped[] = _("Ha dejado de nevar.");
static const u8 sText_FailedToSpitUp[] = _("¡Pero no ha podido\nescupir nada!");
static const u8 sText_FailedToSwallow[] = _("¡Pero no ha podido\ntragar nada!");
static const u8 sText_WindBecameHeatWave[] = _("¡El viento se ha convertido\nen una ONDA ÍGNEA!");
static const u8 sText_StatChangesGone[] = _("¡Se han anulado todos los\ncambios de características!");
static const u8 sText_CoinsScattered[] = _("¡Hay monedas por todas partes!");
static const u8 sText_TooWeakForSubstitute[] = _("¡Está demasiado débil para\ncrear un SUSTITUTO!");
static const u8 sText_SharedPain[] = _("¡Los combatientes comparten\nsu dolor!");
static const u8 sText_BellChimed[] = _("¡Ha sonado una campana!");
static const u8 sText_FaintInThree[] = _("¡Los Pokémon afectados se\ndebilitarán en tres turnos!");
static const u8 sText_NoPPLeft[] = _("¡No quedan PP para\neste movimiento!\p");
static const u8 sText_ButNoPPLeft[] = _("¡Pero no quedaban PP para\nel movimiento!");
static const u8 sText_PkmnIgnoresAsleep[] = _("¡{B_ATK_NAME_WITH_PREFIX} ignora las\nórdenes mientras duerme!");
static const u8 sText_PkmnIgnoredOrders[] = _("¡{B_ATK_NAME_WITH_PREFIX} ignora\nlas órdenes!");
static const u8 sText_PkmnBeganToNap[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nechado una siesta!");
static const u8 sText_PkmnLoafing[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nholgazaneando!");
static const u8 sText_PkmnWontObey[] = _("¡{B_ATK_NAME_WITH_PREFIX} no\nobedece!");
static const u8 sText_PkmnTurnedAway[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha dado la vuelta!");
static const u8 sText_PkmnPretendNotNotice[] = _("¡{B_ATK_NAME_WITH_PREFIX} hace como\nque no se entera!");
static const u8 sText_EnemyAboutToSwitchPkmn[] = _("{B_TRAINER1_CLASS} {B_TRAINER1_NAME} va\na sacar a {B_BUFF2}.\p¿Quieres cambiar\nde POKéMON?");
static const u8 sText_PkmnLearnedMove2[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\naprendido {B_BUFF1}!");
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("¡Has derrotado a\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!\p");
static const u8 sText_CreptCloser[] = _("¡{B_PLAYER_NAME} se acerca con cuidado\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_CantGetCloser[] = _("¡{B_PLAYER_NAME} no puede acercarse más!");
static const u8 sText_PkmnWatchingCarefully[] = _("¡{B_OPPONENT_MON1_NAME} está\natento!");
static const u8 sText_PkmnCuriousAboutX[] = _("¡{B_OPPONENT_MON1_NAME} siente curiosidad\npor {B_BUFF1}!");
static const u8 sText_PkmnEnthralledByX[] = _("¡{B_OPPONENT_MON1_NAME} está encantado\ncon {B_BUFF1}!");
static const u8 sText_PkmnIgnoredX[] = _("¡{B_OPPONENT_MON1_NAME} ignora por\ncompleto {B_BUFF1}!");
static const u8 sText_ThrewPokeblockAtPkmn[] = _("¡{B_PLAYER_NAME} ha lanzado un {POKEBLOCK}\na {B_OPPONENT_MON1_NAME}!");
static const u8 sText_OutOfSafariBalls[] = _("{PLAY_SE SE_DING_DONG}MEGAFONÍA: ¡Te has quedado\nsin SAFARI BALLS! ¡Se acabó!\p");
static const u8 sText_OpponentMon1Appeared[] = _("¡Ha aparecido {B_OPPONENT_MON1_NAME}!\p");
static const u8 sText_WildPkmnAppeared[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} salvaje!\p");
static const u8 sText_UniquePkmnAppeared[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} Único!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("¡Ha aparecido un {B_OPPONENT_MON1_NAME} salvaje!{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("¡Han aparecido {B_OPPONENT_MON1_NAME} y\n{B_OPPONENT_MON2_NAME} salvajes!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nquiere combatir!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("¡{B_LINK_OPPONENT1_NAME}\nquiere combatir!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}\nquieren combatir!");
static const u8 sText_Trainer1SentOutPkmn[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nsaca a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} saca\na {B_OPPONENT_MON1_NAME} y {B_OPPONENT_MON2_NAME}!");
const u8 sText_Trainer1SentOutPkmn2[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nsaca a {B_BUFF1}!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} saca a\n{B_OPPONENT_MON1_NAME}!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} saca a\n{B_OPPONENT_MON1_NAME} y {B_OPPONENT_MON2_NAME}!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} saca a {B_LINK_OPPONENT_MON1_NAME}!\n¡{B_LINK_OPPONENT2_NAME} saca a {B_LINK_OPPONENT_MON2_NAME}!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("¡{B_LINK_OPPONENT1_NAME} saca a\n{B_BUFF1}!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("¡{B_LINK_SCR_TRAINER_NAME} saca a\n{B_BUFF1}!");
static const u8 sText_GoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("¡Adelante, {B_PLAYER_MON1_NAME} y\n{B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("¡Adelante, {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("¡A por ellos, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("¡Vamos, {B_BUFF1}!");
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("¡El rival está débil!\n¡Acaba con él, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("¡{B_LINK_PARTNER_NAME} saca a {B_LINK_PLAYER_MON2_NAME}!\n¡Adelante, {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnThatsEnough[] = _("¡{B_BUFF1}, ya basta!\n¡Vuelve!");
static const u8 sText_PkmnComeBack[] = _("¡{B_BUFF1}, vuelve!");
static const u8 sText_PkmnOkComeBack[] = _("¡{B_BUFF1}, bien!\n¡Vuelve!");
static const u8 sText_PkmnGoodComeBack[] = _("¡{B_BUFF1}, muy bien!\n¡Vuelve!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nha retirado a {B_BUFF1}!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("¡{B_LINK_OPPONENT1_NAME} ha retirado\na {B_BUFF1}!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("¡{B_LINK_SCR_TRAINER_NAME} ha retirado\na {B_BUFF1}!");
static const u8 sText_PkmnIsAngry[] = _("¡{B_DEF_NAME_WITH_PREFIX} está furioso!");
static const u8 sText_PkmnIsCalm[] = _("{B_DEF_NAME_WITH_PREFIX} ya no\nestá furioso.");
static const u8 sText_PoisonPuppeteer[] = _("¡Títere Tóxico de {B_PLAYER_MON1_NAME}\nha confundido a {B_OPPONENT_MON1_NAME}!");
static const u8 sText_CommanderActivates[] = _("¡{B_BUFF2} se ha tragado a {B_BUFF1}\ny {B_BUFF1} lo comanda!");
static const u8 sText_WildPkmnPrefix[] = _(" salvaje");
static const u8 sText_FoePkmnPrefix[] = _(" rival");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("rival");
static const u8 sText_AllyPkmnPrefix[] = _("aliado");
static const u8 sText_FoePkmnPrefix3[] = _("rival");
static const u8 sText_AllyPkmnPrefix2[] = _("aliado");
static const u8 sText_FoePkmnPrefix4[] = _("rival");
static const u8 sText_AllyPkmnPrefix3[] = _("aliado");
static const u8 sText_AttackerUsedX[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha usado\n{B_BUFF3}!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("PS");
static const u8 sText_Attack[] = _("Ataque");
static const u8 sText_Defense[] = _("Defensa");
static const u8 sText_Speed[] = _("Velocidad");
static const u8 sText_SpAttack[] = _("At. Esp.");
static const u8 sText_SpDefense[] = _("Def. Esp.");
static const u8 sText_Accuracy[] = _("Precisión");
static const u8 sText_Evasiveness[] = _("Evasión");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    sText_HP, sText_Attack, sText_Defense,
    sText_Speed, sText_SpAttack, sText_SpDefense,
    sText_Accuracy, sText_Evasiveness
};

static const u8 sText_PokeblockWasTooSpicy[] = _("¡era demasiado picante!");
static const u8 sText_PokeblockWasTooDry[] = _("¡era demasiado seco!");
static const u8 sText_PokeblockWasTooSweet[] = _("¡era demasiado dulce!");
static const u8 sText_PokeblockWasTooBitter[] = _("¡era demasiado amargo!");
static const u8 sText_PokeblockWasTooSour[] = _("¡era demasiado ácido!");

const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = sText_PokeblockWasTooSpicy,
    [FLAVOR_DRY]    = sText_PokeblockWasTooDry,
    [FLAVOR_SWEET]  = sText_PokeblockWasTooSweet,
    [FLAVOR_BITTER] = sText_PokeblockWasTooBitter,
    [FLAVOR_SOUR]   = sText_PokeblockWasTooSour
};

static const u8 sText_PlayerUsedItem[] = _("¡Has usado\n{B_LAST_ITEM}!");
static const u8 sText_WallyUsedItem[] = _("¡BLASCO ha usado\n{B_LAST_ITEM}!");
static const u8 sText_Trainer1UsedItem[] = _("¡{B_ATK_TRAINER_CLASS} {B_ATK_TRAINER_NAME}\nha usado {B_LAST_ITEM}!");
static const u8 sText_TrainerBlockedBall[] = _("¡El ENTRENADOR ha desviado la BALL!");
static const u8 sText_DontBeAThief[] = _("¡No seas ladrón!");
static const u8 sText_ItDodgedBall[] = _("¡Ha esquivado la Ball!\n¡No se puede capturar!");
static const u8 sText_YouMissedPkmn[] = _("¡Has fallado el lanzamiento!");
static const u8 sText_PkmnBrokeFree[] = _("¡Oh, no!\n¡El Pokémon se ha escapado!");
static const u8 sText_ItAppearedCaught[] = _("¡Vaya!\n¡Parecía que lo tenías!");
static const u8 sText_AarghAlmostHadIt[] = _("¡Argh!\n¡Casi lo consigues!");
static const u8 sText_ShootSoClose[] = _("¡Mecachis!\n¡Ha faltado muy poco!");
static const u8 sText_GotchaPkmnCaughtPlayer[] = _("¡Ya está!\n¡Has capturado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p");
static const u8 sText_GotchaPkmnCaughtWally[] = _("¡Ya está!\n¡Has capturado a {B_DEF_NAME}!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}");
static const u8 sText_GiveNicknameCaptured[] = _("¿Quieres ponerle un mote al\n{B_DEF_NAME} capturado?");
static const u8 sText_PkmnSentToPC[] = _("{B_DEF_NAME} se ha enviado\nal PC de {B_PC_CREATOR_NAME}.");
static const u8 sText_Someones[] = _("alguien");
static const u8 sText_Lanettes[] = _("ARIA");
static const u8 sText_PkmnDataAddedToDex[] = _("Se han añadido los datos de\n{B_DEF_NAME} a la POKéDEX.\p");
static const u8 sText_ItIsRaining[] = _("Está lloviendo.");
static const u8 sText_SandstormIsRaging[] = _("Hay una tormenta de arena.");
static const u8 sText_BoxIsFull[] = _("¡La CAJA está llena!\n¡No puedes capturar más!\p");
static const u8 sText_EnigmaBerry[] = _("BAYA ENIGMA");
static const u8 sText_BerrySuffix[] = _(" BAYA");
static const u8 sText_PkmnsItemCuredParalysis[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura la parálisis!");
static const u8 sText_PkmnsItemCuredPoison[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura el veneno!");
static const u8 sText_PkmnsItemHealedBurn[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura la quemadura!");
static const u8 sText_PkmnsItemHealedFrostbite[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura la congelación!");
static const u8 sText_PkmnsItemDefrostedIt[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlo ha descongelado!");
static const u8 sText_PkmnsItemWokeIt[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nlo ha despertado!");
static const u8 sText_PkmnsItemSnappedOut[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura la confusión!");
static const u8 sText_PkmnsItemCuredProblem[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\ncura su problema de {B_BUFF1}!");
static const u8 sText_PkmnsItemNormalizedStatus[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nnormaliza su estado!");
static const u8 sText_PkmnsItemRestoredHealth[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle devuelve salud!");
static const u8 sText_PkmnsItemRestoredPP[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaura los PP de {B_BUFF1}!");
static const u8 sText_PkmnsItemRestoredStatus[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nrestaura su estado!");
static const u8 sText_PkmnsItemRestoredHPALittle[] = _("¡{B_LAST_ITEM} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nle devuelve algunos PS!");
static const u8 sText_ItemAllowsOnlyYMove[] = _("¡{B_LAST_ITEM} solo permite\nusar {B_CURRENT_MOVE}!\p");
static const u8 sText_PkmnHungOnWithX[] = _("¡{B_DEF_NAME_WITH_PREFIX} aguanta\ngracias a {B_LAST_ITEM}!");
const u8 gText_EmptyString3[] = _("");
static const u8 sText_YouThrowABallNowRight[] = _("Ahora lanzas una BALL, ¿verdad?\n¡Ha… haré lo que pueda!");

// early declaration of strings
static const u8 sText_PkmnIncapableOfPower[];
static const u8 sText_GlintAppearsInEye[];
static const u8 sText_PkmnGettingIntoPosition[];
static const u8 sText_PkmnBeganGrowlingDeeply[];
static const u8 sText_PkmnEagerForMore[];
static const u8 sText_DefeatedOpponentByReferee[];
static const u8 sText_LostToOpponentByReferee[];
static const u8 sText_TiedOpponentByReferee[];
static const u8 sText_QuestionForfeitMatch[];
static const u8 sText_ForfeitedMatch[];
static const u8 sText_Trainer1WinText[];
static const u8 sText_Trainer2WinText[];
static const u8 sText_TwoInGameTrainersDefeated[];
static const u8 sText_Trainer2LoseText[];

// New battle strings.
static const u8 sText_EnduredViaSturdy[] = _("¡{B_DEF_NAME_WITH_PREFIX} aguanta el\ngolpe gracias a {B_DEF_ABILITY}!");
static const u8 sText_PowerHerbActivation[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha cargado\nal máximo con {B_LAST_ITEM}!");
static const u8 sText_HurtByItem[] = _("¡{B_LAST_ITEM} ha herido a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_BadlyPoisonedByItem[] = _("¡{B_LAST_ITEM} ha envenenado\ngravemente a {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_BurnedByItem[] = _("¡{B_LAST_ITEM} ha quemado\na {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAbilityActivates[] = _("¡Se activa {B_DEF_ABILITY}\nde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_GravityIntensified[] = _("¡La gravedad ha aumentado!");
static const u8 sText_TargetIdentified[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha sido\nidentificado!");
static const u8 sText_TargetWokeUp[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha despertado!");
static const u8 sText_PkmnStoleAndAteItem[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha robado y comido\n{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TailWindBlew[] = _("¡Sopla viento a favor\ndel equipo {B_ATK_TEAM2}!");
static const u8 sText_PkmnWentBack[] = _("{B_ATK_NAME_WITH_PREFIX} ha vuelto con\n{B_ATK_TRAINER_CLASS} {B_ATK_TRAINER_NAME}.");
static const u8 sText_PkmnCantUseItemsAnymore[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya no puede\nusar objetos!");
static const u8 sText_PkmnFlung[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha lanzado\n{B_LAST_ITEM}!");
static const u8 sText_PkmnPreventedFromHealing[] = _("¡{B_DEF_NAME_WITH_PREFIX} no puede\ncurarse!");
static const u8 sText_PkmnSwitchedAtkAndDef[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia\nsu Ataque y su Defensa!");
static const u8 sText_PkmnsAbilitySuppressed[] = _("¡Se ha anulado la habilidad\nde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_ShieldedFromCriticalHits[] = _("¡{B_CURRENT_MOVE} protege al equipo\n{B_ATK_TEAM2} de los golpes críticos!");
static const u8 sText_SwitchedAtkAndSpAtk[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia con el\nrival los cambios de Ataque\py At. Esp.!");
static const u8 sText_SwitchedDefAndSpDef[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia con el\nrival los cambios de Defensa\py Def. Esp.!");
static const u8 sText_PkmnAcquiredAbility[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha\nadquirido {B_DEF_ABILITY}!");
static const u8 sText_PoisonSpikesScattered[] = _("¡Hay Púas Tóxicas esparcidas a\nlos pies del equipo {B_DEF_TEAM2}!");
static const u8 sText_PkmnSwitchedStatChanges[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia los\ncambios de características!");
static const u8 sText_PkmnSurroundedWithVeilOfWater[] = _("¡{B_ATK_NAME_WITH_PREFIX} se rodea\nde un velo de agua!");
static const u8 sText_PkmnLevitatedOnElectromagnetism[] = _("¡{B_ATK_NAME_WITH_PREFIX} levita gracias\nal electromagnetismo!");
static const u8 sText_PkmnTwistedDimensions[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\ndistorsionado las dimensiones!");
static const u8 sText_PointedStonesFloat[] =_("¡Flotan piedras puntiagudas\nalrededor del equipo {B_DEF_TEAM2}!");
static const u8 sText_CloakedInMysticalMoonlight[] =_("¡Lo envuelve una luz de\nluna mística!");
static const u8 sText_TrappedBySwirlingMagma[] =_("¡{B_DEF_NAME_WITH_PREFIX} ha quedado\natrapado en un remolino de magma!");
static const u8 sText_VanishedInstantly[] =_("¡{B_ATK_NAME_WITH_PREFIX} ha\ndesaparecido al instante!");
static const u8 sText_ProtectedTeam[] =_("¡{B_CURRENT_MOVE} protege\nal equipo {B_ATK_TEAM2}!");
static const u8 sText_SharedItsGuard[] =_("¡{B_ATK_NAME_WITH_PREFIX} comparte\nsu defensa con el rival!");
static const u8 sText_SharedItsPower[] =_("¡{B_ATK_NAME_WITH_PREFIX} comparte\nsu fuerza con el rival!");
static const u8 sText_SwapsDefAndSpDefOfAllPkmn[] =_("¡Ha creado una zona extraña que\nintercambia Defensa y Def. Esp.!");
static const u8 sText_BecameNimble[] =_("¡{B_ATK_NAME_WITH_PREFIX} se ha vuelto más ágil!");
static const u8 sText_HurledIntoTheAir[] =_("¡{B_DEF_NAME_WITH_PREFIX} ha salido\nlanzado por los aires!");
static const u8 sText_HeldItemsLoseEffects[] =_("¡Ha creado una zona extraña que anula\nlos objetos equipados!");
static const u8 sText_FellStraightDown[] =_("¡{B_DEF_NAME_WITH_PREFIX} ha caído\nen picado!");
static const u8 sText_TargetChangedType[] =_("¡{B_DEF_NAME_WITH_PREFIX} ahora es\nde tipo {B_BUFF1}!");
static const u8 sText_PkmnAcquiredSimple[] =_("¡{B_DEF_NAME_WITH_PREFIX} ha\nadquirido Simple!");
static const u8 sText_KindOffer[] =_("¡{B_DEF_NAME_WITH_PREFIX}\nacepta la amable oferta!");
static const u8 sText_ResetsTargetsStatLevels[] =_("¡Se han anulado los cambios de\ncaracterísticas de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AllySwitchPosition[] =_("¡{B_ATK_NAME_WITH_PREFIX} y\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} cambian de sitio!");
static const u8 sText_RestoreTargetsHealth[] =_("¡{B_DEF_NAME_WITH_PREFIX} ha recuperado PS!");
static const u8 sText_TookPkmnIntoTheSky[] =_("¡{B_ATK_NAME_WITH_PREFIX} se lleva a\n{B_DEF_NAME_WITH_PREFIX} por los aires!");
static const u8 sText_FreedFromSkyDrop[] =_("¡{B_DEF_NAME_WITH_PREFIX} se ha librado\nde Caída Libre!");
static const u8 sText_PostponeTargetMove[] =_("¡El movimiento de\n{B_DEF_NAME_WITH_PREFIX} se ha retrasado!");
static const u8 sText_ReflectTargetsType[] =_("¡{B_ATK_NAME_WITH_PREFIX} ahora tiene\nel tipo de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TransferHeldItem[] =_("{B_DEF_NAME_WITH_PREFIX} ha recibido\n{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX}.");
static const u8 sText_EmbargoEnds[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya puede\nusar objetos!");
static const u8 sText_Electromagnetism[] = _("electromagnetismo");
static const u8 sText_BufferEnds[] = _("¡{B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}\nha terminado!");
static const u8 sText_ThroatChopEnds[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya puede\nusar movs. de sonido!");
static const u8 sText_TelekinesisEnds[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha librado\nde la telequinesis!");
static const u8 sText_TailwindEnds[] = _("¡Se ha calmado el viento a favor\ndel equipo {B_ATK_TEAM1}!");
static const u8 sText_LuckyChantEnds[] = _("¡Conjuro del equipo {B_ATK_TEAM1}\nha terminado!");
static const u8 sText_TrickRoomEnds[] = _("¡Las dimensiones han vuelto\na la normalidad!");
static const u8 sText_WonderRoomEnds[] = _("¡Zona Extraña termina y la Defensa y\nDef. Esp. vuelven a la normalidad!");
static const u8 sText_MagicRoomEnds[] = _("¡Zona Mágica termina y los objetos\nvuelven a funcionar con normalidad!");
static const u8 sText_MudSportEnds[] = _("Chapoteo Lodo ya no hace efecto.");
static const u8 sText_WaterSportEnds[] = _("Hidrochorro ya no hace efecto.");
static const u8 sText_GravityEnds[] = _("¡La gravedad ha vuelto a la normalidad!");
static const u8 sText_AquaRingHeal[] = _("¡Acua Aro restaura PS a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAbilityRaisedStat[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nsube su {B_BUFF1}!");
static const u8 sText_TargetAbilityLoweredStat[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nbaja su {B_BUFF1}!");
static const u8 sText_AttackerAbilityRaisedStat[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nsube su {B_BUFF1}!");
static const u8 sText_ScriptingAbilityRaisedStat[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nsube su {B_BUFF1}!");
static const u8 sText_AuroraVeilEnds[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nha terminado!");
static const u8 sText_ElectricTerrainEnds[] = _("La electricidad ha desaparecido\ndel terreno.");
static const u8 sText_MistyTerrainEnds[] = _("La niebla ha desaparecido\ndel terreno.");
static const u8 sText_PsychicTerrainEnds[] = _("La rareza ha desaparecido\ndel terreno.");
static const u8 sText_GrassyTerrainEnds[] = _("La hierba ha desaparecido\ndel terreno.");
static const u8 sText_TargetsStatWasMaxedOut[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nmaximiza su {B_BUFF1}!");
static const u8 sText_PoisonHealHpUp[] = _("¡El veneno cura un poco\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_BadDreamsDmg[] = _("¡{B_DEF_NAME_WITH_PREFIX} sufre pesadillas!");
static const u8 sText_MoldBreakerEnters[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} rompe moldes!");
static const u8 sText_TeravoltEnters[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} desprende\nun aura chisporroteante!");
static const u8 sText_TurboblazeEnters[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} desprende\nun aura llameante!");
static const u8 sText_SlowStartEnters[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} no termina de arrancar!");
static const u8 sText_SlowStartEnd[] = _("¡{B_ATK_NAME_WITH_PREFIX} por fin\nse ha puesto en marcha!");
static const u8 sText_SolarPowerHpDrop[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\npasa factura!");
static const u8 sText_AftermathDmg[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha resultado herido!");
static const u8 sText_AnticipationActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se\nestremece anticipándose!");
static const u8 sText_ForewarnActivates[] = _("¡{B_SCR_ACTIVE_ABILITY} alerta a {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nde {B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_IceBodyHpGain[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nlo cura un poco!");
static const u8 sText_SnowWarningHail[] = _("¡Ha empezado a granizar!");
static const u8 sText_SnowWarningSnow[] = _("¡Ha empezado a nevar!");
static const u8 sText_FriskActivates[] = _("¡{B_ATK_NAME_WITH_PREFIX} cachea a\n{B_DEF_NAME_WITH_PREFIX} y encuentra\l{B_LAST_ITEM}!");
static const u8 sText_UnnerveEnters[] = _("¡El equipo rival está demasiado\nnervioso para comer Bayas!");
static const u8 sText_HarvestBerry[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nrecogido {B_LAST_ITEM}!");
static const u8 sText_LastAbilityRaisedBuff1[] = _("¡{B_LAST_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nsube su {B_BUFF1}!");
static const u8 sText_MagicBounceActivates[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha devuelto el\nataque de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ProteanTypeChange[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nlo vuelve de tipo {B_BUFF1}!");
static const u8 sText_SymbiosisItemPass[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} pasa {B_LAST_ITEM}\na {B_ATK_NAME_WITH_PREFIX} con {B_LAST_ABILITY}!");
static const u8 sText_StealthRockDmg[] = _("¡Las piedras puntiagudas hieren\na {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ToxicSpikesAbsorbed[] = _("¡Las púas tóxicas han desaparecido\nde los pies del equipo {B_DEF_TEAM2}!");
static const u8 sText_ToxicSpikesPoisoned[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha sido envenenado!");
static const u8 sText_StickyWebSwitchIn[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha caído\nen una Red Viscosa!");
static const u8 sText_HealingWishCameTrue[] = _("¡El Deseo Cura se cumple\npara {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_HealingWishHealed[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha recuperado la salud!");
static const u8 sText_LunarDanceCameTrue[] = _("¡A {B_ATK_NAME_WITH_PREFIX} lo envuelve\nuna luz de luna mística!");
static const u8 sText_CursedBodyDisabled[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\nanula {B_BUFF1} de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_AttackerAquiredAbility[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha\nadquirido {B_ATK_ABILITY}!");
static const u8 sText_TargetStatWontGoHigher[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nno puede subir más!");
static const u8 sText_PkmnMoveBouncedViaAbility[] = _("¡{B_DEF_ABILITY} de {B_DEF_NAME_WITH_PREFIX}\ndevuelve {B_CURRENT_MOVE}\lde {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ImposterTransform[] = _("¡{B_ATK_NAME_WITH_PREFIX} se transforma en\n{B_DEF_NAME_WITH_PREFIX} con {B_LAST_ABILITY}!");
static const u8 sText_NotDoneYet[] = _("¡Este efecto aún no está hecho!\p");
static const u8 sText_PkmnBlewAwayToxicSpikes[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha barrido\nlas Púas Tóxicas!");
static const u8 sText_PkmnBlewAwayStickyWeb[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha barrido\nla Red Viscosa!");
static const u8 sText_PkmnBlewAwayStealthRock[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha barrido\nTrampa Rocas!");
static const u8 sText_SpikesDisappearedFromTeam[] = _("¡Las púas han desaparecido del\nsuelo del equipo {B_ATK_TEAM2}!");
static const u8 sText_ToxicSpikesDisappearedFromTeam[] = _("¡Las púas tóxicas han desaparecido\ndel suelo del equipo {B_ATK_TEAM2}!");
static const u8 sText_StealthRockDisappearedFromTeam[] = _("¡Las piedras puntiagudas han\ndesaparecido del equipo {B_ATK_TEAM2}!");
static const u8 sText_StickyWebDisappearedFromTeam[] = _("¡La red viscosa ha desaparecido\ndel suelo del equipo {B_ATK_TEAM2}!");
static const u8 sText_StickyWebUsed[] = _("¡Una red viscosa cubre el\nsuelo del equipo {B_DEF_TEAM2}!");
static const u8 sText_QuashSuccess[] = _("¡El movimiento de\n{B_DEF_NAME_WITH_PREFIX} se ha retrasado!");
static const u8 sText_IonDelugeOn[] = _("¡Una lluvia de iones cae\nsobre el terreno!");
static const u8 sText_TopsyTurvySwitchedStats[] = _("¡Se han invertido los cambios de\ncaracterísticas de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TerrainBecomesMisty[] = _("¡La niebla envuelve\nel terreno!");
static const u8 sText_TerrainBecomesGrassy[] = _("¡La hierba cubre\nel terreno!");
static const u8 sText_TerrainBecomesElectric[] = _("¡Una corriente eléctrica recorre\nel terreno!");
static const u8 sText_TerrainBecomesPsychic[] = _("¡El terreno se ha vuelto extraño!");
static const u8 sText_TargetElectrified[] = _("¡Los movimientos de\n{B_DEF_NAME_WITH_PREFIX} se han electrificado!");
static const u8 sText_AssaultVestDoesntAllow[] = _("¡{B_LAST_ITEM} impide usar\nmovimientos de estado!\p");
static const u8 sText_GravityPreventsUsage[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede usar\n{B_CURRENT_MOVE} por la gravedad!\p");
static const u8 sText_HealBlockPreventsUsage[] = _("¡{B_ATK_NAME_WITH_PREFIX} no\npuede curarse!\p");
static const u8 sText_MegaEvoReacting[] = _("¡{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX}\nreacciona a la Megapulsera\lde {B_ATK_TRAINER_NAME}!");
static const u8 sText_FerventWishReached[] = _("¡El ferviente deseo de {B_ATK_TRAINER_NAME}\nha llegado a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_MegaEvoEvolved[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha megaevolucionado\nen Mega-{B_BUFF1}!");
static const u8 sText_drastically[] = _("muchísimo ");
static const u8 sText_severely[] = _("muchísimo ");
static const u8 sText_Infestation[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha infestado\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_NoEffectOnTarget[] = _("¡No ha tenido efecto\nen {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_BurstingFlames[] = _("¡Las llamas alcanzan\na {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_BestowItemGiving[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha recibido\n{B_LAST_ITEM} de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ThirdTypeAdded[] = _("¡{B_DEF_NAME_WITH_PREFIX} ahora\ntambién es de tipo {B_BUFF1}!");
static const u8 sText_FellForFeint[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha caído\nen el engaño!");
static const u8 sText_PokemonCannotUseMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} no puede\nusar {B_CURRENT_MOVE}!");
static const u8 sText_CoveredInPowder[] = _("¡{B_DEF_NAME_WITH_PREFIX} está\ncubierto de polvo!");
static const u8 sText_PowderExplodes[] = _("¡Al tocar la llama el polvo que\ncubre al Pokémon, ha explotado!");
static const u8 sText_BelchCantUse[] = _("¡No se puede usar Eructo!\p");
static const u8 sText_SpectralThiefSteal[] = _("¡{B_ATK_NAME_WITH_PREFIX} roba las mejoras\nde características del rival!");
static const u8 sText_GravityGrounding[] = _("¡{B_DEF_NAME_WITH_PREFIX} no puede seguir\nvolando por la gravedad!");
static const u8 sText_MistyTerrainPreventsStatus[] = _("¡{B_DEF_NAME_WITH_PREFIX} se rodea de\nuna niebla protectora!");
static const u8 sText_GrassyTerrainHeals[] = _("¡El campo de hierba\ncura a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_ElectricTerrainPreventsSleep[] = _("¡{B_DEF_NAME_WITH_PREFIX} se rodea de\nun campo eléctrico!");
static const u8 sText_PsychicTerrainPreventsPriority[] = _("¡{B_DEF_NAME_WITH_PREFIX} se rodea de\nun campo psíquico!");
static const u8 sText_SafetyGogglesProtected[] = _("¡A {B_DEF_NAME_WITH_PREFIX} no le afecta\ngracias a {B_LAST_ITEM}!");
static const u8 sText_FlowerVeilProtected[] = _("¡{B_DEF_NAME_WITH_PREFIX} se rodea de\nun velo de pétalos!");
static const u8 sText_SweetVeilProtected[] = _("¡{B_DEF_NAME_WITH_PREFIX} se rodea de\nun velo dulce!");
static const u8 sText_AromaVeilProtected[] = _("¡Un velo aromático protege\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_CelebrateMessage[] = _("¡Enhorabuena, {B_PLAYER_NAME}!");
static const u8 sText_UsedInstructedMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} usa el mov.\nque le ha indicado {B_BUFF1}!");
static const u8 sText_LaserFocusMessage[] = _("¡{B_ATK_NAME_WITH_PREFIX} se\nconcentra al máximo!");
static const u8 sText_GemActivates[] = _("¡{B_LAST_ITEM} potencia el\nataque de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_BerryDmgReducing[] = _("¡{B_LAST_ITEM} reduce el daño\nque recibe {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_TargetAteItem[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha\ncomido {B_LAST_ITEM}!");
static const u8 sText_AirBalloonFloat[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} flota en el aire\ngracias a {B_LAST_ITEM}!");
static const u8 sText_AirBalloonPop[] = _("¡{B_LAST_ITEM} de\n{B_DEF_NAME_WITH_PREFIX} ha explotado!");
static const u8 sText_IncinerateBurn[] = _("¡{B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX}\nse ha quemado!");
static const u8 sText_BugBite[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha robado y comido\n{B_LAST_ITEM} de {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_IllusionWoreOff[] = _("¡Se ha desvanecido la Ilusión\nde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AttackerCuredTargetStatus[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha curado\nel problema de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AttackerLostFireType[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha consumido!");
static const u8 sText_HealerCure[] = _("¡{B_LAST_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\ncura el problema de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_ReceiverAbilityTakeOver[] = _("¡Se ha adoptado {B_SCR_ACTIVE_ABILITY}\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnAbsorbingPower[] = _("¡{B_ATK_NAME_WITH_PREFIX} está\nabsorbiendo energía!");
static const u8 sText_NoOneWillBeAbleToRun[] = _("¡Nadie podrá huir durante\nel próximo turno!");
static const u8 sText_DestinyKnotActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se ha enamorado\npor {B_LAST_ITEM}!");
static const u8 sText_CloakedInAFreezingLight[] = _("¡A {B_ATK_NAME_WITH_PREFIX} lo envuelve\nuna luz gélida!");
static const u8 sText_ClearAmuletWontLowerStats[] = _("¡{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX} impide\nque bajen sus características!");
static const u8 sText_AuraFlaredToLife[] = _("¡El aura de {B_DEF_NAME_WITH_PREFIX}\nse ha avivado!");
static const u8 sText_AirLockActivates[] = _("Los efectos del clima\nhan desaparecido.");
static const u8 sText_PressureActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ejerce\nsu presión!");
static const u8 sText_DarkAuraActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} desprende\nun aura oscura!");
static const u8 sText_FairyAuraActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} desprende\nun aura feérica!");
static const u8 sText_AuraBreakActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} invierte el\naura de los demás Pokémon!");
static const u8 sText_ComatoseActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} está adormilado!");
static const u8 sText_ScreenCleanerActivates[] = _("¡Se han eliminado todas las\nbarreras del terreno!");
static const u8 sText_FetchedPokeBall[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ha\nencontrado {B_LAST_ITEM}!");
static const u8 sText_BattlerAbilityRaisedStat[] = _("¡{B_SCR_ACTIVE_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nsube su {B_BUFF1}!");
static const u8 sText_ASandstormKickedUp[] = _("¡Se ha levantado una tormenta de arena!");
static const u8 sText_PkmnsWillPerishIn3Turns[] = _("¡Ambos Pokémon se debilitarán\nen tres turnos!");
static const u8 sText_AbilityRaisedStatDrastically[] = _("¡{B_DEF_ABILITY} sube muchísimo\n{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AsOneEnters[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} tiene dos habilidades!");
static const u8 sText_PkmnMadeShellGleam[] = _("¡{B_DEF_NAME_WITH_PREFIX} hace brillar\nsu caparazón!\p¡Altera la eficacia de los tipos!");
static const u8 sText_CuriousMedicineEnters[] = _("¡Se han anulado los cambios de\ncaracterísticas de {B_EFF_NAME_WITH_PREFIX}!");
static const u8 sText_CanActFaster[] = _("¡{B_ATK_NAME_WITH_PREFIX} puede actuar antes\ngracias a {B_BUFF1}!");
static const u8 sText_MicleBerryActivates[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} usa {B_LAST_ITEM}\ny aumenta la precisión\lde su próximo movimiento!");
static const u8 sText_PkmnShookOffTheTaunt[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ya no\ncae en la provocación!");
static const u8 sText_PkmnGotOverItsInfatuation[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ya no\nestá enamorado!");
static const u8 sText_ZPowerSurrounds[] = _("¡{B_ATK_NAME_WITH_PREFIX} se rodea\nde su poder Z!");
static const u8 sText_ZPowerUnleashed[] = _("¡{B_ATK_NAME_WITH_PREFIX} desata\nsu movimiento Z!");
static const u8 sText_ZMoveResetsStats[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} restaura sus\ncaracterísticas reducidas\lcon el poder Z!");
static const u8 sText_ZMoveAllStatsUp[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} aumenta todas\nsus características con el poder Z!");
static const u8 sText_ZMoveBoostCrit[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} aumenta su\níndice de crítico con el poder Z!");
static const u8 sText_ZMoveRestoreHp[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} recupera\nPS con el poder Z!");
static const u8 sText_ZMoveStatUp[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} aumenta sus\ncaracterísticas con el poder Z!");
static const u8 sText_ZMoveHpSwitchInTrap[] = _("¡El poder Z restaura los PS\nde {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_TerrainReturnedToNormal[] = _("¡El terreno ha vuelto\na la normalidad!");
static const u8 sText_ItemCannotBeRemoved[] = _("¡No se puede quitar el objeto\nde {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_StickyBarbTransfer[] = _("¡{B_LAST_ITEM} se ha pegado a\n{B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBurnHealed[] = _("Se ha curado la quemadura\nde {B_DEF_NAME_WITH_PREFIX}.");
static const u8 sText_RedCardActivate[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} le muestra\n{B_LAST_ITEM} a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_EjectButtonActivate[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se retira\ngracias a {B_LAST_ITEM}!");
static const u8 sText_AttackerGotOverInfatuation[] =_("¡{B_ATK_NAME_WITH_PREFIX} ya no\nestá enamorado!");
static const u8 sText_TormentedNoMore[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya no\nsufre el tormento!");
static const u8 sText_HealBlockedNoMore[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya puede\ncurarse!");
static const u8 sText_AttackerBecameFullyCharged[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha cargado al máximo\npor el vínculo con su entrenador!\p");
static const u8 sText_AttackerBecameAshSpecies[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha\nconvertido en {B_BUFF1}-Ash!\p");
static const u8 sText_ExtremelyHarshSunlight[] = _("¡El sol se ha vuelto\nabrasador!");
static const u8 sText_ExtremeSunlightFaded[] = _("El sol abrasador se ha desvanecido.{PAUSE 64}");
static const u8 sText_MoveEvaporatedInTheHarshSunlight[] = _("¡El ataque de tipo Agua se ha\nevaporado por el sol abrasador!");
static const u8 sText_ExtremelyHarshSunlightWasNotLessened[] = _("¡El sol abrasador no\nha perdido fuerza!");
static const u8 sText_HeavyRain[] = _("¡Ha empezado a diluviar!");
static const u8 sText_HeavyRainLifted[] = _("¡El diluvio ha cesado!{PAUSE 64}");
static const u8 sText_MoveFizzledOutInTheHeavyRain[] = _("¡El ataque de tipo Fuego se ha\napagado con el diluvio!");
static const u8 sText_NoReliefFromHeavyRain[] = _("¡Este diluvio no\nda tregua!");
static const u8 sText_MysteriousAirCurrent[] = _("¡Unas misteriosas turbulencias\nprotegen a los Pokémon Volador!");
static const u8 sText_StrongWindsDissipated[] = _("¡Las misteriosas turbulencias\nse han disipado!{PAUSE 64}");
static const u8 sText_MysteriousAirCurrentBlowsOn[] = _("¡Las misteriosas turbulencias\nsiguen soplando!");
static const u8 sText_AttackWeakenedByStrongWinds[] = _("¡Las misteriosas turbulencias\nhan debilitado el ataque!");
static const u8 sText_StuffCheeksCantSelect[] = _("¡No se puede elegir Atiborramiento\nsin tener una Baya!\p");
static const u8 sText_PkmnRevertedToPrimal[] = _("¡Regresión primigenia de\n{B_ATK_NAME_WITH_PREFIX}!\p¡Ha recuperado su forma primitiva!");
static const u8 sText_ButPokemonCantUseTheMove[] = _("¡Pero {B_ATK_NAME_WITH_PREFIX} no puede\nusar el movimiento!");
static const u8 sText_ButHoopaCantUseIt[] = _("¡Pero Hoopa no puede usarlo\ncon su forma actual!");
static const u8 sText_BrokeThroughProtection[] = _("¡Ha atravesado la protección\nde {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_AbilityAllowsOnlyMove[] = _("¡{B_ATK_ABILITY} solo permite\nusar {B_CURRENT_MOVE}!\p");
static const u8 sText_SwappedAbilities[] = _("¡{B_DEF_NAME_WITH_PREFIX} intercambia su\nhabilidad con el objetivo!");
static const u8 sText_PastelVeilProtected[] = _("¡Un velo pastel protege\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PastelVeilEnters[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha curado\ndel envenenamiento!");
static const u8 sText_BattlerTypeChangedTo[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} ahora\nes de tipo {B_BUFF1}!");
static const u8 sText_BothCanNoLongerEscape[] = _("¡Ningún Pokémon puede huir!");
static const u8 sText_CantEscapeDueToUsedMove[] = _("¡{B_ATK_NAME_WITH_PREFIX} ya no puede huir\npor haber usado {B_CURRENT_MOVE}!");
static const u8 sText_PkmnBecameWeakerToFire[] = _("¡{B_DEF_NAME_WITH_PREFIX} se ha vuelto\nmás débil al fuego!");
static const u8 sText_PkmnAboutToBeAttackedByItsItem[] = _("¡{B_BUFF1} de {B_DEF_NAME_WITH_PREFIX}\nestá a punto de atacarle!");
static const u8 sText_CantEscapeBecauseOfCurrentMove[] = _("¡{B_DEF_NAME_WITH_PREFIX} ya no puede huir\npor {B_CURRENT_MOVE}!");
static const u8 sText_NeutralizingGasEnters[] = _("¡El Gas Reactivo lo llena todo!");
static const u8 sText_NeutralizingGasOver[] = _("¡Los efectos del Gas\nReactivo han terminado!");
static const u8 sText_PkmnTookTargetHigh[] = _("¡{B_ATK_NAME_WITH_PREFIX} se lleva a\n{B_DEF_NAME_WITH_PREFIX} por los aires!");
static const u8 sText_TargetTooHeavy[] = _("¡Pero el objetivo\npesa demasiado!");
static const u8 sText_MeteorBeamCharging[] = _("¡{B_ATK_NAME_WITH_PREFIX} rebosa\nenergía cósmica!");
static const u8 sText_HeatingUpBeak[] = _("¡{B_ATK_NAME_WITH_PREFIX} empieza a\ncalentar su pico!");
static const u8 sText_CourtChange[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia los\nefectos de ambos lados del campo!");
static const u8 sText_AttackerExpelledThePoison[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha logrado\nexpulsar el veneno!");
static const u8 sText_AttackerShookItselfAwake[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha espabilado!");
static const u8 sText_AttackerBrokeThroughParalysis[] = _("¡{B_ATK_NAME_WITH_PREFIX} reúne su energía\ny supera la parálisis!");
static const u8 sText_AttackerHealedItsBurn[] = _("¡{B_ATK_NAME_WITH_PREFIX} cura su quemadura\ncon pura determinación!");
static const u8 sText_AttackerHealedItsFrostbite[] = _("¡{B_ATK_NAME_WITH_PREFIX} cura su congelación\ncon pura determinación!");
static const u8 sText_AttackerMeltedTheIce[] = _("¡{B_ATK_NAME_WITH_PREFIX} derrite el hielo\ncon su ardiente determinación!");
static const u8 sText_TargetToughedItOut[] = _("¡{B_DEF_NAME_WITH_PREFIX} aguanta para\nmostrar su mejor cara!");
static const u8 sText_AttackerLostElectricType[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha gastado\ntoda su electricidad!");
static const u8 sText_AttackerSwitchedStatWithTarget[] = _("¡{B_ATK_NAME_WITH_PREFIX} intercambia\n{B_BUFF1} con el objetivo!");
static const u8 sText_BeingHitChargedPkmnWithPower[] = _("¡Recibir {B_CURRENT_MOVE} ha\ncargado de energía a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_SunlightActivatedAbility[] = _("¡El sol intenso activa\n{B_LAST_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_StatWasHeightened[] = _("¡{B_BUFF1} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nha aumentado!");
static const u8 sText_BoosterEnergyActivates[] = _("¡La Energía Potenciadora de\n{B_SCR_ACTIVE_NAME_WITH_PREFIX} activa\l{B_SCR_ACTIVE_ABILITY}!");
static const u8 sText_ElectricTerrainActivatedAbility[] = _("¡El Campo Eléctrico activa\n{B_LAST_ABILITY} de {B_SCR_ACTIVE_NAME_WITH_PREFIX}!");
static const u8 sText_AbilityWeakenedSurroundingMonsStat[] = _("¡{B_ATK_ABILITY} de {B_ATK_NAME_WITH_PREFIX}\nreduce {B_BUFF1} de\ltodos los Pokémon a su alrededor!\p");
static const u8 sText_AttackerGainedStrengthFromTheFallen[] = _("¡{B_ATK_NAME_WITH_PREFIX} se fortalece\ncon los caídos!");
static const u8 sText_PrepareShellTrap[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha preparado\nuna coraza trampa!");
static const u8 sText_ShellTrapDidntWork[] = _("¡La coraza trampa de\n{B_ATK_NAME_WITH_PREFIX} ha fallado!");
static const u8 sText_SharpSteelFloats[] = _("¡Flotan púas de acero alrededor\ndel equipo {B_DEF_TEAM2}!");
static const u8 sText_SharpSteelDmg[] = _("¡Las púas de acero hieren\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_PkmnBlewAwaySharpSteel[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha barrido\nlas púas de acero!");
static const u8 sText_SharpSteelDisappearedFromTeam[] = _("¡Las púas de acero han desaparecido\ndel suelo del equipo {B_ATK_TEAM2}!");
static const u8 sText_TeamTrappedWithVines[] = _("¡El equipo {B_DEF_TEAM1} ha quedado\natrapado entre lianas!");
static const u8 sText_PkmnHurtByVines[] = _("¡Los latigazos del Gigalianas\nhieren a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_TeamCaughtInVortex[] = _("¡El equipo {B_DEF_TEAM1} ha quedado\natrapado en un torbellino de agua!");
static const u8 sText_PkmnHurtByVortex[] = _("¡El torbellino del Gigacañonazo\nhiere a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_TeamSurroundedByFire[] = _("¡El equipo {B_DEF_TEAM1} está\nrodeado de llamas!");
static const u8 sText_PkmnBurningUp[] = _("¡{B_ATK_NAME_WITH_PREFIX} arde entre las\nllamas del Gigallamarada!");
static const u8 sText_TeamSurroundedByRocks[] = _("¡El equipo {B_DEF_TEAM1} está\nrodeado de rocas!");
static const u8 sText_PkmnHurtByRocksThrown[] = _("¡Las rocas del Gigarroca Ígnea\nhieren a {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_CouldntFullyProtect[] = _("¡{B_DEF_NAME_WITH_PREFIX} no ha podido\nprotegerse del todo y ha\lresultado herido!");
static const u8 sText_StockpiledEffectWoreOff[] = _("¡El efecto de Reserva de\n{B_ATK_NAME_WITH_PREFIX} ha terminado!");
static const u8 sText_MoveBlockedByDynamax[] = _("¡El poder Dinamax ha\nbloqueado el movimiento!");
static const u8 sText_PkmnRevivedReadyToFight[] = _("¡{B_BUFF1} se ha reanimado\ny puede volver a luchar!");
static const u8 sText_ItemRestoredSpeciesHealth[] = _("¡{B_BUFF1} ha\nrecuperado PS!");
static const u8 sText_ItemCuredSpeciesStatus[] = _("¡{B_BUFF1} se ha\ncurado de su estado!");
static const u8 sText_ItemRestoredSpeciesPP[] = _("¡{B_BUFF1} ha\nrecuperado PP!");
static const u8 sText_AtkTrappedDef[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha atrapado\na {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_MirrorHerbCopied[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} usa {B_LAST_ITEM}\ny copia los cambios de\lcaracterísticas del rival!");
static const u8 sText_PkmnItemMelted[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha corroído\n{B_LAST_ITEM} de {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_UltraBurstReacting[] = _("¡Una luz cegadora está a punto\nde brotar de {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_UltraBurstCompleted[] = _("¡{B_ATK_NAME_WITH_PREFIX} recupera su\nverdadero poder con el Ultraestallido!");
static const u8 sText_TeamGainedEXP[] = _("¡El resto de tu equipo gana\nPUNTOS EXP. gracias a {B_LAST_ITEM}!\p");
static const u8 sText_CurrentMoveCantSelect[] = _("¡No se puede usar {B_BUFF1}!\p");
static const u8 sText_TargetIsBeingSaltCured[] = _("¡{B_DEF_NAME_WITH_PREFIX} está en salazón!");
static const u8 sText_TargetIsHurtBySaltCure[] = _("¡{B_BUFF1} hiere a {B_DEF_NAME_WITH_PREFIX}!");
static const u8 sText_OpportunistCopied[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} copia los cambios\nde características del rival!");
static const u8 sText_TargetCoveredInStickyCandySyrup[] = _("¡{B_DEF_NAME_WITH_PREFIX} ha quedado\ncubierto de sirope pegajoso!");
static const u8 sText_PkmnTellChillingReceptionJoke[] = _("¡{B_ATK_NAME_WITH_PREFIX} se prepara para contar\nun chiste malísimo y gélido!");
static const u8 sText_ZeroToHeroTransformation[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha sufrido una\ntransformación heroica!");
static const u8 sText_TheTwoMovesBecomeOne[] = _("¡Los dos movimientos se unen!\n¡Es un movimiento combinado!{PAUSE 16}");
static const u8 sText_ARainbowAppearedOnSide[] = _("¡Ha aparecido un arcoíris en el\ncielo del equipo {B_ATK_TEAM2}!");
static const u8 sText_TheRainbowDisappeared[] = _("¡El arcoíris del equipo\n{B_ATK_TEAM2} ha desaparecido!");
static const u8 sText_WaitingForPartnersMove[] = _("{B_ATK_NAME_WITH_PREFIX} espera el\nmovimiento de {B_ATK_PARTNER_NAME}…{PAUSE 16}");
static const u8 sText_SeaOfFireEnvelopedSide[] = _("¡Un mar de llamas envuelve\nal equipo {B_DEF_TEAM2}!");
static const u8 sText_HurtByTheSeaOfFire[] = _("¡El mar de llamas hiere\na {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_TheSeaOfFireDisappeared[] = _("¡El mar de llamas del equipo\n{B_ATK_TEAM2} ha desaparecido!");
static const u8 sText_SwampEnvelopedSide[] = _("¡Un pantano envuelve\nal equipo {B_DEF_TEAM2}!");
static const u8 sText_TheSwampDisappeared[] = _("¡El pantano del equipo\n{B_ATK_TEAM2} ha desaparecido!");
static const u8 sText_ShedItsTail[] = _("¡{B_ATK_NAME_WITH_PREFIX} se desprende de\nsu cola para crear un señuelo!");
static const u8 sText_TidyingUpComplete[] = _("¡Limpieza completada!");
static const u8 sText_HospitalityRestoration[] = _("¡{B_ATK_PARTNER_NAME} se ha bebido todo el\nté que ha preparado {B_ATK_NAME_WITH_PREFIX}!");
static const u8 sText_SupersweetAromaWafts[] = _("¡El sirope que cubre a {B_ATK_NAME_WITH_PREFIX}\ndesprende un aroma dulcísimo!");
static const u8 sText_PkmnTerastallizedInto[] = _("¡{B_ATK_NAME_WITH_PREFIX} se ha teracristalizado\nen tipo {B_BUFF1}!");
static const u8 sText_ElectroShotCharging[] = _("¡{B_ATK_NAME_WITH_PREFIX} ha absorbido\nelectricidad!");

const u8 *const gBattleStringsTable[BATTLESTRINGS_COUNT] =
{
    [STRINGID_PKMNTERASTALLIZEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTerastallizedInto,
    [STRINGID_SUPERSWEETAROMAWAFTS - BATTLESTRINGS_TABLE_START] = sText_SupersweetAromaWafts,
    [STRINGID_HOSPITALITYRESTORATION - BATTLESTRINGS_TABLE_START] = sText_HospitalityRestoration,
    [STRINGID_TIDYINGUPCOMPLETE - BATTLESTRINGS_TABLE_START] = sText_TidyingUpComplete,
    [STRINGID_SHEDITSTAIL - BATTLESTRINGS_TABLE_START] = sText_ShedItsTail,
    [STRINGID_THESWAMPDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheSwampDisappeared,
    [STRINGID_SWAMPENVELOPEDSIDE - BATTLESTRINGS_TABLE_START] = sText_SwampEnvelopedSide,
    [STRINGID_THESEAOFFIREDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheSeaOfFireDisappeared,
    [STRINGID_HURTBYTHESEAOFFIRE - BATTLESTRINGS_TABLE_START] = sText_HurtByTheSeaOfFire,
    [STRINGID_SEAOFFIREENVELOPEDSIDE - BATTLESTRINGS_TABLE_START] = sText_SeaOfFireEnvelopedSide,
    [STRINGID_WAITINGFORPARTNERSMOVE - BATTLESTRINGS_TABLE_START] = sText_WaitingForPartnersMove,
    [STRINGID_THERAINBOWDISAPPEARED - BATTLESTRINGS_TABLE_START] = sText_TheRainbowDisappeared,
    [STRINGID_ARAINBOWAPPEAREDONSIDE - BATTLESTRINGS_TABLE_START] = sText_ARainbowAppearedOnSide,
    [STRINGID_THETWOMOVESBECOMEONE - BATTLESTRINGS_TABLE_START] = sText_TheTwoMovesBecomeOne,
    [STRINGID_ZEROTOHEROTRANSFORMATION - BATTLESTRINGS_TABLE_START] = sText_ZeroToHeroTransformation,
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE - BATTLESTRINGS_TABLE_START] = sText_PkmnTellChillingReceptionJoke,
    [STRINGID_MOVEBLOCKEDBYDYNAMAX - BATTLESTRINGS_TABLE_START] = sText_MoveBlockedByDynamax,
    [STRINGID_OPPORTUNISTCOPIED - BATTLESTRINGS_TABLE_START] = sText_OpportunistCopied,
    [STRINGID_TARGETISHURTBYSALTCURE - BATTLESTRINGS_TABLE_START] = sText_TargetIsHurtBySaltCure,
    [STRINGID_TARGETISBEINGSALTCURED - BATTLESTRINGS_TABLE_START] = sText_TargetIsBeingSaltCured,
    [STRINGID_CURRENTMOVECANTSELECT - BATTLESTRINGS_TABLE_START] = sText_CurrentMoveCantSelect,
    [STRINGID_PKMNITEMMELTED - BATTLESTRINGS_TABLE_START] = sText_PkmnItemMelted,
    [STRINGID_MIRRORHERBCOPIED - BATTLESTRINGS_TABLE_START] = sText_MirrorHerbCopied,
    [STRINGID_THUNDERCAGETRAPPED - BATTLESTRINGS_TABLE_START] = sText_AtkTrappedDef,
    [STRINGID_ITEMRESTOREDSPECIESHEALTH - BATTLESTRINGS_TABLE_START] = sText_ItemRestoredSpeciesHealth,
    [STRINGID_ITEMCUREDSPECIESSTATUS - BATTLESTRINGS_TABLE_START] = sText_ItemCuredSpeciesStatus,
    [STRINGID_ITEMRESTOREDSPECIESPP - BATTLESTRINGS_TABLE_START] = sText_ItemRestoredSpeciesPP,
    [STRINGID_PKMNREVIVEDREADYTOFIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnRevivedReadyToFight,
    [STRINGID_STOCKPILEDEFFECTWOREOFF - BATTLESTRINGS_TABLE_START] = sText_StockpiledEffectWoreOff,
    [STRINGID_COULDNTFULLYPROTECT - BATTLESTRINGS_TABLE_START] = sText_CouldntFullyProtect,
    [STRINGID_PKMNHURTBYROCKSTHROWN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByRocksThrown,
    [STRINGID_TEAMSURROUNDEDBYROCKS - BATTLESTRINGS_TABLE_START] = sText_TeamSurroundedByRocks,
    [STRINGID_PKMNBURNINGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnBurningUp,
    [STRINGID_TEAMSURROUNDEDBYFIRE - BATTLESTRINGS_TABLE_START] = sText_TeamSurroundedByFire,
    [STRINGID_PKMNHURTBYVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByVortex,
    [STRINGID_TEAMCAUGHTINVORTEX - BATTLESTRINGS_TABLE_START] = sText_TeamCaughtInVortex,
    [STRINGID_PKMNHURTBYVINES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByVines,
    [STRINGID_TEAMTRAPPEDWITHVINES - BATTLESTRINGS_TABLE_START] = sText_TeamTrappedWithVines,
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySharpSteel,
    [STRINGID_SHARPSTEELDMG - BATTLESTRINGS_TABLE_START] = sText_SharpSteelDmg,
    [STRINGID_SHARPSTEELFLOATS - BATTLESTRINGS_TABLE_START] = sText_SharpSteelFloats,
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN - BATTLESTRINGS_TABLE_START] = sText_AttackerGainedStrengthFromTheFallen,
    [STRINGID_ABILITYWEAKENEDFSURROUNDINGMONSSTAT - BATTLESTRINGS_TABLE_START] = sText_AbilityWeakenedSurroundingMonsStat,
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainActivatedAbility,
    [STRINGID_STATWASHEIGHTENED - BATTLESTRINGS_TABLE_START] = sText_StatWasHeightened,
    [STRINGID_SUNLIGHTACTIVATEDABILITY - BATTLESTRINGS_TABLE_START] = sText_SunlightActivatedAbility,
    [STRINGID_POISONPUPPETEER - BATTLESTRINGS_TABLE_START] = sText_PoisonPuppeteer,
    [STRINGID_BOOSTERENERGYACTIVATES - BATTLESTRINGS_TABLE_START] = sText_BoosterEnergyActivates,
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER - BATTLESTRINGS_TABLE_START] = sText_BeingHitChargedPkmnWithPower,
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET - BATTLESTRINGS_TABLE_START] = sText_AttackerSwitchedStatWithTarget,
    [STRINGID_TARGETTOUGHEDITOUT - BATTLESTRINGS_TABLE_START] = sText_TargetToughedItOut,
    [STRINGID_ATTACKERMELTEDTHEICE - BATTLESTRINGS_TABLE_START] = sText_AttackerMeltedTheIce,
    [STRINGID_ATTACKERHEALEDITSBURN - BATTLESTRINGS_TABLE_START] = sText_AttackerHealedItsBurn,
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_AttackerBrokeThroughParalysis,
    [STRINGID_ATTACKERSHOOKITSELFAWAKE - BATTLESTRINGS_TABLE_START] = sText_AttackerShookItselfAwake,
    [STRINGID_ATTACKEREXPELLEDTHEPOISON - BATTLESTRINGS_TABLE_START] = sText_AttackerExpelledThePoison,
    [STRINGID_ZPOWERSURROUNDS - BATTLESTRINGS_TABLE_START] = sText_ZPowerSurrounds,
    [STRINGID_ZMOVEUNLEASHED - BATTLESTRINGS_TABLE_START] = sText_ZPowerUnleashed,
    [STRINGID_ZMOVERESETSSTATS - BATTLESTRINGS_TABLE_START] = sText_ZMoveResetsStats,
    [STRINGID_ZMOVEALLSTATSUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveAllStatsUp,
    [STRINGID_ZMOVEZBOOSTCRIT - BATTLESTRINGS_TABLE_START] = sText_ZMoveBoostCrit,
    [STRINGID_ZMOVERESTOREHP - BATTLESTRINGS_TABLE_START] = sText_ZMoveRestoreHp,
    [STRINGID_ZMOVESTATUP - BATTLESTRINGS_TABLE_START] = sText_ZMoveStatUp,
    [STRINGID_ZMOVEHPTRAP - BATTLESTRINGS_TABLE_START] = sText_ZMoveHpSwitchInTrap,
    [STRINGID_PLAYERLOSTTOENEMYTRAINER - BATTLESTRINGS_TABLE_START] = sText_PlayerLostToEnemyTrainer,
    [STRINGID_PLAYERPAIDPRIZEMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPaidPrizeMoney,
    [STRINGID_SHELLTRAPDIDNTWORK - BATTLESTRINGS_TABLE_START] = sText_ShellTrapDidntWork,
    [STRINGID_PREPARESHELLTRAP - BATTLESTRINGS_TABLE_START] = sText_PrepareShellTrap,
    [STRINGID_COURTCHANGE - BATTLESTRINGS_TABLE_START] = sText_CourtChange,
    [STRINGID_HEATUPBEAK - BATTLESTRINGS_TABLE_START] = sText_HeatingUpBeak,
    [STRINGID_METEORBEAMCHARGING - BATTLESTRINGS_TABLE_START] = sText_MeteorBeamCharging,
    [STRINGID_ELECTROSHOTCHARGING - BATTLESTRINGS_TABLE_START] = sText_ElectroShotCharging,
    [STRINGID_PKMNINSNAPTRAP - BATTLESTRINGS_TABLE_START] = sText_PkmnInSnapTrap,
    [STRINGID_NEUTRALIZINGGASOVER - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasOver,
    [STRINGID_NEUTRALIZINGGASENTERS - BATTLESTRINGS_TABLE_START] = sText_NeutralizingGasEnters,
    [STRINGID_BATTLERTYPECHANGEDTO - BATTLESTRINGS_TABLE_START] = sText_BattlerTypeChangedTo,
    [STRINGID_PASTELVEILENTERS - BATTLESTRINGS_TABLE_START] = sText_PastelVeilEnters,
    [STRINGID_PASTELVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_PastelVeilProtected,
    [STRINGID_SWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_SwappedAbilities,
    [STRINGID_ABILITYALLOWSONLYMOVE - BATTLESTRINGS_TABLE_START] = sText_AbilityAllowsOnlyMove,
    [STRINGID_BROKETHROUGHPROTECTION - BATTLESTRINGS_TABLE_START] = sText_BrokeThroughProtection,
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE - BATTLESTRINGS_TABLE_START] = sText_ButPokemonCantUseTheMove,
    [STRINGID_BUTHOOPACANTUSEIT - BATTLESTRINGS_TABLE_START] = sText_ButHoopaCantUseIt,
    [STRINGID_PKMNREVERTEDTOPRIMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnRevertedToPrimal,
    [STRINGID_STUFFCHEEKSCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_StuffCheeksCantSelect,
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS - BATTLESTRINGS_TABLE_START] = sText_AttackWeakenedByStrongWinds,
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrentBlowsOn,
    [STRINGID_STRONGWINDSDISSIPATED - BATTLESTRINGS_TABLE_START] = sText_StrongWindsDissipated,
    [STRINGID_MYSTERIOUSAIRCURRENT - BATTLESTRINGS_TABLE_START] = sText_MysteriousAirCurrent,
    [STRINGID_NORELIEFROMHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_NoReliefFromHeavyRain,
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_MoveFizzledOutInTheHeavyRain,
    [STRINGID_HEAVYRAINLIFTED - BATTLESTRINGS_TABLE_START] = sText_HeavyRainLifted,
    [STRINGID_HEAVYRAIN - BATTLESTRINGS_TABLE_START] = sText_HeavyRain,
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlightWasNotLessened,
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_MoveEvaporatedInTheHarshSunlight,
    [STRINGID_EXTREMESUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_ExtremeSunlightFaded,
    [STRINGID_EXTREMELYHARSHSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_ExtremelyHarshSunlight,
    [STRINGID_ATTACKERBECAMEASHSPECIES - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameAshSpecies,
    [STRINGID_ATTACKERBECAMEFULLYCHARGED - BATTLESTRINGS_TABLE_START] = sText_AttackerBecameFullyCharged,
    [STRINGID_HEALBLOCKEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_HealBlockedNoMore,
    [STRINGID_TORMENTEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_TormentedNoMore,
    [STRINGID_ATKGOTOVERINFATUATION - BATTLESTRINGS_TABLE_START] = sText_AttackerGotOverInfatuation,
    [STRINGID_EJECTBUTTONACTIVATE - BATTLESTRINGS_TABLE_START] = sText_EjectButtonActivate,
    [STRINGID_REDCARDACTIVATE - BATTLESTRINGS_TABLE_START] = sText_RedCardActivate,
    [STRINGID_PKMNBURNHEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnHealed,
    [STRINGID_STICKYBARBTRANSFER - BATTLESTRINGS_TABLE_START] = sText_StickyBarbTransfer,
    [STRINGID_ITEMCANNOTBEREMOVED - BATTLESTRINGS_TABLE_START] = sText_ItemCannotBeRemoved,
    [STRINGID_PKMNGOTOVERITSINFATUATION - BATTLESTRINGS_TABLE_START] = sText_PkmnGotOverItsInfatuation,
    [STRINGID_PKMNSHOOKOFFTHETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnShookOffTheTaunt,
    [STRINGID_MICLEBERRYACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MicleBerryActivates,
    [STRINGID_CANACTFASTERTHANKSTO - BATTLESTRINGS_TABLE_START] = sText_CanActFaster,
    [STRINGID_CURIOUSMEDICINEENTERS - BATTLESTRINGS_TABLE_START] = sText_CuriousMedicineEnters,
    [STRINGID_ASONEENTERS - BATTLESTRINGS_TABLE_START] = sText_AsOneEnters,
    [STRINGID_PKMNMADESHELLGLEAM - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeShellGleam,
    [STRINGID_ABILITYRAISEDSTATDRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_AbilityRaisedStatDrastically,
    [STRINGID_PKMNSWILLPERISHIN3TURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsWillPerishIn3Turns,
    [STRINGID_ASANDSTORMKICKEDUP - BATTLESTRINGS_TABLE_START] = sText_ASandstormKickedUp,
    [STRINGID_BATTLERABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_BattlerAbilityRaisedStat,
    [STRINGID_FETCHEDPOKEBALL - BATTLESTRINGS_TABLE_START] = sText_FetchedPokeBall,
    [STRINGID_CLEARAMULETWONTLOWERSTATS - BATTLESTRINGS_TABLE_START] = sText_ClearAmuletWontLowerStats,
    [STRINGID_CLOAKEDINAFREEZINGLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInAFreezingLight,
    [STRINGID_DESTINYKNOTACTIVATES - BATTLESTRINGS_TABLE_START] = sText_DestinyKnotActivates,
    [STRINGID_NOONEWILLBEABLETORUNAWAY - BATTLESTRINGS_TABLE_START] = sText_NoOneWillBeAbleToRun,
    [STRINGID_PKNMABSORBINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbingPower,
    [STRINGID_RECEIVERABILITYTAKEOVER - BATTLESTRINGS_TABLE_START] = sText_ReceiverAbilityTakeOver,
    [STRINGID_SCRIPTINGABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_ScriptingAbilityRaisedStat,
    [STRINGID_HEALERCURE - BATTLESTRINGS_TABLE_START] = sText_HealerCure,
    [STRINGID_ATTACKERLOSTFIRETYPE - BATTLESTRINGS_TABLE_START] = sText_AttackerLostFireType,
    [STRINGID_ATTACKERCUREDTARGETSTATUS - BATTLESTRINGS_TABLE_START] = sText_AttackerCuredTargetStatus,
    [STRINGID_ILLUSIONWOREOFF - BATTLESTRINGS_TABLE_START] = sText_IllusionWoreOff,
    [STRINGID_BUGBITE - BATTLESTRINGS_TABLE_START] = sText_BugBite,
    [STRINGID_INCINERATEBURN - BATTLESTRINGS_TABLE_START] = sText_IncinerateBurn,
    [STRINGID_AIRBALLOONPOP - BATTLESTRINGS_TABLE_START] = sText_AirBalloonPop,
    [STRINGID_AIRBALLOONFLOAT - BATTLESTRINGS_TABLE_START] = sText_AirBalloonFloat,
    [STRINGID_TARGETATEITEM - BATTLESTRINGS_TABLE_START] = sText_TargetAteItem,
    [STRINGID_BERRYDMGREDUCES - BATTLESTRINGS_TABLE_START] = sText_BerryDmgReducing,
    [STRINGID_GEMACTIVATES - BATTLESTRINGS_TABLE_START] = sText_GemActivates,
    [STRINGID_LASERFOCUS - BATTLESTRINGS_TABLE_START] = sText_LaserFocusMessage,
    [STRINGID_THROATCHOPENDS - BATTLESTRINGS_TABLE_START] = sText_ThroatChopEnds,
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveThroatChop,
    [STRINGID_USEDINSTRUCTEDMOVE - BATTLESTRINGS_TABLE_START] = sText_UsedInstructedMove,
    [STRINGID_CELEBRATEMESSAGE - BATTLESTRINGS_TABLE_START] = sText_CelebrateMessage,
    [STRINGID_AROMAVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_AromaVeilProtected,
    [STRINGID_SWEETVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SweetVeilProtected,
    [STRINGID_FLOWERVEILPROTECTED - BATTLESTRINGS_TABLE_START] = sText_FlowerVeilProtected,
    [STRINGID_SAFETYGOGGLESPROTECTED - BATTLESTRINGS_TABLE_START] = sText_SafetyGogglesProtected,
    [STRINGID_SPECTRALTHIEFSTEAL - BATTLESTRINGS_TABLE_START] = sText_SpectralThiefSteal,
    [STRINGID_BELCHCANTSELECT - BATTLESTRINGS_TABLE_START] = sText_BelchCantUse,
    [STRINGID_TRAINER1LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1LoseText,
    [STRINGID_PKMNGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_PkmnGainedEXP,
    [STRINGID_PKMNGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_PkmnGrewToLv,
    [STRINGID_TEAMGREWTOLV - BATTLESTRINGS_TABLE_START] = sText_TeamGrewToLv,
    [STRINGID_PKMNLEARNEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove,
    [STRINGID_TRYTOLEARNMOVE1 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove1,
    [STRINGID_TRYTOLEARNMOVE2 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove2,
    [STRINGID_TRYTOLEARNMOVE3 - BATTLESTRINGS_TABLE_START] = sText_TryToLearnMove3,
    [STRINGID_PKMNFORGOTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnForgotMove,
    [STRINGID_STOPLEARNINGMOVE - BATTLESTRINGS_TABLE_START] = sText_StopLearningMove,
    [STRINGID_DIDNOTLEARNMOVE - BATTLESTRINGS_TABLE_START] = sText_DidNotLearnMove,
    [STRINGID_PKMNLEARNEDMOVE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnLearnedMove2,
    [STRINGID_ATTACKMISSED - BATTLESTRINGS_TABLE_START] = sText_AttackMissed,
    [STRINGID_PKMNPROTECTEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself,
    [STRINGID_STATSWONTINCREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease2,
    [STRINGID_AVOIDEDDAMAGE - BATTLESTRINGS_TABLE_START] = sText_AvoidedDamage,
    [STRINGID_ITDOESNTAFFECT - BATTLESTRINGS_TABLE_START] = sText_ItDoesntAffect,
    [STRINGID_ATTACKERFAINTED - BATTLESTRINGS_TABLE_START] = sText_AttackerFainted,
    [STRINGID_TARGETFAINTED - BATTLESTRINGS_TABLE_START] = sText_TargetFainted,
    [STRINGID_PLAYERGOTMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerGotMoney,
    [STRINGID_PLAYERWHITEOUT - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout,
    [STRINGID_PLAYERWHITEOUT2 - BATTLESTRINGS_TABLE_START] = sText_PlayerWhiteout2,
    [STRINGID_PREVENTSESCAPE - BATTLESTRINGS_TABLE_START] = sText_PreventsEscape,
    [STRINGID_HITXTIMES - BATTLESTRINGS_TABLE_START] = sText_HitXTimes,
    [STRINGID_PKMNFELLASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFellAsleep,
    [STRINGID_PKMNMADESLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSleep,
    [STRINGID_PKMNALREADYASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep,
    [STRINGID_PKMNALREADYASLEEP2 - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyAsleep2,
    [STRINGID_PKMNWASNTAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasntAffected,
    [STRINGID_PKMNWASPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasPoisoned,
    [STRINGID_PKMNPOISONEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnPoisonedBy,
    [STRINGID_PKMNHURTBYPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByPoison,
    [STRINGID_PKMNALREADYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyPoisoned,
    [STRINGID_PKMNBADLYPOISONED - BATTLESTRINGS_TABLE_START] = sText_PkmnBadlyPoisoned,
    [STRINGID_PKMNENERGYDRAINED - BATTLESTRINGS_TABLE_START] = sText_PkmnEnergyDrained,
    [STRINGID_PKMNWASBURNED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasBurned,
    [STRINGID_PKMNBURNEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnBurnedBy,
    [STRINGID_PKMNHURTBYBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByBurn,
    [STRINGID_PKMNWASFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnWasFrozen,
    [STRINGID_PKMNFROZENBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrozenBy,
    [STRINGID_PKMNISFROZEN - BATTLESTRINGS_TABLE_START] = sText_PkmnIsFrozen,
    [STRINGID_PKMNWASDEFROSTED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted,
    [STRINGID_PKMNWASDEFROSTED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrosted2,
    [STRINGID_PKMNWASDEFROSTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDefrostedBy,
    [STRINGID_PKMNWASPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzed,
    [STRINGID_PKMNWASPARALYZEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasParalyzedBy,
    [STRINGID_PKMNISPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsParalyzed,
    [STRINGID_PKMNISALREADYPARALYZED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAlreadyParalyzed,
    [STRINGID_PKMNHEALEDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedParalysis,
    [STRINGID_PKMNDREAMEATEN - BATTLESTRINGS_TABLE_START] = sText_PkmnDreamEaten,
    [STRINGID_STATSWONTINCREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontIncrease,
    [STRINGID_STATSWONTDECREASE - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease,
    [STRINGID_TEAMSTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_TeamStoppedWorking,
    [STRINGID_FOESTOPPEDWORKING - BATTLESTRINGS_TABLE_START] = sText_FoeStoppedWorking,
    [STRINGID_PKMNISCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnIsConfused,
    [STRINGID_PKMNHEALEDCONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnHealedConfusion,
    [STRINGID_PKMNWASCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnWasConfused,
    [STRINGID_PKMNALREADYCONFUSED - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyConfused,
    [STRINGID_PKMNFELLINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellInLove,
    [STRINGID_PKMNINLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnInLove,
    [STRINGID_PKMNIMMOBILIZEDBYLOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnImmobilizedByLove,
    [STRINGID_PKMNBLOWNAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnBlownAway,
    [STRINGID_PKMNCHANGEDTYPE - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedType,
    [STRINGID_PKMNFLINCHED - BATTLESTRINGS_TABLE_START] = sText_PkmnFlinched,
    [STRINGID_PKMNREGAINEDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnRegainedHealth,
    [STRINGID_PKMNHPFULL - BATTLESTRINGS_TABLE_START] = sText_PkmnHPFull,
    [STRINGID_PKMNRAISEDSPDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDef,
    [STRINGID_PKMNRAISEDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDef,
    [STRINGID_PKMNCOVEREDBYVEIL - BATTLESTRINGS_TABLE_START] = sText_PkmnCoveredByVeil,
    [STRINGID_PKMNUSEDSAFEGUARD - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedSafeguard,
    [STRINGID_PKMNSAFEGUARDEXPIRED - BATTLESTRINGS_TABLE_START] = sText_PkmnSafeguardExpired,
    [STRINGID_PKMNWENTTOSLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnWentToSleep,
    [STRINGID_PKMNSLEPTHEALTHY - BATTLESTRINGS_TABLE_START] = sText_PkmnSleptHealthy,
    [STRINGID_PKMNWHIPPEDWHIRLWIND - BATTLESTRINGS_TABLE_START] = sText_PkmnWhippedWhirlwind,
    [STRINGID_PKMNTOOKSUNLIGHT - BATTLESTRINGS_TABLE_START] = sText_PkmnTookSunlight,
    [STRINGID_PKMNLOWEREDHEAD - BATTLESTRINGS_TABLE_START] = sText_PkmnLoweredHead,
    [STRINGID_PKMNISGLOWING - BATTLESTRINGS_TABLE_START] = sText_PkmnIsGlowing,
    [STRINGID_PKMNFLEWHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnFlewHigh,
    [STRINGID_PKMNDUGHOLE - BATTLESTRINGS_TABLE_START] = sText_PkmnDugHole,
    [STRINGID_PKMNSQUEEZEDBYBIND - BATTLESTRINGS_TABLE_START] = sText_PkmnSqueezedByBind,
    [STRINGID_PKMNTRAPPEDINVORTEX - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedInVortex,
    [STRINGID_PKMNWRAPPEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnWrappedBy,
    [STRINGID_PKMNCLAMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnClamped,
    [STRINGID_PKMNHURTBY - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBy,
    [STRINGID_PKMNFREEDFROM - BATTLESTRINGS_TABLE_START] = sText_PkmnFreedFrom,
    [STRINGID_PKMNCRASHED - BATTLESTRINGS_TABLE_START] = sText_PkmnCrashed,
    [STRINGID_PKMNSHROUDEDINMIST - BATTLESTRINGS_TABLE_START] = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedByMist,
    [STRINGID_PKMNGETTINGPUMPED - BATTLESTRINGS_TABLE_START] = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL - BATTLESTRINGS_TABLE_START] = sText_PkmnHitWithRecoil,
    [STRINGID_PKMNPROTECTEDITSELF2 - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedItself2,
    [STRINGID_PKMNBUFFETEDBYSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnBuffetedBySandstorm,
    [STRINGID_PKMNPELTEDBYHAIL - BATTLESTRINGS_TABLE_START] = sText_PkmnPeltedByHail,
    [STRINGID_PKMNSEEDED - BATTLESTRINGS_TABLE_START] = sText_PkmnSeeded,
    [STRINGID_PKMNEVADEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnEvadedAttack,
    [STRINGID_PKMNSAPPEDBYLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnSappedByLeechSeed,
    [STRINGID_PKMNFASTASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnFastAsleep,
    [STRINGID_PKMNWOKEUP - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUp,
    [STRINGID_PKMNUPROARKEPTAWAKE - BATTLESTRINGS_TABLE_START] = sText_PkmnUproarKeptAwake,
    [STRINGID_PKMNWOKEUPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnWokeUpInUproar,
    [STRINGID_PKMNCAUSEDUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCausedUproar,
    [STRINGID_PKMNMAKINGUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnMakingUproar,
    [STRINGID_PKMNCALMEDDOWN - BATTLESTRINGS_TABLE_START] = sText_PkmnCalmedDown,
    [STRINGID_PKMNCANTSLEEPINUPROAR - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar,
    [STRINGID_PKMNSTOCKPILED - BATTLESTRINGS_TABLE_START] = sText_PkmnStockpiled,
    [STRINGID_PKMNCANTSTOCKPILE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantStockpile,
    [STRINGID_PKMNCANTSLEEPINUPROAR2 - BATTLESTRINGS_TABLE_START] = sText_PkmnCantSleepInUproar2,
    [STRINGID_UPROARKEPTPKMNAWAKE - BATTLESTRINGS_TABLE_START] = sText_UproarKeptPkmnAwake,
    [STRINGID_PKMNSTAYEDAWAKEUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnStayedAwakeUsing,
    [STRINGID_PKMNSTORINGENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnStoringEnergy,
    [STRINGID_PKMNUNLEASHEDENERGY - BATTLESTRINGS_TABLE_START] = sText_PkmnUnleashedEnergy,
    [STRINGID_PKMNFATIGUECONFUSION - BATTLESTRINGS_TABLE_START] = sText_PkmnFatigueConfusion,
    [STRINGID_PLAYERPICKEDUPMONEY - BATTLESTRINGS_TABLE_START] = sText_PlayerPickedUpMoney,
    [STRINGID_PKMNUNAFFECTED - BATTLESTRINGS_TABLE_START] = sText_PkmnUnaffected,
    [STRINGID_PKMNTRANSFORMEDINTO - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformedInto,
    [STRINGID_PKMNMADESUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeSubstitute,
    [STRINGID_PKMNHASSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_PkmnHasSubstitute,
    [STRINGID_SUBSTITUTEDAMAGED - BATTLESTRINGS_TABLE_START] = sText_SubstituteDamaged,
    [STRINGID_PKMNSUBSTITUTEFADED - BATTLESTRINGS_TABLE_START] = sText_PkmnSubstituteFaded,
    [STRINGID_PKMNMUSTRECHARGE - BATTLESTRINGS_TABLE_START] = sText_PkmnMustRecharge,
    [STRINGID_PKMNRAGEBUILDING - BATTLESTRINGS_TABLE_START] = sText_PkmnRageBuilding,
    [STRINGID_PKMNMOVEWASDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveWasDisabled,
    [STRINGID_PKMNMOVEISDISABLED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveIsDisabled,
    [STRINGID_PKMNMOVEDISABLEDNOMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveDisabledNoMore,
    [STRINGID_PKMNGOTENCORE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotEncore,
    [STRINGID_PKMNENCOREENDED - BATTLESTRINGS_TABLE_START] = sText_PkmnEncoreEnded,
    [STRINGID_PKMNTOOKAIM - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAim,
    [STRINGID_PKMNSKETCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSketchedMove,
    [STRINGID_PKMNTRYINGTOTAKEFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTryingToTakeFoe,
    [STRINGID_PKMNTOOKFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnTookFoe,
    [STRINGID_PKMNREDUCEDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnReducedPP,
    [STRINGID_PKMNSTOLEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleItem,
    [STRINGID_TARGETCANTESCAPENOW - BATTLESTRINGS_TABLE_START] = sText_TargetCantEscapeNow,
    [STRINGID_PKMNFELLINTONIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnFellIntoNightmare,
    [STRINGID_PKMNLOCKEDINNIGHTMARE - BATTLESTRINGS_TABLE_START] = sText_PkmnLockedInNightmare,
    [STRINGID_PKMNLAIDCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnLaidCurse,
    [STRINGID_PKMNAFFLICTEDBYCURSE - BATTLESTRINGS_TABLE_START] = sText_PkmnAfflictedByCurse,
    [STRINGID_SPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_SpikesScattered,
    [STRINGID_PKMNHURTBYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtBySpikes,
    [STRINGID_PKMNIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_PkmnIdentified,
    [STRINGID_PKMNPERISHCOUNTFELL - BATTLESTRINGS_TABLE_START] = sText_PkmnPerishCountFell,
    [STRINGID_PKMNBRACEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnBracedItself,
    [STRINGID_PKMNENDUREDHIT - BATTLESTRINGS_TABLE_START] = sText_PkmnEnduredHit,
    [STRINGID_MAGNITUDESTRENGTH - BATTLESTRINGS_TABLE_START] = sText_MagnitudeStrength,
    [STRINGID_PKMNCUTHPMAXEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnCutHPMaxedAttack,
    [STRINGID_PKMNCOPIEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedStatChanges,
    [STRINGID_PKMNGOTFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFree,
    [STRINGID_PKMNSHEDLEECHSEED - BATTLESTRINGS_TABLE_START] = sText_PkmnShedLeechSeed,
    [STRINGID_PKMNBLEWAWAYSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwaySpikes,
    [STRINGID_PKMNFLEDFROMBATTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnFledFromBattle,
    [STRINGID_PKMNFORESAWATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnForesawAttack,
    [STRINGID_PKMNTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnTookAttack,
    [STRINGID_PKMNATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAttack,
    [STRINGID_PKMNCENTERATTENTION - BATTLESTRINGS_TABLE_START] = sText_PkmnCenterAttention,
    [STRINGID_PKMNCHARGINGPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnChargingPower,
    [STRINGID_NATUREPOWERTURNEDINTO - BATTLESTRINGS_TABLE_START] = sText_NaturePowerTurnedInto,
    [STRINGID_PKMNSTATUSNORMAL - BATTLESTRINGS_TABLE_START] = sText_PkmnStatusNormal,
    [STRINGID_PKMNHASNOMOVESLEFT - BATTLESTRINGS_TABLE_START] = sText_PkmnHasNoMovesLeft,
    [STRINGID_PKMNSUBJECTEDTOTORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnSubjectedToTorment,
    [STRINGID_PKMNCANTUSEMOVETORMENT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTorment,
    [STRINGID_PKMNTIGHTENINGFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnTighteningFocus,
    [STRINGID_PKMNFELLFORTAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnFellForTaunt,
    [STRINGID_PKMNCANTUSEMOVETAUNT - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveTaunt,
    [STRINGID_PKMNREADYTOHELP - BATTLESTRINGS_TABLE_START] = sText_PkmnReadyToHelp,
    [STRINGID_PKMNSWITCHEDITEMS - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedItems,
    [STRINGID_PKMNCOPIEDFOE - BATTLESTRINGS_TABLE_START] = sText_PkmnCopiedFoe,
    [STRINGID_PKMNMADEWISH - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeWish,
    [STRINGID_PKMNWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_PkmnWishCameTrue,
    [STRINGID_PKMNPLANTEDROOTS - BATTLESTRINGS_TABLE_START] = sText_PkmnPlantedRoots,
    [STRINGID_PKMNABSORBEDNUTRIENTS - BATTLESTRINGS_TABLE_START] = sText_PkmnAbsorbedNutrients,
    [STRINGID_PKMNANCHOREDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchoredItself,
    [STRINGID_PKMNWASMADEDROWSY - BATTLESTRINGS_TABLE_START] = sText_PkmnWasMadeDrowsy,
    [STRINGID_PKMNKNOCKEDOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnKnockedOff,
    [STRINGID_PKMNSWAPPEDABILITIES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwappedAbilities,
    [STRINGID_PKMNSEALEDOPPONENTMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSealedOpponentMove,
    [STRINGID_PKMNCANTUSEMOVESEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseMoveSealed,
    [STRINGID_PKMNWANTSGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnWantsGrudge,
    [STRINGID_PKMNLOSTPPGRUDGE - BATTLESTRINGS_TABLE_START] = sText_PkmnLostPPGrudge,
    [STRINGID_PKMNSHROUDEDITSELF - BATTLESTRINGS_TABLE_START] = sText_PkmnShroudedItself,
    [STRINGID_PKMNMOVEBOUNCED - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBounced,
    [STRINGID_PKMNWAITSFORTARGET - BATTLESTRINGS_TABLE_START] = sText_PkmnWaitsForTarget,
    [STRINGID_PKMNSNATCHEDMOVE - BATTLESTRINGS_TABLE_START] = sText_PkmnSnatchedMove,
    [STRINGID_PKMNMADEITRAIN - BATTLESTRINGS_TABLE_START] = sText_PkmnMadeItRain,
    [STRINGID_PKMNRAISEDSPEED - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpeed,
    [STRINGID_PKMNPROTECTEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnProtectedBy,
    [STRINGID_PKMNPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsUsage,
    [STRINGID_PKMNRESTOREDHPUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnRestoredHPUsing,
    [STRINGID_PKMNCHANGEDTYPEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnChangedTypeWith,
    [STRINGID_PKMNPREVENTSPARALYSISWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsParalysisWith,
    [STRINGID_PKMNPREVENTSROMANCEWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsRomanceWith,
    [STRINGID_PKMNPREVENTSPOISONINGWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsPoisoningWith,
    [STRINGID_PKMNPREVENTSCONFUSIONWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsConfusionWith,
    [STRINGID_PKMNRAISEDFIREPOWERWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedFirePowerWith,
    [STRINGID_PKMNANCHORSITSELFWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnAnchorsItselfWith,
    [STRINGID_PKMNCUTSATTACKWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnCutsAttackWith,
    [STRINGID_PKMNPREVENTSSTATLOSSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventsStatLossWith,
    [STRINGID_PKMNHURTSWITH - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtsWith,
    [STRINGID_PKMNTRACED - BATTLESTRINGS_TABLE_START] = sText_PkmnTraced,
    [STRINGID_STATSHARPLY - BATTLESTRINGS_TABLE_START] = gText_StatSharply,
    [STRINGID_STATROSE - BATTLESTRINGS_TABLE_START] = gText_StatRose,
    [STRINGID_STATHARSHLY - BATTLESTRINGS_TABLE_START] = sText_StatHarshly,
    [STRINGID_STATFELL - BATTLESTRINGS_TABLE_START] = sText_StatFell,
    [STRINGID_ATTACKERSSTATROSE - BATTLESTRINGS_TABLE_START] = sText_AttackersStatRose,
    [STRINGID_DEFENDERSSTATROSE - BATTLESTRINGS_TABLE_START] = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_AttackersStatFell,
    [STRINGID_DEFENDERSSTATFELL - BATTLESTRINGS_TABLE_START] = sText_DefendersStatFell,
    [STRINGID_CRITICALHIT - BATTLESTRINGS_TABLE_START] = sText_CriticalHit,
    [STRINGID_ONEHITKO - BATTLESTRINGS_TABLE_START] = sText_OneHitKO,
    [STRINGID_123POOF - BATTLESTRINGS_TABLE_START] = sText_123Poof,
    [STRINGID_ANDELLIPSIS - BATTLESTRINGS_TABLE_START] = sText_AndEllipsis,
    [STRINGID_NOTVERYEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_NotVeryEffective,
    [STRINGID_SUPEREFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_SuperEffective,
    [STRINGID_GOTAWAYSAFELY - BATTLESTRINGS_TABLE_START] = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED - BATTLESTRINGS_TABLE_START] = sText_WildPkmnFled,
    [STRINGID_NORUNNINGFROMTRAINERS - BATTLESTRINGS_TABLE_START] = sText_NoRunningFromTrainers,
    [STRINGID_CANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_CantEscape,
    [STRINGID_DONTLEAVEBIRCH - BATTLESTRINGS_TABLE_START] = sText_DontLeaveBirch,
    [STRINGID_BUTNOTHINGHAPPENED - BATTLESTRINGS_TABLE_START] = sText_ButNothingHappened,
    [STRINGID_BUTITFAILED - BATTLESTRINGS_TABLE_START] = sText_ButItFailed,
    [STRINGID_ITHURTCONFUSION - BATTLESTRINGS_TABLE_START] = sText_ItHurtConfusion,
    [STRINGID_MIRRORMOVEFAILED - BATTLESTRINGS_TABLE_START] = sText_MirrorMoveFailed,
    [STRINGID_STARTEDTORAIN - BATTLESTRINGS_TABLE_START] = sText_StartedToRain,
    [STRINGID_DOWNPOURSTARTED - BATTLESTRINGS_TABLE_START] = sText_DownpourStarted,
    [STRINGID_RAINCONTINUES - BATTLESTRINGS_TABLE_START] = sText_RainContinues,
    [STRINGID_DOWNPOURCONTINUES - BATTLESTRINGS_TABLE_START] = sText_DownpourContinues,
    [STRINGID_RAINSTOPPED - BATTLESTRINGS_TABLE_START] = sText_RainStopped,
    [STRINGID_SANDSTORMBREWED - BATTLESTRINGS_TABLE_START] = sText_SandstormBrewed,
    [STRINGID_SANDSTORMRAGES - BATTLESTRINGS_TABLE_START] = sText_SandstormRages,
    [STRINGID_SANDSTORMSUBSIDED - BATTLESTRINGS_TABLE_START] = sText_SandstormSubsided,
    [STRINGID_SUNLIGHTGOTBRIGHT - BATTLESTRINGS_TABLE_START] = sText_SunlightGotBright,
    [STRINGID_SUNLIGHTSTRONG - BATTLESTRINGS_TABLE_START] = sText_SunlightStrong,
    [STRINGID_SUNLIGHTFADED - BATTLESTRINGS_TABLE_START] = sText_SunlightFaded,
    [STRINGID_STARTEDHAIL - BATTLESTRINGS_TABLE_START] = sText_StartedHail,
    [STRINGID_HAILCONTINUES - BATTLESTRINGS_TABLE_START] = sText_HailContinues,
    [STRINGID_HAILSTOPPED - BATTLESTRINGS_TABLE_START] = sText_HailStopped,
    [STRINGID_STARTEDSNOW - BATTLESTRINGS_TABLE_START] = sText_StartedSnow,
    [STRINGID_SNOWCONTINUES -BATTLESTRINGS_TABLE_START] = sText_SnowContinues,
    [STRINGID_SNOWSTOPPED - BATTLESTRINGS_TABLE_START] = sText_SnowStopped,
    [STRINGID_FAILEDTOSPITUP - BATTLESTRINGS_TABLE_START] = sText_FailedToSpitUp,
    [STRINGID_FAILEDTOSWALLOW - BATTLESTRINGS_TABLE_START] = sText_FailedToSwallow,
    [STRINGID_WINDBECAMEHEATWAVE - BATTLESTRINGS_TABLE_START] = sText_WindBecameHeatWave,
    [STRINGID_STATCHANGESGONE - BATTLESTRINGS_TABLE_START] = sText_StatChangesGone,
    [STRINGID_COINSSCATTERED - BATTLESTRINGS_TABLE_START] = sText_CoinsScattered,
    [STRINGID_TOOWEAKFORSUBSTITUTE - BATTLESTRINGS_TABLE_START] = sText_TooWeakForSubstitute,
    [STRINGID_SHAREDPAIN - BATTLESTRINGS_TABLE_START] = sText_SharedPain,
    [STRINGID_BELLCHIMED - BATTLESTRINGS_TABLE_START] = sText_BellChimed,
    [STRINGID_FAINTINTHREE - BATTLESTRINGS_TABLE_START] = sText_FaintInThree,
    [STRINGID_NOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_NoPPLeft,
    [STRINGID_BUTNOPPLEFT - BATTLESTRINGS_TABLE_START] = sText_ButNoPPLeft,
    [STRINGID_PLAYERUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_PlayerUsedItem,
    [STRINGID_WALLYUSEDITEM - BATTLESTRINGS_TABLE_START] = sText_WallyUsedItem,
    [STRINGID_TRAINERBLOCKEDBALL - BATTLESTRINGS_TABLE_START] = sText_TrainerBlockedBall,
    [STRINGID_DONTBEATHIEF - BATTLESTRINGS_TABLE_START] = sText_DontBeAThief,
    [STRINGID_ITDODGEDBALL - BATTLESTRINGS_TABLE_START] = sText_ItDodgedBall,
    [STRINGID_YOUMISSEDPKMN - BATTLESTRINGS_TABLE_START] = sText_YouMissedPkmn,
    [STRINGID_PKMNBROKEFREE - BATTLESTRINGS_TABLE_START] = sText_PkmnBrokeFree,
    [STRINGID_ITAPPEAREDCAUGHT - BATTLESTRINGS_TABLE_START] = sText_ItAppearedCaught,
    [STRINGID_AARGHALMOSTHADIT - BATTLESTRINGS_TABLE_START] = sText_AarghAlmostHadIt,
    [STRINGID_SHOOTSOCLOSE - BATTLESTRINGS_TABLE_START] = sText_ShootSoClose,
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtPlayer,
    [STRINGID_GOTCHAPKMNCAUGHTWALLY - BATTLESTRINGS_TABLE_START] = sText_GotchaPkmnCaughtWally,
    [STRINGID_GIVENICKNAMECAPTURED - BATTLESTRINGS_TABLE_START] = sText_GiveNicknameCaptured,
    [STRINGID_PKMNSENTTOPC - BATTLESTRINGS_TABLE_START] = sText_PkmnSentToPC,
    [STRINGID_PKMNDATAADDEDTODEX - BATTLESTRINGS_TABLE_START] = sText_PkmnDataAddedToDex,
    [STRINGID_ITISRAINING - BATTLESTRINGS_TABLE_START] = sText_ItIsRaining,
    [STRINGID_SANDSTORMISRAGING - BATTLESTRINGS_TABLE_START] = sText_SandstormIsRaging,
    [STRINGID_CANTESCAPE2 - BATTLESTRINGS_TABLE_START] = sText_CantEscape2,
    [STRINGID_PKMNIGNORESASLEEP - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoresAsleep,
    [STRINGID_PKMNIGNOREDORDERS - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredOrders,
    [STRINGID_PKMNBEGANTONAP - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganToNap,
    [STRINGID_PKMNLOAFING - BATTLESTRINGS_TABLE_START] = sText_PkmnLoafing,
    [STRINGID_PKMNWONTOBEY - BATTLESTRINGS_TABLE_START] = sText_PkmnWontObey,
    [STRINGID_PKMNTURNEDAWAY - BATTLESTRINGS_TABLE_START] = sText_PkmnTurnedAway,
    [STRINGID_PKMNPRETENDNOTNOTICE - BATTLESTRINGS_TABLE_START] = sText_PkmnPretendNotNotice,
    [STRINGID_ENEMYABOUTTOSWITCHPKMN - BATTLESTRINGS_TABLE_START] = sText_EnemyAboutToSwitchPkmn,
    [STRINGID_CREPTCLOSER - BATTLESTRINGS_TABLE_START] = sText_CreptCloser,
    [STRINGID_CANTGETCLOSER - BATTLESTRINGS_TABLE_START] = sText_CantGetCloser,
    [STRINGID_PKMNWATCHINGCAREFULLY - BATTLESTRINGS_TABLE_START] = sText_PkmnWatchingCarefully,
    [STRINGID_PKMNCURIOUSABOUTX - BATTLESTRINGS_TABLE_START] = sText_PkmnCuriousAboutX,
    [STRINGID_PKMNENTHRALLEDBYX - BATTLESTRINGS_TABLE_START] = sText_PkmnEnthralledByX,
    [STRINGID_PKMNIGNOREDX - BATTLESTRINGS_TABLE_START] = sText_PkmnIgnoredX,
    [STRINGID_THREWPOKEBLOCKATPKMN - BATTLESTRINGS_TABLE_START] = sText_ThrewPokeblockAtPkmn,
    [STRINGID_OUTOFSAFARIBALLS - BATTLESTRINGS_TABLE_START] = sText_OutOfSafariBalls,
    [STRINGID_PKMNSITEMCUREDPARALYSIS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredParalysis,
    [STRINGID_PKMNSITEMCUREDPOISON - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredPoison,
    [STRINGID_PKMNSITEMHEALEDBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedBurn,
    [STRINGID_PKMNSITEMDEFROSTEDIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemDefrostedIt,
    [STRINGID_PKMNSITEMWOKEIT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemWokeIt,
    [STRINGID_PKMNSITEMSNAPPEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemSnappedOut,
    [STRINGID_PKMNSITEMCUREDPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemCuredProblem,
    [STRINGID_PKMNSITEMRESTOREDHEALTH - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHealth,
    [STRINGID_PKMNSITEMRESTOREDPP - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredPP,
    [STRINGID_PKMNSITEMRESTOREDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredStatus,
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemRestoredHPALittle,
    [STRINGID_ITEMALLOWSONLYYMOVE - BATTLESTRINGS_TABLE_START] = sText_ItemAllowsOnlyYMove,
    [STRINGID_PKMNHUNGONWITHX - BATTLESTRINGS_TABLE_START] = sText_PkmnHungOnWithX,
    [STRINGID_EMPTYSTRING3 - BATTLESTRINGS_TABLE_START] = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsBurns,
    [STRINGID_PKMNSXBLOCKSY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY,
    [STRINGID_PKMNSXRESTOREDHPALITTLE2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXRestoredHPALittle2,
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWhippedUpSandstorm,
    [STRINGID_PKMNSXPREVENTSYLOSS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYLoss,
    [STRINGID_PKMNSXINFATUATEDY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXInfatuatedY,
    [STRINGID_PKMNSXMADEYINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYIneffective,
    [STRINGID_PKMNSXCUREDYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredYProblem,
    [STRINGID_ITSUCKEDLIQUIDOOZE - BATTLESTRINGS_TABLE_START] = sText_ItSuckedLiquidOoze,
    [STRINGID_PKMNTRANSFORMED - BATTLESTRINGS_TABLE_START] = sText_PkmnTransformed,
    [STRINGID_ELECTRICITYWEAKENED - BATTLESTRINGS_TABLE_START] = sText_ElectricityWeakened,
    [STRINGID_FIREWEAKENED - BATTLESTRINGS_TABLE_START] = sText_FireWeakened,
    [STRINGID_PKMNHIDUNDERWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnHidUnderwater,
    [STRINGID_PKMNSPRANGUP - BATTLESTRINGS_TABLE_START] = sText_PkmnSprangUp,
    [STRINGID_HMMOVESCANTBEFORGOTTEN - BATTLESTRINGS_TABLE_START] = sText_HMMovesCantBeForgotten,
    [STRINGID_XFOUNDONEY - BATTLESTRINGS_TABLE_START] = sText_XFoundOneY,
    [STRINGID_PLAYERDEFEATEDTRAINER1 - BATTLESTRINGS_TABLE_START] = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA - BATTLESTRINGS_TABLE_START] = sText_SoothingAroma,
    [STRINGID_ITEMSCANTBEUSEDNOW - BATTLESTRINGS_TABLE_START] = sText_ItemsCantBeUsedNow,
    [STRINGID_FORXCOMMAYZ - BATTLESTRINGS_TABLE_START] = sText_ForXCommaYZ,
    [STRINGID_USINGITEMSTATOFPKMNROSE - BATTLESTRINGS_TABLE_START] = sText_UsingItemTheStatOfPkmnRose,
    [STRINGID_PKMNUSEDXTOGETPUMPED - BATTLESTRINGS_TABLE_START] = sText_PkmnUsedXToGetPumped,
    [STRINGID_PKMNSXMADEYUSELESS - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeYUseless,
    [STRINGID_PKMNTRAPPEDBYSANDTOMB - BATTLESTRINGS_TABLE_START] = sText_PkmnTrappedBySandTomb,
    [STRINGID_EMPTYSTRING4 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ABOOSTED - BATTLESTRINGS_TABLE_START] = sText_ABoosted,
    [STRINGID_PKMNSXINTENSIFIEDSUN - BATTLESTRINGS_TABLE_START] = sText_PkmnsXIntensifiedSun,
    [STRINGID_PKMNMAKESGROUNDMISS - BATTLESTRINGS_TABLE_START] = sText_PkmnMakesGroundMiss,
    [STRINGID_YOUTHROWABALLNOWRIGHT - BATTLESTRINGS_TABLE_START] = sText_YouThrowABallNowRight,
    [STRINGID_PKMNSXTOOKATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnsXTookAttack,
    [STRINGID_PKMNCHOSEXASDESTINY - BATTLESTRINGS_TABLE_START] = sText_PkmnChoseXAsDestiny,
    [STRINGID_PKMNLOSTFOCUS - BATTLESTRINGS_TABLE_START] = sText_PkmnLostFocus,
    [STRINGID_USENEXTPKMN - BATTLESTRINGS_TABLE_START] = sText_UseNextPkmn,
    [STRINGID_PKMNFLEDUSINGITS - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsingIts,
    [STRINGID_PKMNFLEDUSING - BATTLESTRINGS_TABLE_START] = sText_PkmnFledUsing,
    [STRINGID_PKMNWASDRAGGEDOUT - BATTLESTRINGS_TABLE_START] = sText_PkmnWasDraggedOut,
    [STRINGID_PREVENTEDFROMWORKING - BATTLESTRINGS_TABLE_START] = sText_PreventedFromWorking,
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemNormalizedStatus,
    [STRINGID_TRAINER1USEDITEM - BATTLESTRINGS_TABLE_START] = sText_Trainer1UsedItem,
    [STRINGID_BOXISFULL - BATTLESTRINGS_TABLE_START] = sText_BoxIsFull,
    [STRINGID_PKMNAVOIDEDATTACK - BATTLESTRINGS_TABLE_START] = sText_PkmnAvoidedAttack,
    [STRINGID_PKMNSXMADEITINEFFECTIVE - BATTLESTRINGS_TABLE_START] = sText_PkmnsXMadeItIneffective,
    [STRINGID_PKMNSXPREVENTSFLINCHING - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsFlinching,
    [STRINGID_PKMNALREADYHASBURN - BATTLESTRINGS_TABLE_START] = sText_PkmnAlreadyHasBurn,
    [STRINGID_STATSWONTDECREASE2 - BATTLESTRINGS_TABLE_START] = sText_StatsWontDecrease2,
    [STRINGID_PKMNSXBLOCKSY2 - BATTLESTRINGS_TABLE_START] = sText_PkmnsXBlocksY2,
    [STRINGID_PKMNSXWOREOFF - BATTLESTRINGS_TABLE_START] = sText_PkmnsXWoreOff,
    [STRINGID_PKMNRAISEDDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedDefALittle,
    [STRINGID_PKMNRAISEDSPDEFALITTLE - BATTLESTRINGS_TABLE_START] = sText_PkmnRaisedSpDefALittle,
    [STRINGID_THEWALLSHATTERED - BATTLESTRINGS_TABLE_START] = sText_TheWallShattered,
    [STRINGID_PKMNSXPREVENTSYSZ - BATTLESTRINGS_TABLE_START] = sText_PkmnsXPreventsYsZ,
    [STRINGID_PKMNSXCUREDITSYPROBLEM - BATTLESTRINGS_TABLE_START] = sText_PkmnsXCuredItsYProblem,
    [STRINGID_ATTACKERCANTESCAPE - BATTLESTRINGS_TABLE_START] = sText_AttackerCantEscape,
    [STRINGID_PKMNOBTAINEDX - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX,
    [STRINGID_PKMNOBTAINEDX2 - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedX2,
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ - BATTLESTRINGS_TABLE_START] = sText_PkmnObtainedXYObtainedZ,
    [STRINGID_BUTNOEFFECT - BATTLESTRINGS_TABLE_START] = sText_ButNoEffect,
    [STRINGID_PKMNSXHADNOEFFECTONY - BATTLESTRINGS_TABLE_START] = sText_PkmnsXHadNoEffectOnY,
    [STRINGID_TWOENEMIESDEFEATED - BATTLESTRINGS_TABLE_START] = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2LoseText,
    [STRINGID_PKMNINCAPABLEOFPOWER - BATTLESTRINGS_TABLE_START] = sText_PkmnIncapableOfPower,
    [STRINGID_GLINTAPPEARSINEYE - BATTLESTRINGS_TABLE_START] = sText_GlintAppearsInEye,
    [STRINGID_PKMNGETTINGINTOPOSITION - BATTLESTRINGS_TABLE_START] = sText_PkmnGettingIntoPosition,
    [STRINGID_PKMNBEGANGROWLINGDEEPLY - BATTLESTRINGS_TABLE_START] = sText_PkmnBeganGrowlingDeeply,
    [STRINGID_PKMNEAGERFORMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnEagerForMore,
    [STRINGID_DEFEATEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_DefeatedOpponentByReferee,
    [STRINGID_LOSTTOOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_LostToOpponentByReferee,
    [STRINGID_TIEDOPPONENTBYREFEREE - BATTLESTRINGS_TABLE_START] = sText_TiedOpponentByReferee,
    [STRINGID_QUESTIONFORFEITMATCH - BATTLESTRINGS_TABLE_START] = sText_QuestionForfeitMatch,
    [STRINGID_FORFEITEDMATCH - BATTLESTRINGS_TABLE_START] = sText_ForfeitedMatch,
    [STRINGID_PKMNTRANSFERREDSOMEONESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL - BATTLESTRINGS_TABLE_START] = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer1WinText,
    [STRINGID_TRAINER2WINTEXT - BATTLESTRINGS_TABLE_START] = sText_Trainer2WinText,
    [STRINGID_ENDUREDSTURDY - BATTLESTRINGS_TABLE_START] = sText_EnduredViaSturdy,
    [STRINGID_POWERHERB - BATTLESTRINGS_TABLE_START] = sText_PowerHerbActivation,
    [STRINGID_HURTBYITEM - BATTLESTRINGS_TABLE_START] = sText_HurtByItem,
    [STRINGID_PSNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BadlyPoisonedByItem,
    [STRINGID_BRNBYITEM - BATTLESTRINGS_TABLE_START] = sText_BurnedByItem,
    [STRINGID_DEFABILITYIN - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityActivates,
    [STRINGID_GRAVITYINTENSIFIED - BATTLESTRINGS_TABLE_START] = sText_GravityIntensified,
    [STRINGID_TARGETIDENTIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetIdentified,
    [STRINGID_TARGETWOKEUP - BATTLESTRINGS_TABLE_START] = sText_TargetWokeUp,
    [STRINGID_PKMNSTOLEANDATEITEM - BATTLESTRINGS_TABLE_START] = sText_PkmnStoleAndAteItem,
    [STRINGID_TAILWINDBLEW - BATTLESTRINGS_TABLE_START] = sText_TailWindBlew,
    [STRINGID_PKMNWENTBACK - BATTLESTRINGS_TABLE_START] = sText_PkmnWentBack,
    [STRINGID_PKMNCANTUSEITEMSANYMORE - BATTLESTRINGS_TABLE_START] = sText_PkmnCantUseItemsAnymore,
    [STRINGID_PKMNFLUNG - BATTLESTRINGS_TABLE_START] = sText_PkmnFlung,
    [STRINGID_PKMNPREVENTEDFROMHEALING - BATTLESTRINGS_TABLE_START] = sText_PkmnPreventedFromHealing,
    [STRINGID_PKMNSWITCHEDATKANDDEF - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedAtkAndDef,
    [STRINGID_PKMNSABILITYSUPPRESSED - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilitySuppressed,
    [STRINGID_SHIELDEDFROMCRITICALHITS - BATTLESTRINGS_TABLE_START] = sText_ShieldedFromCriticalHits,
    [STRINGID_SWITCHEDATKANDSPATK - BATTLESTRINGS_TABLE_START] = sText_SwitchedAtkAndSpAtk,
    [STRINGID_SWITCHEDDEFANDSPDEF - BATTLESTRINGS_TABLE_START] = sText_SwitchedDefAndSpDef,
    [STRINGID_PKMNACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredAbility,
    [STRINGID_POISONSPIKESSCATTERED - BATTLESTRINGS_TABLE_START] = sText_PoisonSpikesScattered,
    [STRINGID_PKMNSWITCHEDSTATCHANGES - BATTLESTRINGS_TABLE_START] = sText_PkmnSwitchedStatChanges,
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER - BATTLESTRINGS_TABLE_START] = sText_PkmnSurroundedWithVeilOfWater,
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_PkmnLevitatedOnElectromagnetism,
    [STRINGID_PKMNTWISTEDDIMENSIONS - BATTLESTRINGS_TABLE_START] = sText_PkmnTwistedDimensions,
    [STRINGID_POINTEDSTONESFLOAT - BATTLESTRINGS_TABLE_START] = sText_PointedStonesFloat,
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT - BATTLESTRINGS_TABLE_START] = sText_CloakedInMysticalMoonlight,
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA - BATTLESTRINGS_TABLE_START] = sText_TrappedBySwirlingMagma,
    [STRINGID_VANISHEDINSTANTLY - BATTLESTRINGS_TABLE_START] = sText_VanishedInstantly,
    [STRINGID_PROTECTEDTEAM - BATTLESTRINGS_TABLE_START] = sText_ProtectedTeam,
    [STRINGID_SHAREDITSGUARD - BATTLESTRINGS_TABLE_START] = sText_SharedItsGuard,
    [STRINGID_SHAREDITSPOWER - BATTLESTRINGS_TABLE_START] = sText_SharedItsPower,
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON - BATTLESTRINGS_TABLE_START] = sText_SwapsDefAndSpDefOfAllPkmn,
    [STRINGID_BECAMENIMBLE - BATTLESTRINGS_TABLE_START] = sText_BecameNimble,
    [STRINGID_HURLEDINTOTHEAIR - BATTLESTRINGS_TABLE_START] = sText_HurledIntoTheAir,
    [STRINGID_HELDITEMSLOSEEFFECTS - BATTLESTRINGS_TABLE_START] = sText_HeldItemsLoseEffects,
    [STRINGID_FELLSTRAIGHTDOWN - BATTLESTRINGS_TABLE_START] = sText_FellStraightDown,
    [STRINGID_TARGETCHANGEDTYPE  - BATTLESTRINGS_TABLE_START] = sText_TargetChangedType,
    [STRINGID_PKMNACQUIREDSIMPLE - BATTLESTRINGS_TABLE_START] = sText_PkmnAcquiredSimple,
    [STRINGID_EMPTYSTRING5 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_KINDOFFER - BATTLESTRINGS_TABLE_START] = sText_KindOffer,
    [STRINGID_RESETSTARGETSSTATLEVELS - BATTLESTRINGS_TABLE_START] = sText_ResetsTargetsStatLevels,
    [STRINGID_EMPTYSTRING6 - BATTLESTRINGS_TABLE_START] = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION - BATTLESTRINGS_TABLE_START] = sText_AllySwitchPosition,
    [STRINGID_RESTORETARGETSHEALTH - BATTLESTRINGS_TABLE_START] = sText_RestoreTargetsHealth,
    [STRINGID_TOOKPJMNINTOTHESKY - BATTLESTRINGS_TABLE_START] = sText_TookPkmnIntoTheSky,
    [STRINGID_FREEDFROMSKYDROP - BATTLESTRINGS_TABLE_START] = sText_FreedFromSkyDrop,
    [STRINGID_POSTPONETARGETMOVE - BATTLESTRINGS_TABLE_START] = sText_PostponeTargetMove,
    [STRINGID_REFLECTTARGETSTYPE - BATTLESTRINGS_TABLE_START] = sText_ReflectTargetsType,
    [STRINGID_TRANSFERHELDITEM - BATTLESTRINGS_TABLE_START] = sText_TransferHeldItem,
    [STRINGID_EMBARGOENDS - BATTLESTRINGS_TABLE_START] = sText_EmbargoEnds,
    [STRINGID_ELECTROMAGNETISM - BATTLESTRINGS_TABLE_START] = sText_Electromagnetism,
    [STRINGID_BUFFERENDS - BATTLESTRINGS_TABLE_START] = sText_BufferEnds,
    [STRINGID_TELEKINESISENDS - BATTLESTRINGS_TABLE_START] = sText_TelekinesisEnds,
    [STRINGID_TAILWINDENDS - BATTLESTRINGS_TABLE_START] = sText_TailwindEnds,
    [STRINGID_LUCKYCHANTENDS - BATTLESTRINGS_TABLE_START] = sText_LuckyChantEnds,
    [STRINGID_TRICKROOMENDS - BATTLESTRINGS_TABLE_START] = sText_TrickRoomEnds,
    [STRINGID_WONDERROOMENDS - BATTLESTRINGS_TABLE_START] = sText_WonderRoomEnds,
    [STRINGID_MAGICROOMENDS - BATTLESTRINGS_TABLE_START] = sText_MagicRoomEnds,
    [STRINGID_MUDSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_MudSportEnds,
    [STRINGID_WATERSPORTENDS - BATTLESTRINGS_TABLE_START] = sText_WaterSportEnds,
    [STRINGID_GRAVITYENDS - BATTLESTRINGS_TABLE_START] = sText_GravityEnds,
    [STRINGID_AQUARINGHEAL - BATTLESTRINGS_TABLE_START] = sText_AquaRingHeal,
    [STRINGID_AURORAVEILENDS - BATTLESTRINGS_TABLE_START] = sText_AuroraVeilEnds,
    [STRINGID_ELECTRICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainEnds,
    [STRINGID_MISTYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainEnds,
    [STRINGID_PSYCHICTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainEnds,
    [STRINGID_GRASSYTERRAINENDS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainEnds,
    [STRINGID_TARGETABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityRaisedStat,
    [STRINGID_TARGETSSTATWASMAXEDOUT - BATTLESTRINGS_TABLE_START] = sText_TargetsStatWasMaxedOut,
    [STRINGID_ATTACKERABILITYSTATRAISE - BATTLESTRINGS_TABLE_START] = sText_AttackerAbilityRaisedStat,
    [STRINGID_POISONHEALHPUP - BATTLESTRINGS_TABLE_START] = sText_PoisonHealHpUp,
    [STRINGID_BADDREAMSDMG - BATTLESTRINGS_TABLE_START] = sText_BadDreamsDmg,
    [STRINGID_MOLDBREAKERENTERS - BATTLESTRINGS_TABLE_START] = sText_MoldBreakerEnters,
    [STRINGID_TERAVOLTENTERS - BATTLESTRINGS_TABLE_START] = sText_TeravoltEnters,
    [STRINGID_TURBOBLAZEENTERS - BATTLESTRINGS_TABLE_START] = sText_TurboblazeEnters,
    [STRINGID_SLOWSTARTENTERS - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnters,
    [STRINGID_SLOWSTARTEND - BATTLESTRINGS_TABLE_START] = sText_SlowStartEnd,
    [STRINGID_SOLARPOWERHPDROP - BATTLESTRINGS_TABLE_START] = sText_SolarPowerHpDrop,
    [STRINGID_AFTERMATHDMG - BATTLESTRINGS_TABLE_START] = sText_AftermathDmg,
    [STRINGID_ANTICIPATIONACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AnticipationActivates,
    [STRINGID_FOREWARNACTIVATES - BATTLESTRINGS_TABLE_START] = sText_ForewarnActivates,
    [STRINGID_ICEBODYHPGAIN - BATTLESTRINGS_TABLE_START] = sText_IceBodyHpGain,
    [STRINGID_SNOWWARNINGHAIL - BATTLESTRINGS_TABLE_START] = sText_SnowWarningHail,
    [STRINGID_SNOWWARNINGSNOW - BATTLESTRINGS_TABLE_START] = sText_SnowWarningSnow,
    [STRINGID_FRISKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_FriskActivates,
    [STRINGID_UNNERVEENTERS - BATTLESTRINGS_TABLE_START] = sText_UnnerveEnters,
    [STRINGID_HARVESTBERRY - BATTLESTRINGS_TABLE_START] = sText_HarvestBerry,
    [STRINGID_LASTABILITYRAISEDSTAT - BATTLESTRINGS_TABLE_START] = sText_LastAbilityRaisedBuff1,
    [STRINGID_MAGICBOUNCEACTIVATES - BATTLESTRINGS_TABLE_START] = sText_MagicBounceActivates,
    [STRINGID_PROTEANTYPECHANGE - BATTLESTRINGS_TABLE_START] = sText_ProteanTypeChange,
    [STRINGID_SYMBIOSISITEMPASS - BATTLESTRINGS_TABLE_START] = sText_SymbiosisItemPass,
    [STRINGID_STEALTHROCKDMG - BATTLESTRINGS_TABLE_START] = sText_StealthRockDmg,
    [STRINGID_TOXICSPIKESABSORBED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesAbsorbed,
    [STRINGID_TOXICSPIKESPOISONED - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesPoisoned,
    [STRINGID_STICKYWEBSWITCHIN - BATTLESTRINGS_TABLE_START] = sText_StickyWebSwitchIn,
    [STRINGID_HEALINGWISHCAMETRUE - BATTLESTRINGS_TABLE_START] = sText_HealingWishCameTrue,
    [STRINGID_HEALINGWISHHEALED - BATTLESTRINGS_TABLE_START] = sText_HealingWishHealed,
    [STRINGID_LUNARDANCECAMETRUE - BATTLESTRINGS_TABLE_START] = sText_LunarDanceCameTrue,
    [STRINGID_CUSEDBODYDISABLED - BATTLESTRINGS_TABLE_START] = sText_CursedBodyDisabled,
    [STRINGID_ATTACKERACQUIREDABILITY - BATTLESTRINGS_TABLE_START] = sText_AttackerAquiredAbility,
    [STRINGID_TARGETABILITYSTATLOWER - BATTLESTRINGS_TABLE_START] = sText_TargetAbilityLoweredStat,
    [STRINGID_TARGETSTATWONTGOHIGHER - BATTLESTRINGS_TABLE_START] = sText_TargetStatWontGoHigher,
    [STRINGID_PKMNMOVEBOUNCEDABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnMoveBouncedViaAbility,
    [STRINGID_IMPOSTERTRANSFORM - BATTLESTRINGS_TABLE_START] = sText_ImposterTransform,
    [STRINGID_ASSAULTVESTDOESNTALLOW - BATTLESTRINGS_TABLE_START] = sText_AssaultVestDoesntAllow,
    [STRINGID_GRAVITYPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_GravityPreventsUsage,
    [STRINGID_HEALBLOCKPREVENTSUSAGE - BATTLESTRINGS_TABLE_START] = sText_HealBlockPreventsUsage,
    [STRINGID_NOTDONEYET - BATTLESTRINGS_TABLE_START] = sText_NotDoneYet,
    [STRINGID_STICKYWEBUSED - BATTLESTRINGS_TABLE_START] = sText_StickyWebUsed,
    [STRINGID_QUASHSUCCESS - BATTLESTRINGS_TABLE_START] = sText_QuashSuccess,
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayToxicSpikes,
    [STRINGID_PKMNBLEWAWAYSTICKYWEB - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStickyWeb,
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK - BATTLESTRINGS_TABLE_START] = sText_PkmnBlewAwayStealthRock,
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_SpikesDisappearedFromTeam,
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_ToxicSpikesDisappearedFromTeam,
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_StealthRockDisappearedFromTeam,
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_StickyWebDisappearedFromTeam,
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM - BATTLESTRINGS_TABLE_START] = sText_SharpSteelDisappearedFromTeam,
    [STRINGID_IONDELUGEON - BATTLESTRINGS_TABLE_START] = sText_IonDelugeOn,
    [STRINGID_TOPSYTURVYSWITCHEDSTATS - BATTLESTRINGS_TABLE_START] = sText_TopsyTurvySwitchedStats,
    [STRINGID_TERRAINBECOMESMISTY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesMisty,
    [STRINGID_TERRAINBECOMESGRASSY - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesGrassy,
    [STRINGID_TERRAINBECOMESELECTRIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesElectric,
    [STRINGID_TERRAINBECOMESPSYCHIC - BATTLESTRINGS_TABLE_START] = sText_TerrainBecomesPsychic,
    [STRINGID_TARGETELECTRIFIED - BATTLESTRINGS_TABLE_START] = sText_TargetElectrified,
    [STRINGID_MEGAEVOREACTING - BATTLESTRINGS_TABLE_START] = sText_MegaEvoReacting,
    [STRINGID_FERVENTWISHREACHED - BATTLESTRINGS_TABLE_START] = sText_FerventWishReached,
    [STRINGID_MEGAEVOEVOLVED - BATTLESTRINGS_TABLE_START] = sText_MegaEvoEvolved,
    [STRINGID_DRASTICALLY - BATTLESTRINGS_TABLE_START] = sText_drastically,
    [STRINGID_SEVERELY - BATTLESTRINGS_TABLE_START] = sText_severely,
    [STRINGID_INFESTATION - BATTLESTRINGS_TABLE_START] = sText_Infestation,
    [STRINGID_NOEFFECTONTARGET - BATTLESTRINGS_TABLE_START] = sText_NoEffectOnTarget,
    [STRINGID_BURSTINGFLAMESHIT - BATTLESTRINGS_TABLE_START] = sText_BurstingFlames,
    [STRINGID_BESTOWITEMGIVING - BATTLESTRINGS_TABLE_START] = sText_BestowItemGiving,
    [STRINGID_THIRDTYPEADDED - BATTLESTRINGS_TABLE_START] = sText_ThirdTypeAdded,
    [STRINGID_FELLFORFEINT - BATTLESTRINGS_TABLE_START] = sText_FellForFeint,
    [STRINGID_POKEMONCANNOTUSEMOVE - BATTLESTRINGS_TABLE_START] = sText_PokemonCannotUseMove,
    [STRINGID_COVEREDINPOWDER - BATTLESTRINGS_TABLE_START] = sText_CoveredInPowder,
    [STRINGID_POWDEREXPLODES - BATTLESTRINGS_TABLE_START] = sText_PowderExplodes,
    [STRINGID_GRAVITYGROUNDING - BATTLESTRINGS_TABLE_START] = sText_GravityGrounding,
    [STRINGID_MISTYTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_MistyTerrainPreventsStatus,
    [STRINGID_GRASSYTERRAINHEALS - BATTLESTRINGS_TABLE_START] = sText_GrassyTerrainHeals,
    [STRINGID_ELECTRICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_ElectricTerrainPreventsSleep,
    [STRINGID_PSYCHICTERRAINPREVENTS - BATTLESTRINGS_TABLE_START] = sText_PsychicTerrainPreventsPriority,
    [STRINGID_AURAFLAREDTOLIFE - BATTLESTRINGS_TABLE_START] = sText_AuraFlaredToLife,
    [STRINGID_AIRLOCKACTIVATES - BATTLESTRINGS_TABLE_START] = sText_AirLockActivates,
    [STRINGID_PRESSUREENTERS - BATTLESTRINGS_TABLE_START] = sText_PressureActivates,
    [STRINGID_DARKAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_DarkAuraActivates,
    [STRINGID_FAIRYAURAENTERS - BATTLESTRINGS_TABLE_START] = sText_FairyAuraActivates,
    [STRINGID_AURABREAKENTERS - BATTLESTRINGS_TABLE_START] = sText_AuraBreakActivates,
    [STRINGID_COMATOSEENTERS - BATTLESTRINGS_TABLE_START] = sText_ComatoseActivates,
    [STRINGID_SCREENCLEANERENTERS - BATTLESTRINGS_TABLE_START] = sText_ScreenCleanerActivates,
    [STRINGID_BOTHCANNOLONGERESCAPE - BATTLESTRINGS_TABLE_START] = sText_BothCanNoLongerEscape,
    [STRINGID_CANTESCAPEDUETOUSEDMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeDueToUsedMove,
    [STRINGID_PKMNBECAMEWEAKERTOFIRE - BATTLESTRINGS_TABLE_START] = sText_PkmnBecameWeakerToFire,
    [STRINGID_ABOUTTOUSEPOLTERGEIST - BATTLESTRINGS_TABLE_START] = sText_PkmnAboutToBeAttackedByItsItem,
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE - BATTLESTRINGS_TABLE_START] = sText_CantEscapeBecauseOfCurrentMove,
    [STRINGID_PKMNTOOKTARGETHIGH - BATTLESTRINGS_TABLE_START] = sText_PkmnTookTargetHigh,
    [STRINGID_TARGETTOOHEAVY - BATTLESTRINGS_TABLE_START] = sText_TargetTooHeavy,
    [STRINGID_ATTACKERLOSTELECTRICTYPE - BATTLESTRINGS_TABLE_START] = sText_AttackerLostElectricType,
    [STRINGID_PKMNSABILITYPREVENTSABILITY - BATTLESTRINGS_TABLE_START] = sText_PkmnsAbilityPreventsAbility,
    [STRINGID_PKMNHURTBYFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnHurtByFrostbite,
    [STRINGID_PKMNGOTFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnGotFrostbite,
    [STRINGID_PKMNSITEMHEALEDFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_PkmnsItemHealedFrostbite,
    [STRINGID_ATTACKERHEALEDITSFROSTBITE - BATTLESTRINGS_TABLE_START] = sText_AttackerHealedItsFrostbite,
    [STRINGID_PKMNFROSTBITEHEALED - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealed,
    [STRINGID_PKMNFROSTBITEHEALED2 - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealed2,
    [STRINGID_PKMNFROSTBITEHEALEDBY - BATTLESTRINGS_TABLE_START] = sText_PkmnFrostbiteHealedBy,
    [STRINGID_ULTRABURSTREACTING - BATTLESTRINGS_TABLE_START] = sText_UltraBurstReacting,
    [STRINGID_ULTRABURSTCOMPLETED - BATTLESTRINGS_TABLE_START] = sText_UltraBurstCompleted,
    [STRINGID_TEAMGAINEDEXP - BATTLESTRINGS_TABLE_START] = sText_TeamGainedEXP,
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP - BATTLESTRINGS_TABLE_START] = sText_TargetCoveredInStickyCandySyrup,
    [STRINGID_PKMNISANGRY - BATTLESTRINGS_TABLE_START] = sText_PkmnIsAngry,
    [STRINGID_PKMNISCALM - BATTLESTRINGS_TABLE_START] = sText_PkmnIsCalm,
    [STRINGID_COMMANDERACTIVATES - BATTLESTRINGS_TABLE_START] = sText_CommanderActivates,
    
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gMagicCoatBounceStringIds[] =
{
    STRINGID_PKMNMOVEBOUNCED, STRINGID_PKMNMOVEBOUNCEDABILITY
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE, STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN] = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_SUN] = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_HAIL] = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_STRONG_WINDS] = STRINGID_STRONGWINDSDISSIPATED,
    [B_MSG_WEATHER_END_SNOW] = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG] = STRINGID_SNOWSTOPPED,
};

const u16 gSandStormHailSnowContinuesStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMRAGES,
    [B_MSG_HAIL]      = STRINGID_HAILCONTINUES,
    [B_MSG_SNOW]      = STRINGID_SNOWCONTINUES,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gSandStormHailSnowEndStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_HAIL]      = STRINGID_HAILSTOPPED,
    [B_MSG_SNOW]      = STRINGID_SNOWSTOPPED,
};

const u16 gRainContinuesStringIds[] =
{
    [B_MSG_RAIN_CONTINUES]     = STRINGID_RAINCONTINUES,
    [B_MSG_DOWNPOUR_CONTINUES] = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_RAIN_STOPPED]       = STRINGID_RAINSTOPPED
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEFALITTLE,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEFALITTLE,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gStockpileUsedStringIds[] =
{
    [B_MSG_STOCKPILED]     = STRINGID_PKMNSTOCKPILED,
    [B_MSG_CANT_STOCKPILE] = STRINGID_PKMNCANTSTOCKPILE,
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gSwallowFailStringIds[] =
{
    [B_MSG_SWALLOW_FAILED]  = STRINGID_FAILEDTOSWALLOW,
    [B_MSG_SWALLOW_FULL_HP] = STRINGID_PKMNHPFULL
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_ROSE] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_ROSE] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_INCREASE] = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_ROSE_EMPTY]    = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_ROSE_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]      = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_FELL] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_FELL] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_DECREASE] = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_FELL_EMPTY]    = STRINGID_EMPTYSTRING3,
};

// Index read from sTWOTURN_STRINGID
const u16 gFirstTurnOfTwoStringIds[] =
{
    [B_MSG_TURN1_RAZOR_WIND]    = STRINGID_PKMNWHIPPEDWHIRLWIND,
    [B_MSG_TURN1_SOLAR_BEAM]    = STRINGID_PKMNTOOKSUNLIGHT,
    [B_MSG_TURN1_SKULL_BASH]    = STRINGID_PKMNLOWEREDHEAD,
    [B_MSG_TURN1_SKY_ATTACK]    = STRINGID_PKMNISGLOWING,
    [B_MSG_TURN1_FLY]           = STRINGID_PKMNFLEWHIGH,
    [B_MSG_TURN1_DIG]           = STRINGID_PKMNDUGHOLE,
    [B_MSG_TURN1_DIVE]          = STRINGID_PKMNHIDUNDERWATER,
    [B_MSG_TURN1_BOUNCE]        = STRINGID_PKMNSPRANGUP,
    [B_MSG_TURN1_PHANTOM_FORCE] = STRINGID_VANISHEDINSTANTLY,
    [B_MSG_TURN1_GEOMANCY]      = STRINGID_PKNMABSORBINGPOWER,
    [B_MSG_TURN1_FREEZE_SHOCK]  = STRINGID_CLOAKEDINAFREEZINGLIGHT,
    [B_MSG_TURN1_SKY_DROP]      = STRINGID_PKMNTOOKTARGETHIGH,
    [B_MSG_TURN1_METEOR_BEAM]   = STRINGID_METEORBEAMCHARGING,
    [B_MSG_TURN1_ELECTRO_SHOT]  = STRINGID_ELECTROSHOTCHARGING,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED2,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = STRINGID_STARTEDSNOW,
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_ITISRAINING,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTSTRONG,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING,
    [WEATHER_LEAVES]             = STRINGID_ITISRAINING
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 gBerryEffectStringIds[] =
{
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gBRNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNSXPREVENTSBURNS,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPRLZPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPARALYSISWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gPSNPreventionStringIds[] =
{
    [B_MSG_ABILITY_PREVENTS_MOVE_STATUS]    = STRINGID_PKMNPREVENTSPOISONINGWITH,
    [B_MSG_ABILITY_PREVENTS_ABILITY_STATUS] = STRINGID_PKMNSXPREVENTSYSZ,
    [B_MSG_STATUS_HAD_NO_EFFECT]            = STRINGID_PKMNSXHADNOEFFECTONY
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]  = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]  = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL] = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL] = STRINGID_PKMNBOXLANETTESPCFULL,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gStatus2StringIds[] =
{
    STRINGID_PKMNWASCONFUSED, STRINGID_PKMNFELLINLOVE, STRINGID_TARGETCANTESCAPENOW, STRINGID_PKMNSUBJECTEDTOTORMENT
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u8 gText_PkmnIsEvolving[] = _("¿Qué?\n¡{STR_VAR_1} está evolucionando!");
const u8 gText_CongratsPkmnEvolved[] = _("¡Enhorabuena! ¡Tu {STR_VAR_1}\nha evolucionado a {STR_VAR_2}!\p");
const u8 gText_PkmnStoppedEvolving[] = _("¿Eh? ¡{STR_VAR_1}\nha dejado de evolucionar!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("{FONT_NARROW}¿Qué hará {B_BUFF1}?\n{FONT_SMALL_NARROW}{SELECT_BUTTON} Info {PKMN}");
const u8 gText_WhatWillPkmnDo2[] = _("¿Qué hará\n{B_PLAYER_NAME}?");
const u8 gText_WhatWillWallyDo[] = _("¿Qué hará\nBLASCO?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Esperando conexión…");
const u8 gText_BattleMenu[] = _("Luchar{CLEAR_TO 56}Mochila\nPokémon{CLEAR_TO 56}Huir {B_BUTTON}");
const u8 gText_TrainerBattleMenu[] = _("Luchar{CLEAR_TO 56}Mochila\nPokémon{CLEAR_TO 56}{FONT_NARROW}Rendirse");
const u8 gText_SafariZoneMenu[] = _("Capturar{CLEAR_TO 56}{FONT_SMALL_NARROW}Otra Ball\n{CLEAR_TO 56}{FONT_NORMAL}Huir {B_BUTTON}");
const u8 gText_SafariZoneMenuNoBallSwap[] = _("Capturar{CLEAR_TO 56}{FONT_SMALL_NARROW}{COLOR DYNAMIC_COLOR6}{SHADOW DYNAMIC_COLOR5}Otra Ball\n{CLEAR_TO 56}{FONT_NORMAL}{COLOR DYNAMIC_COLOR4}{SHADOW DYNAMIC_COLOR6}Huir {B_BUTTON}");
const u8 gText_MoveInterfacePP[] = _("PP ");
const u8 gText_MoveInterfaceType[] = _("TIPO/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}PP\nTIPO/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}¿Qué movimiento\ndebe olvidar?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Sí\nNo");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}¿Cambiar\ncuál?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");

// Unused
static const u8 *const sStatNamesTable2[] =
{
    gText_HP3, gText_SpAtk, gText_Attack,
    gText_SpDef, gText_Defense, gText_Speed
};

const u8 gText_SafariBalls[] = _("{HIGHLIGHT LIGHT_RED}");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT LIGHT_RED}Quedan: $" "{HIGHLIGHT LIGHT_RED}");
const u8 gText_Sleep[] = _("sueño");
const u8 gText_Poison[] = _("veneno");
const u8 gText_Burn[] = _("quemadura");
const u8 gText_Paralysis[] = _("parálisis");
const u8 gText_Ice[] = _("hielo");
const u8 gText_Confusion[] = _("confusión");
const u8 gText_Love[] = _("amor");
const u8 gText_SpaceAndSpace[] = _(" y ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("son");
const u8 gText_Are2[] = _("son");
const u8 gText_BadEgg[] = _("HUEVO malo");
const u8 gText_BattleWallyName[] = _("BLASCO");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Victoria");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Derrota");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Empate");
static const u8 sText_SpaceIs[] = _(" es");
static const u8 sText_ApostropheS[] = _("'s");

// For displaying names of invalid moves.
// This is large enough that the text for TYPE_ELECTRIC will exceed TEXT_BUFF_ARRAY_COUNT.
static const u8 sATypeMove_Table[NUMBER_OF_MON_TYPES][17] =
{
    [TYPE_NORMAL]   = _("a NORMAL move"),
    [TYPE_FIGHTING] = _("a FIGHTING move"),
    [TYPE_FLYING]   = _("a FLYING move"),
    [TYPE_POISON]   = _("a POISON move"),
    [TYPE_GROUND]   = _("a GROUND move"),
    [TYPE_ROCK]     = _("a ROCK move"),
    [TYPE_BUG]      = _("a BUG move"),
    [TYPE_GHOST]    = _("a GHOST move"),
    [TYPE_STEEL]    = _("a STEEL move"),
    [TYPE_MYSTERY]  = _("a ??? move"),
    [TYPE_FIRE]     = _("a FIRE move"),
    [TYPE_WATER]    = _("a WATER move"),
    [TYPE_GRASS]    = _("a GRASS move"),
    [TYPE_ELECTRIC] = _("an ELECTRIC move"),
    [TYPE_PSYCHIC]  = _("a PSYCHIC move"),
    [TYPE_ICE]      = _("an ICE move"),
    [TYPE_DRAGON]   = _("a DRAGON move"),
    [TYPE_DARK]     = _("a DARK move"),
    [TYPE_FAIRY]    = _("a FAIRY move"),
};

const u8 gText_BattleTourney[] = _("TORNEO");
static const u8 sText_Round1[] = _("Ronda 1");
static const u8 sText_Round2[] = _("Ronda 2");
static const u8 sText_Semifinal[] = _("Semifinal");
static const u8 sText_Final[] = _("Final");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = sText_Round1,
    [DOME_ROUND2]    = sText_Round2,
    [DOME_SEMIFINAL] = sText_Semifinal,
    [DOME_FINAL]     = sText_Final
};

const u8 gText_TheGreatNewHope[] = _("¡La gran promesa!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("¿¡Se cumplirá su sueño de ser campeón!?\p");
const u8 gText_AFormerChampion[] = _("¡Un antiguo CAMPEÓN!\p");
const u8 gText_ThePreviousChampion[] = _("¡El anterior CAMPEÓN!\p");
const u8 gText_TheUnbeatenChampion[] = _("¡El CAMPEÓN invicto!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Mente");
const u8 gText_Skill[] = _("Técnica");
const u8 gText_Body[] = _("Cuerpo");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Decisión{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME}\nsaca a {B_OPPONENT_MON1_NAME}!\p¡{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\nsaca a {B_OPPONENT_MON2_NAME}!");
static const u8 sText_Trainer2SentOutPkmn[] = _("¡{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\nsaca a {B_BUFF1}!");
static const u8 sText_TwoTrainersWantToBattle[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} y\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lquieren luchar!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("¡{B_PARTNER_CLASS} {B_PARTNER_NAME}\nsaca a {B_PLAYER_MON2_NAME}!\l¡Adelante, {B_PLAYER_MON1_NAME}!");
static const u8 sText_TwoInGameTrainersDefeated[] = _("¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} y\n{B_TRAINER2_CLASS} {B_TRAINER2_NAME}\lhan sido derrotados!\p");
static const u8 sText_Trainer2LoseText[] = _("{B_TRAINER2_LOSE_TEXT}");
static const u8 sText_PkmnIncapableOfPower[] = _("¡{B_ATK_NAME_WITH_PREFIX} parece incapaz\nde usar su poder!");
static const u8 sText_GlintAppearsInEye[] = _("¡Los ojos de {B_SCR_ACTIVE_NAME_WITH_PREFIX}\nbrillan!");
static const u8 sText_PkmnGettingIntoPosition[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} se está\ncolocando en posición!");
static const u8 sText_PkmnBeganGrowlingDeeply[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} gruñe con fuerza!");
static const u8 sText_PkmnEagerForMore[] = _("¡{B_SCR_ACTIVE_NAME_WITH_PREFIX} quiere más!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

static const u8 sText_RefIfNothingIsDecided[] = _("ÁRBITRO: ¡Si no hay ganador en\n3 turnos, decidirán los jueces!");
static const u8 sText_RefThatsIt[] = _("ÁRBITRO: ¡Se acabó! ¡Los jueces\ndecidirán quién es el ganador!");
static const u8 sText_RefJudgeMind[] = _("ÁRBITRO: ¡Categoría 1, Mente!\n¡El Pokémon con más agallas!\p");
static const u8 sText_RefJudgeSkill[] = _("ÁRBITRO: ¡Categoría 2, Técnica!\n¡El Pokémon que mejor usa sus movs.!\p");
static const u8 sText_RefJudgeBody[] = _("ÁRBITRO: ¡Categoría 3, Cuerpo!\n¡El Pokémon con más vitalidad!\p");
static const u8 sText_RefPlayerWon[] = _("ÁRBITRO: ¡{B_BUFF1} a {B_BUFF2}!\n¡Gana {B_PLAYER_MON1_NAME} de {B_PLAYER_NAME}!\p");
static const u8 sText_RefOpponentWon[] = _("ÁRBITRO: ¡{B_BUFF1} a {B_BUFF2}!\n¡Gana {B_OPPONENT_MON1_NAME} de {B_TRAINER1_NAME}!\p");
static const u8 sText_RefDraw[] = _("ÁRBITRO: ¡Decisión: 3 a 3!\n¡Es un empate!\p");
static const u8 sText_DefeatedOpponentByReferee[] = _("¡{B_PLAYER_MON1_NAME} vence a {B_OPPONENT_MON1_NAME}\npor decisión del ÁRBITRO!");
static const u8 sText_LostToOpponentByReferee[] = _("¡{B_PLAYER_MON1_NAME} pierde contra {B_OPPONENT_MON1_NAME}\npor decisión del ÁRBITRO!");
static const u8 sText_TiedOpponentByReferee[] = _("¡{B_PLAYER_MON1_NAME} empata con {B_OPPONENT_MON1_NAME}\npor decisión del ÁRBITRO!");
static const u8 sText_RefCommenceBattle[] = _("ÁRBITRO: ¡{B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}!\n¡Que empiece el combate!");

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = sText_RefIfNothingIsDecided,
    [B_MSG_REF_THATS_IT]           = sText_RefThatsIt,
    [B_MSG_REF_JUDGE_MIND]         = sText_RefJudgeMind,
    [B_MSG_REF_JUDGE_SKILL]        = sText_RefJudgeSkill,
    [B_MSG_REF_JUDGE_BODY]         = sText_RefJudgeBody,
    [B_MSG_REF_PLAYER_WON]         = sText_RefPlayerWon,
    [B_MSG_REF_OPPONENT_WON]       = sText_RefOpponentWon,
    [B_MSG_REF_DRAW]               = sText_RefDraw,
    [B_MSG_REF_COMMENCE_BATTLE]    = sText_RefCommenceBattle,
};

static const u8 sText_QuestionForfeitMatch[] = _("¿Quieres rendirte en el combate\ny abandonar la aventura?");
static const u8 sText_ForfeitedMatch[] = _("¡{B_PLAYER_NAME} se ha rendido!");
static const u8 sText_Trainer1WinText[] = _("{B_TRAINER1_WIN_TEXT}");
static const u8 sText_Trainer2WinText[] = _("{B_TRAINER2_WIN_TEXT}");
static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}¡{B_TRAINER1_CLASS} {B_TRAINER1_NAME} ha huido!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("¡Has perdido contra\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("¡Has empatado contra\n{B_TRAINER1_CLASS} {B_TRAINER1_NAME}!");
const u8 gText_RecordBattleToPass[] = _("¿Quieres grabar el combate\nen tu PASE del FRENTE?");
const u8 gText_BattleRecordedOnPass[] = _("El resultado del combate de {B_PLAYER_NAME}\nse ha grabado en el PASE del FRENTE.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME}\nquiere luchar!{PAUSE 49}");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("¡{B_LINK_OPPONENT1_NAME} y {B_LINK_OPPONENT2_NAME}\nquieren luchar!{PAUSE 49}");
static const u8 sText_Your1[] = _("aliado");
static const u8 sText_Opposing1[] = _("rival");
static const u8 sText_Your2[] = _("aliado");
static const u8 sText_Opposing2[] = _("rival");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VISE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(u16 stringID, u32 battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                    else
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                }
                else
                {
                    if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)]]))
                stringPtr = sText_TwoWildPkmnAppeared;
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else if (gBattleTypeFlags & BATTLE_TYPE_ALPHA_MON) // not legend but alpha means this is a unique mon
                stringPtr = sText_UniquePkmnAppeared;
            else
                stringPtr = sText_WildPkmnAppeared;
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gPlayerParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE && IsValidForBattle(&gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]]))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (gTrainerBattleOpponent_A == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                stringPtr = sText_Trainer1WithdrewPkmn;
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (GetBattlerSide(gBattleScripting.battler) == B_SIDE_PLAYER)
        {
            if (*(&gBattleStruct->hpScale) == 0 || gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // pokemon used a move msg
        if (gBattleStruct->zmove.active && gBattleStruct->zmove.activeSplit != SPLIT_STATUS)
            StringCopy(gBattleTextBuff3, GetZMoveName(gBattleMsgDataPtr->currentMove));
        else if (IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, GetMaxMoveName(gBattleMsgDataPtr->currentMove));
        else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
            StringCopy(gBattleTextBuff3, sATypeMove_Table[*(&gBattleStruct->stringMoveType)]);
        else
            StringCopy(gBattleTextBuff3, gMoveNames[gBattleMsgDataPtr->currentMove]);

        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (GetBattlerSide(battler) == B_SIDE_OPPONENT && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                case B_OUTCOME_FORFEITED:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (gTrainerBattleOpponent_A == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                case B_OUTCOME_FORFEITED:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= BATTLESTRINGS_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID - BATTLESTRINGS_TABLE_START];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
    return BattleStringExpandPlaceholders(Rogue_ModifyBattleMessage(src), gDisplayedStringBattle);
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(u32 battler, u8 *dst)
{
    struct Pokemon *mon, *illusionMon;

    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        mon = &gPlayerParty[gBattlerPartyIndexes[battler]];
    else
        mon = &gEnemyParty[gBattlerPartyIndexes[battler]];

    illusionMon = GetIllusionMonPtr(battler);
    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

// Translation build: the wild/foe marker goes after the name ("PIKACHU salvaje"),
// so sText_WildPkmnPrefix / sText_FoePkmnPrefix are used as suffixes.
#define HANDLE_NICKNAME_STRING_CASE(battler)                          \
    GetBattlerNick(battler, text);                                    \
    if (GetBattlerSide(battler) != B_SIDE_PLAYER)                     \
    {                                                                   \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            StringAppend(text, sText_FoePkmnPrefix);                    \
        else                                                            \
            StringAppend(text, sText_WildPkmnPrefix);                   \
    }                                                                   \
    toCpy = text;

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        toCpy = Rogue_GetTrainerName(trainerId);
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, battler);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, u8 battler)
{
    if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;
    struct Trainer trainer;

    Rogue_ModifyTrainer(trainerId, &trainer);

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClassNames[GetSecretBaseTrainerClass()];
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClassNames[GetUnionRoomTrainerClass()];
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClassNames[GetFrontierBrainTrainerClass()];
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClassNames[GetFrontierOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClassNames[GetTrainerHillOpponentClass(trainerId)];
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClassNames[GetEreaderTrainerClassId()];
    else
        toCpy = gTrainerClassNames[trainer.trainerClass];

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    // This buffer may hold either the name of a trainer, pokemon, or item.
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 multiplayerId;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    while (*src != EOS)
    {
        toCpy = NULL;
        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                    toCpy = gBattleTextBuff2;
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                    toCpy = gBattleTextBuff3;
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->currentMove);
                else if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->currentMove];
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleStruct->zmove.active)
                    toCpy = GetZMoveName(gBattleMsgDataPtr->originallyUsedMove);
                else if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT)
                    toCpy = sATypeMove_Table[gBattleStruct->stringMoveType];
                else
                    toCpy = gMoveNames[gBattleMsgDataPtr->originallyUsedMove];
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                                toCpy = sText_EnigmaBerry;
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilityNames[gLastUsedAbility];
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerAttacker]];
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattlerTarget]];
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilityNames[sBattlerAbilities[gBattleScripting.battler]];
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilityNames[sBattlerAbilities[gEffectBattler]];
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_A, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_A);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                if (GetBattlerSide(gBattleScripting.battler) != B_SIDE_PLAYER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                    GetMonData(&gEnemyParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(gTrainerBattleOpponent_B, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, gTrainerBattleOpponent_B);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClassNames[GetFrontierOpponentClass(gPartnerTrainerId)];
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_B);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(gTrainerBattleOpponent_A);
                    break;
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (GetBattlerSide(gBattlerAttacker) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    return dstID;
}

static void IllusionNickHack(u32 battler, u32 partyId, u8 *dst)
{
    s32 id, i;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = &gEnemyParty[gBattlerPartyIndexes[BATTLE_PARTNER(battler)]];
        else
            partnerMon = mon;

        // Find last alive non-egg pokemon.
        for (i = PARTY_SIZE - 1; i >= 0; i--)
        {
            id = i;
            if (GetMonData(&gEnemyParty[id], MON_DATA_SANITY_HAS_SPECIES)
                && GetMonData(&gEnemyParty[id], MON_DATA_HP)
                && &gEnemyParty[id] != mon
                && &gEnemyParty[id] != partnerMon)
            {
                GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
                return;
            }
        }
    }

    GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword - BATTLESTRINGS_TABLE_START]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, gMoveNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypeNames[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
            if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                    StringAppend(dst, sText_FoePkmnPrefix);
                else
                    StringAppend(dst, sText_WildPkmnPrefix);

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (GetBattlerSide(src[srcID + 1]) == B_SIDE_PLAYER)
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilityNames[T1_READ_16(&src[srcID + 1])]);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "?" or "?") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void UNUSED ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "? ????!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "??!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "? ??!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " ????!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void UNUSED ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    BattlePutTextOnWindowWithSpeed(text, windowId, TEXT_SKIP_DRAW);
}

void BattlePutTextOnWindowWithSpeed(const u8* text, u8 windowId, u8 textSpeed)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled)
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    if(textSpeed != TEXT_SKIP_DRAW)
    {
        speed = textSpeed;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(u32 battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]], gBattleMoves[gMoveSelectionCursor[battler]].pp);

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}

struct TrainerSlide
{
    u16 trainerId;
    bool8 isFrontierTrainer;
    const u8 *msgLastSwitchIn;
    const u8 *msgLastLowHp;
    const u8 *msgFirstDown;
    const u8 *msgLastHalfHp;
    const u8 *msgFirstCriticalHit;
    const u8 *msgFirstSuperEffectiveHit;
    const u8 *msgFirstSTABMove;
    const u8 *msgPlayerMonUnaffected;
    const u8 *msgMegaEvolution;
    const u8 *msgZMove;
    const u8 *msgBeforeFirstTurn;
    const u8 *msgDynamax;
};

static const struct TrainerSlide sTrainerSlides[] =
{
    /* Put any trainer slide-in messages inside this array.
    Example:
    {
        .trainerId = TRAINER_WALLY_VR_2,
        .isFrontierTrainer = FALSE,
        .msgLastSwitchIn = sText_AarghAlmostHadIt,
        .msgLastLowHp = sText_BoxIsFull,
        .msgFirstDown = sText_123Poof,
        .msgLastHalfHp = sText_ShootSoClose,
        .msgFirstCriticalHit = sText_CriticalHit,
        .msgFirstSuperEffectiveHit = sText_SuperEffective,
        .msgFirstSTABMove = sText_ABoosted,
        .msgPlayerMonUnaffected = sText_ButNoEffect,
        .msgMegaEvolution = sText_PowderExplodes,
        .msgZMove = sText_Electromagnetism,
        .msgBeforeFirstTurn = sText_GravityIntensified,
        .msgDynamax = sText_TargetWokeUp,
    },
    */
};

static u32 GetEnemyMonCount(u32 firstId, u32 lastId, bool32 onlyAlive)
{
    u32 i, count = 0;

    for (i = firstId; i < lastId; i++)
    {
        u32 species = GetMonData(&gEnemyParty[i], MON_DATA_SPECIES_OR_EGG, NULL);
        if (species != SPECIES_NONE
            && species != SPECIES_EGG
            && (!onlyAlive || GetMonData(&gEnemyParty[i], MON_DATA_HP, NULL)))
            count++;
    }

    return count;
}

enum
{
    LESS_THAN,
    EQUAL,
    GREATER_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN_OR_EQUAL,
    NOT_EQUAL,
};

u32 BattlerHPPercentage(u32 battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
    case LESS_THAN:
        return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
    case EQUAL:
        return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN:
        return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
    case LESS_THAN_OR_EQUAL:
        return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
    case GREATER_THAN_OR_EQUAL:
        return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
    case NOT_EQUAL:
    default:
        return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

u32 ShouldDoTrainerSlide(u32 battler, u32 which)
{
    u32 i, firstId, lastId, trainerId, retValue = 1;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) || GetBattlerSide(battler) != B_SIDE_OPPONENT)
        return 0;

    // Two opponents support.
    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        if (gBattlerPartyIndexes[battler] >= 3)
        {
            firstId = 3, lastId = PARTY_SIZE;
            trainerId = gTrainerBattleOpponent_B;
            retValue = 2;
        }
        else
        {
            firstId = 0, lastId = 3;
            trainerId = gTrainerBattleOpponent_A;
        }
    }
    else
    {
        firstId = 0, lastId = PARTY_SIZE;
        trainerId = gTrainerBattleOpponent_A;
    }

    for (i = 0; i < ARRAY_COUNT(sTrainerSlides); i++)
    {
        if (trainerId == sTrainerSlides[i].trainerId
            && (((gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && sTrainerSlides[i].isFrontierTrainer)
                || (!(gBattleTypeFlags & BATTLE_TYPE_FRONTIER) && !sTrainerSlides[i].isFrontierTrainer)))
        {
            gBattleScripting.battler = battler;
            switch (which)
            {
            case TRAINER_SLIDE_LAST_SWITCHIN:
                if (sTrainerSlides[i].msgLastSwitchIn != NULL && !CanBattlerSwitch(battler))
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastSwitchIn;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_LOW_HP:
                if (sTrainerSlides[i].msgLastLowHp != NULL
                    && GetEnemyMonCount(firstId, lastId, TRUE) == 1
                    && BattlerHPPercentage(battler, GREATER_THAN_OR_EQUAL, 4)
                    && !gBattleStruct->trainerSlideLowHpMsgDone)
                {
                    gBattleStruct->trainerSlideLowHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastLowHp;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_FIRST_DOWN:
                if (sTrainerSlides[i].msgFirstDown != NULL && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1)
                {
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstDown;
                    return retValue;
                }
                break;
            case TRAINER_SLIDE_LAST_HALF_HP:
                if (sTrainerSlides[i].msgLastHalfHp != NULL
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE) - 1
                 && BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 2) && BattlerHPPercentage(battler, GREATER_THAN, 4)
                 && !gBattleStruct->trainerSlideHalfHpMsgDone)
                {
                    gBattleStruct->trainerSlideHalfHpMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgLastHalfHp;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_CRITICAL_HIT:
                if (sTrainerSlides[i].msgFirstCriticalHit != NULL && gBattleStruct->trainerSlideFirstCriticalHitMsgState == 1)
                {
                    gBattleStruct->trainerSlideFirstCriticalHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstCriticalHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_SUPER_EFFECTIVE_HIT:
                if (sTrainerSlides[i].msgFirstSuperEffectiveHit != NULL
                    && gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState == 1
                    && gBattleMons[battler].hp)
                {
                    gBattleStruct->trainerSlideFirstSuperEffectiveHitMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSuperEffectiveHit;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_FIRST_STAB_MOVE:
                if (sTrainerSlides[i].msgFirstSTABMove != NULL
                 && gBattleStruct->trainerSlideFirstSTABMoveMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlideFirstSTABMoveMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgFirstSTABMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_PLAYER_MON_UNAFFECTED:
                if (sTrainerSlides[i].msgPlayerMonUnaffected != NULL
                 && gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState == 1
                 && GetEnemyMonCount(firstId, lastId, TRUE) == GetEnemyMonCount(firstId, lastId, FALSE))
                {
                    gBattleStruct->trainerSlidePlayerMonUnaffectedMsgState = 2;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgPlayerMonUnaffected;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_MEGA_EVOLUTION:
                if (sTrainerSlides[i].msgMegaEvolution != NULL && !gBattleStruct->trainerSlideMegaEvolutionMsgDone)
                {
                    gBattleStruct->trainerSlideMegaEvolutionMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgMegaEvolution;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_Z_MOVE:
                if (sTrainerSlides[i].msgZMove != NULL && !gBattleStruct->trainerSlideZMoveMsgDone)
                {
                    gBattleStruct->trainerSlideZMoveMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgZMove;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_BEFORE_FIRST_TURN:
                if (sTrainerSlides[i].msgBeforeFirstTurn != NULL && !gBattleStruct->trainerSlideBeforeFirstTurnMsgDone)
                {
                    gBattleStruct->trainerSlideBeforeFirstTurnMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgBeforeFirstTurn;
                    return TRUE;
                }
                break;
            case TRAINER_SLIDE_DYNAMAX:
                if (sTrainerSlides[i].msgDynamax != NULL && !gBattleStruct->trainerSlideDynamaxMsgDone)
                {
                    gBattleStruct->trainerSlideDynamaxMsgDone = TRUE;
                    gBattleStruct->trainerSlideMsg = sTrainerSlides[i].msgDynamax;
                    return TRUE;
                }
                break;
            }
            break;
        }
    }

    return 0;
}
