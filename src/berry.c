#include "global.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/items.h"

#include "rogue_controller.h"
#include "rogue_popup.h"

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry);
static bool32 BerryTreeGrow(struct BerryTree *tree);
static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree);
static u8 GetNumStagesWateredByBerryTreeId(u8 id);
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water);
static u8 CalcBerryYield(struct BerryTree *tree);
static u8 GetBerryCountByBerryTreeId(u8 id);
static u16 GetStageDurationByBerryType(u8);

//.rodata
static const u8 sBerryDescriptionPart1_Cheri[] = _("Da unas flores preciosas y delicadas.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("Esta baya roja y brillante pica mucho.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("Su gruesa piel y su pulpa son muy");
static const u8 sBerryDescriptionPart2_Chesto[] = _("duras. Tiene un sabor seco.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Muy dulce y deliciosa.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Es muy tierna: manéjala con cuidado.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Si sus hojas crecen largas y rizadas,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("la baya se vuelve muy amarga.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("Esta baya dura está llena de un jugo");
static const u8 sBerryDescriptionPart2_Aspear[] = _("abundante. Es bastante ácida.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Crece más despacio que Zreza y otras.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("Cuanto más pequeña, más sabrosa.");
static const u8 sBerryDescriptionPart1_Oran[] = _("Una baya peculiar de sabor variado.");
static const u8 sBerryDescriptionPart2_Oran[] = _("Crece en medio día.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Le encanta el sol. Su color se");
static const u8 sBerryDescriptionPart2_Persim[] = _("vuelve más vivo cuando le da el sol.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Crece despacio. Si se la mima,");
static const u8 sBerryDescriptionPart2_Lum[] = _("puede dar dos bayas.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Pariente cercana de la Aranja. Esta");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("gran baya tiene un sabor equilibrado.");
static const u8 sBerryDescriptionPart1_Figy[] = _("Esta baya, que parece mordisqueada,");
static const u8 sBerryDescriptionPart2_Figy[] = _("rebosa sustancias picantes.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("Se dice que le salieron bultos para");
static const u8 sBerryDescriptionPart2_Wiki[] = _("que los Pokémon la sujeten mejor.");
static const u8 sBerryDescriptionPart1_Mago[] = _("Se curva a medida que crece.");
static const u8 sBerryDescriptionPart2_Mago[] = _("Cuanto más curva, más dulce.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("Su flor es delicada. Es poco común");
static const u8 sBerryDescriptionPart2_Aguav[] = _("porque puede crecer sin luz.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("Una baya muy grande y ácida.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("Tarda al menos un día en crecer.");
static const u8 sBerryDescriptionPart1_Razz[] = _("Esta baya roja pica un poco.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Crece rápido: solo en cuatro horas.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("Es azul por fuera, pero al comerla");
static const u8 sBerryDescriptionPart2_Bluk[] = _("deja la boca negra.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("Fue la séptima baya descubierta");
static const u8 sBerryDescriptionPart2_Nanab[] = _("en el mundo. Es dulce.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("Su flor es pequeña y blanca. Tiene un");
static const u8 sBerryDescriptionPart2_Wepear[] = _("delicado equilibrio de amargo y ácido.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("No soporta el viento ni el frío.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("La pulpa pica y la piel es ácida.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Por mucho que se riegue,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("solo da hasta seis bayas.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Variedad rara con forma de raíz.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Da una flor muy grande.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Le encanta el agua. Crece fuerte");
static const u8 sBerryDescriptionPart2_Qualot[] = _("incluso donde llueve sin parar.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("Una baya muy valiosa que casi");
static const u8 sBerryDescriptionPart2_Hondew[] = _("nunca se ve. Es deliciosa.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Pese a ser tierna y redonda,");
static const u8 sBerryDescriptionPart2_Grepa[] = _("es increíblemente ácida.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("Pica tanto que tuerce los labios.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("Tarda en crecer.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("Una baya de una época antigua. Puede");
static const u8 sBerryDescriptionPart2_Cornn[] = _("que no crezca si no se planta mucha.");
static const u8 sBerryDescriptionPart1_Magost[] = _("Todo el mundo dice que tiene");
static const u8 sBerryDescriptionPart2_Magost[] = _("un sabor muy equilibrado.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Variedad rara cubierta de pelo.");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("Es bastante amarga.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Muy ácida. Un solo bocado deja");
static const u8 sBerryDescriptionPart2_Nomel[] = _("sin sentido del gusto tres días.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("Esta baya de rojo vivo pica mucho.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Sus verrugas sueltan algo picante.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Llega a la deriva por el mar.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("Se cree que crece en otro lugar.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("Una baya enorme: se han hallado de");
static const u8 sBerryDescriptionPart2_Watmel[] = _("más de 50 cm. Dulcísima.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Amarga solo con mirarla. Tanto");
static const u8 sBerryDescriptionPart2_Durin[] = _("que nadie la ha comido tal cual.");
static const u8 sBerryDescriptionPart1_Belue[] = _("Es brillante y parece deliciosa, pero");
static const u8 sBerryDescriptionPart2_Belue[] = _("es muy ácida. Tarda en crecer.");
static const u8 sBerryDescriptionPart1_Chilan[] = _("Con ella se puede hacer un silbato");
static const u8 sBerryDescriptionPart2_Chilan[] = _("de sonido indescriptible.");
static const u8 sBerryDescriptionPart1_Occa[] = _("Dicen que antes crecía en el trópico.");
static const u8 sBerryDescriptionPart2_Occa[] = _("Pica muchísimo.");
static const u8 sBerryDescriptionPart1_Passho[] = _("Su pulpa está llena de burbujitas");
static const u8 sBerryDescriptionPart2_Passho[] = _("que la hacen flotar en el agua.");
static const u8 sBerryDescriptionPart1_Wacan[] = _("La energía de los rayos que recibe");
static const u8 sBerryDescriptionPart2_Wacan[] = _("la hace crecer grande y sabrosa.");
static const u8 sBerryDescriptionPart1_Rindo[] = _("Sabe a verdura, pero es rica en");
static const u8 sBerryDescriptionPart2_Rindo[] = _("fibra muy saludable.");
static const u8 sBerryDescriptionPart1_Yache[] = _("Tiene un sabor seco y ácido muy");
static const u8 sBerryDescriptionPart2_Yache[] = _("refrescante. Mejor bien fría.");
static const u8 sBerryDescriptionPart1_Chople[] = _("Contiene una sustancia que da calor.");
static const u8 sBerryDescriptionPart2_Chople[] = _("Hasta calienta un corazón frío.");
static const u8 sBerryDescriptionPart1_Kebia[] = _("Verde brillante por fuera, por dentro");
static const u8 sBerryDescriptionPart2_Kebia[] = _("está llena de pulpa negra.");
static const u8 sBerryDescriptionPart1_Shuca[] = _("Su pulpa dulce tiene un toque");
static const u8 sBerryDescriptionPart2_Shuca[] = _("intenso y aromático.");
static const u8 sBerryDescriptionPart1_Coba[] = _("Se dice que es un cruce de dos");
static const u8 sBerryDescriptionPart2_Coba[] = _("bayas traídas por el viento de lejos.");
static const u8 sBerryDescriptionPart1_Payapa[] = _("Dicen que percibe las emociones: se");
static const u8 sBerryDescriptionPart2_Payapa[] = _("hincha cuando alguien se acerca.");
static const u8 sBerryDescriptionPart1_Tanga[] = _("Le sale una flor en la punta que atrae");
static const u8 sBerryDescriptionPart2_Tanga[] = _("a los Pokémon Bicho con sus pétalos.");
static const u8 sBerryDescriptionPart1_Charti[] = _("Por su sabor seco se encurte.");
static const u8 sBerryDescriptionPart2_Charti[] = _("A veces se come cruda.");
static const u8 sBerryDescriptionPart1_Kasib[] = _("Viejas supersticiones le dan un poder");
static const u8 sBerryDescriptionPart2_Kasib[] = _("extraño. Es un amuleto muy popular.");
static const u8 sBerryDescriptionPart1_Haban[] = _("Si se cuece bien, amarga menos.");
static const u8 sBerryDescriptionPart2_Haban[] = _("Da una buena mermelada.");
static const u8 sBerryDescriptionPart1_Colbur[] = _("Sus ganchitos se enganchan a los");
static const u8 sBerryDescriptionPart2_Colbur[] = _("Pokémon para llegar lejos.");
static const u8 sBerryDescriptionPart1_Babiri[] = _("Muy dura y de sabor fuerte. Antes");
static const u8 sBerryDescriptionPart2_Babiri[] = _("se usaba para hacer medicinas.");
static const u8 sBerryDescriptionPart1_Roseli[] = _("En la naturaleza crece en grandes");
static const u8 sBerryDescriptionPart2_Roseli[] = _("círculos por motivos desconocidos.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("Una baya misteriosa. Se rumorea que");
static const u8 sBerryDescriptionPart2_Liechi[] = _("encierra el poder del mar.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("Una baya misteriosa. Se rumorea que");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("encierra el poder de la tierra.");
static const u8 sBerryDescriptionPart1_Salac[] = _("Una baya misteriosa. Se rumorea que");
static const u8 sBerryDescriptionPart2_Salac[] = _("encierra el poder del cielo.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("Una baya misteriosa. Se rumorea que");
static const u8 sBerryDescriptionPart2_Petaya[] = _("encierra el poder de todo ser vivo.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("Una baya muy misteriosa. No se sabe");
static const u8 sBerryDescriptionPart2_Apicot[] = _("qué puede pasar ni cómo se usa.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Dicen que es una baya legendaria.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Se supone que llevarla da alegría.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Tan potente que la abandonaron en el");
static const u8 sBerryDescriptionPart2_Starf[] = _("fin del mundo. Se cree un espejismo.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("Una baya totalmente enigmática.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Parece tener poder estelar.");
static const u8 sBerryDescriptionPart1_Micle[] = _("Hace que lo que se coma a la vez");
static const u8 sBerryDescriptionPart2_Micle[] = _("sepa dulce.");
static const u8 sBerryDescriptionPart1_Custap[] = _("La pulpa bajo la piel de la baya");
static const u8 sBerryDescriptionPart2_Custap[] = _("Chiri es dulce y cremosa.");
static const u8 sBerryDescriptionPart1_Jaboca[] = _("Sus granitos estallan con ritmo");
static const u8 sBerryDescriptionPart2_Jaboca[] = _("si se maneja con brusquedad.");
static const u8 sBerryDescriptionPart1_Rowap[] = _("Antes se sacaban trozos con forma");
static const u8 sBerryDescriptionPart2_Rowap[] = _("de peonza para usarlos de juguete.");
static const u8 sBerryDescriptionPart1_Kee[] = _("Al principio pica muchísimo y");
static const u8 sBerryDescriptionPart2_Kee[] = _("luego es amarguísima.");
static const u8 sBerryDescriptionPart1_Maranga[] = _("Por fuera es muy amarga, pero por");
static const u8 sBerryDescriptionPart2_Maranga[] = _("dentro sabe a una bebida dulce.");

const struct Berry gBerries[] =
{
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zreza"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cheri,
        .description2 = sBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Atania"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chesto,
        .description2 = sBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Meloc"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pecha,
        .description2 = sBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Safre"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rawst,
        .description2 = sBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Perasi"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aspear,
        .description2 = sBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zanama"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Leppa,
        .description2 = sBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aranja"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Oran,
        .description2 = sBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Caquic"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Persim,
        .description2 = sBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ziuela"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lum,
        .description2 = sBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zidra"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Sitrus,
        .description2 = sBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Higog"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Figy,
        .description2 = sBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Wiki"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Wiki,
        .description2 = sBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ango"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Mago,
        .description2 = sBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Guaya"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aguav,
        .description2 = sBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pabaya"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Iapapa,
        .description2 = sBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Frambu"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Razz,
        .description2 = sBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Oram"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Bluk,
        .description2 = sBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Latano"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Nanab,
        .description2 = sBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Peragu"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Wepear,
        .description2 = sBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pinia"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Pinap,
        .description2 = sBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Grana"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pomeg,
        .description2 = sBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Algama"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kelpsy,
        .description2 = sBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Ispero"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Qualot,
        .description2 = sBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Meluce"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Hondew,
        .description2 = sBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Uvav"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Grepa,
        .description2 = sBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Tamate"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Tamato,
        .description2 = sBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Mais"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cornn,
        .description2 = sBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aostan"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Magost,
        .description2 = sBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rautan"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rabuta,
        .description2 = sBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Monli"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Nomel,
        .description2 = sBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Wikano"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Spelon,
        .description2 = sBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Plama"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Pamtre,
        .description2 = sBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Sambia"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Watmel,
        .description2 = sBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rudion"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Durin,
        .description2 = sBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Andano"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Belue,
        .description2 = sBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_CHILAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Chilan"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 34,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chilan,
        .description2 = sBerryDescriptionPart2_Chilan,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 25,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_OCCA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Caoca"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 90,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Occa,
        .description2 = sBerryDescriptionPart2_Occa,
        .stageDuration = 18,
        .spicy = 15,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_PASSHO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pasio"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 33,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Passho,
        .description2 = sBerryDescriptionPart2_Passho,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 15,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_WACAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Gualot"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 250,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Wacan,
        .description2 = sBerryDescriptionPart2_Wacan,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 15,
        .bitter = 0,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_RINDO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Tamar"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 156,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rindo,
        .description2 = sBerryDescriptionPart2_Rindo,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 15,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_YACHE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Rimoya"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Yache,
        .description2 = sBerryDescriptionPart2_Yache,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 15,
        .smoothness = 30,
    },

    [ITEM_CHOPLE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Pomaro"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 77,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chople,
        .description2 = sBerryDescriptionPart2_Chople,
        .stageDuration = 18,
        .spicy = 15,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_KEBIA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Kebia"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 90,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kebia,
        .description2 = sBerryDescriptionPart2_Kebia,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 15,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_SHUCA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Acardo"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 42,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Shuca,
        .description2 = sBerryDescriptionPart2_Shuca,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 15,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_COBA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Kouba"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 278,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Coba,
        .description2 = sBerryDescriptionPart2_Coba,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 15,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_PAYAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Payapa"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 252,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Payapa,
        .description2 = sBerryDescriptionPart2_Payapa,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 15,
        .smoothness = 30,
    },

    [ITEM_TANGA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Yecana"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 42,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Tanga,
        .description2 = sBerryDescriptionPart2_Tanga,
        .stageDuration = 18,
        .spicy = 20,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 35,
    },

    [ITEM_CHARTI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Alcho"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 28,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Charti,
        .description2 = sBerryDescriptionPart2_Charti,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 20,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_KASIB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Drasi"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 144,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kasib,
        .description2 = sBerryDescriptionPart2_Kasib,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 10,
        .sweet = 20,
        .bitter = 0,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_HABAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Anjiro"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 23,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Haban,
        .description2 = sBerryDescriptionPart2_Haban,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 20,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_COLBUR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Dillo"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 39,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Colbur,
        .description2 = sBerryDescriptionPart2_Colbur,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 20,
        .smoothness = 35,
    },

    [ITEM_BABIRI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Baribá"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 265,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Babiri,
        .description2 = sBerryDescriptionPart2_Babiri,
        .stageDuration = 18,
        .spicy = 25,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_ROSELI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Hibis"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 35,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Roseli,
        .description2 = sBerryDescriptionPart2_Roseli,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 25,
        .bitter = 10,
        .sour = 0,
        .smoothness = 35,
    },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Lichi"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Liechi,
        .description2 = sBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Gonlan"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Ganlon,
        .description2 = sBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aslac"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Salac,
        .description2 = sBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Yapati"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Petaya,
        .description2 = sBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Aricoc"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Apicot,
        .description2 = sBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Zonlan"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lansat,
        .description2 = sBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Arabol"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Starf,
        .description2 = sBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Enigma"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 155,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 60,
    },

    [ITEM_MICLE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Lagro"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 41,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Micle,
        .description2 = sBerryDescriptionPart2_Micle,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 60,
    },

    [ITEM_CUSTAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Chiri"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 267,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Custap,
        .description2 = sBerryDescriptionPart2_Custap,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 60,
    },

    [ITEM_JABOCA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Jaboca"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 33,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Jaboca,
        .description2 = sBerryDescriptionPart2_Jaboca,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 60,
    },

    [ITEM_ROWAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Magua"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 52,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rowap,
        .description2 = sBerryDescriptionPart2_Rowap,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 60,
    },

    [ITEM_KEE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Biglia"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kee,
        .description2 = sBerryDescriptionPart2_Kee,
        .stageDuration = 24,
        .spicy = 30,
        .dry = 30,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 60,
    },

    [ITEM_MARANGA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("Marnga"), // "Maranga" is too long
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 5,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Maranga,
        .description2 = sBerryDescriptionPart2_Maranga,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 30,
        .bitter = 30,
        .sour = 10,
        .smoothness = 60,
    },

    [ITEM_ENIGMA_BERRY_E_READER - FIRST_BERRY_INDEX] =
    {
        .name = _("Enigma"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },
};

const struct BerryCrushBerryData gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  50, .powder =  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  50, .powder =  20},
    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  50, .powder =  20},
    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  50, .powder =  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  50, .powder =  20},
    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  50, .powder =  30},
    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  50, .powder =  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  50, .powder =  30},
    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX]             = {.difficulty =  50, .powder =  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  50, .powder =  30},
    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  60, .powder =  50},
    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  60, .powder =  50},
    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  60, .powder =  50},
    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  60, .powder =  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  60, .powder =  50},
    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  80, .powder =  70},
    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX]            = {.difficulty =  80, .powder =  70},
    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  80, .powder =  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX]          = {.difficulty =  80, .powder =  70},
    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX]           = {.difficulty =  80, .powder =  70},
    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 100, .powder = 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 100, .powder = 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 100, .powder = 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 100, .powder = 100},
    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 100, .powder = 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 130, .powder = 150},
    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 130, .powder = 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 130, .powder = 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 130, .powder = 150},
    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 130, .powder = 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 160, .powder = 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 160, .powder = 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 160, .powder = 250},
    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 160, .powder = 250},
    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 160, .powder = 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 180, .powder = 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 180, .powder = 500},
    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 180, .powder = 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 180, .powder = 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 180, .powder = 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX]          = {.difficulty = 200, .powder = 750},
    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX]           = {.difficulty = 200, .powder = 750},
    [ITEM_ENIGMA_BERRY_E_READER - FIRST_BERRY_INDEX] = {.difficulty = 150, .powder = 200}
};

const struct BerryTree gBlankBerryTree = {};

// unused
void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
}

void SetEnigmaBerry(u8 *src)
{
    u32 i;
    u8 *dest = (u8 *)&gSaveBlock1Ptr->enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry); i++)
        dest[i] = src[i];
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8 *)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}

bool32 IsEnigmaBerryValid(void)
{
    if (!gSaveBlock1Ptr->enigmaBerry.berry.stageDuration)
        return FALSE;
    if (!gSaveBlock1Ptr->enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;
    return TRUE;
}

const struct Berry *GetBerryInfo(u8 berry)
{
    if (berry == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY_E_READER) && IsEnigmaBerryValid())
        return (struct Berry *)(&gSaveBlock1Ptr->enigmaBerry.berry);
    else
    {
        if (berry == BERRY_NONE || berry > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berry = ITEM_TO_BERRY(FIRST_BERRY_INDEX);
        return &gBerries[berry - 1];
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1Ptr->berryTrees[id];
}

bool32 ObjectEventInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));

    switch (tree->stage)
    {
    case BERRY_STAGE_PLANTED:
        tree->watered1 = TRUE;
        break;
    case BERRY_STAGE_SPROUTED:
        tree->watered2 = TRUE;
        break;
    case BERRY_STAGE_TALLER:
        tree->watered3 = TRUE;
        break;
    case BERRY_STAGE_FLOWERING:
        tree->watered4 = TRUE;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerFacingEmptyBerryTreePatch(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() == BerryTreeScript
     && GetStageByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent)) == BERRY_STAGE_NO_BERRY)
        return TRUE;
    else
        return FALSE;
}

bool8 TryToWaterBerryTree(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() != BerryTreeScript)
        return FALSE;
    else
        return ObjectEventInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

void ClearBerryTreeRange(u16 from, u16 to)
{
    int i;

    for (i = from; i <= to; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

static bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->stopGrowth)
        return FALSE;

    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TALLER:
        tree->stage++;
        break;
    //case BERRY_STAGE_BERRIES:
    //    tree->watered1 = 0;
    //    tree->watered2 = 0;
    //    tree->watered3 = 0;
    //    tree->watered4 = 0;
    //    tree->berryYield = 0;
    //    tree->stage = BERRY_STAGE_SPROUTED;
    //    if (++tree->regrowthCount == 10)
    //        *tree = gBlankBerryTree;
    //    break;
    }
    return TRUE;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->stopGrowth)
        {
            s32 time = minutes;

            if(i >= BERRY_TREE_DAYCARE_FIRST && i <= BERRY_TREE_DAYCARE_LAST)
            {
                // We want to grow daycare berries instantly
                time = 99999;
            }

            while (time != 0)
            {
                if (tree->minutesUntilNextStage > time)
                {
                    tree->minutesUntilNextStage -= time;
                    break;
                }
                time -= tree->minutesUntilNextStage;
                tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry);
                if (!BerryTreeGrow(tree))
                    break;
                if (tree->stage == BERRY_STAGE_BERRIES)
                    tree->minutesUntilNextStage *= 4;
            }
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 allowGrowth)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    *tree = gBlankBerryTree;
    tree->berry = berry;
    tree->minutesUntilNextStage = GetStageDurationByBerryType(berry);
    tree->stage = stage;
    tree->watered1 = TRUE;
    tree->watered2 = TRUE;
    tree->watered3 = TRUE;
    tree->watered4 = TRUE;
    if (stage == BERRY_STAGE_BERRIES)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->minutesUntilNextStage *= 4;
    }

    // Stop growth, to keep tree at this stage until the player has seen it
    // allowGrowth is always true for berry trees the player has planted
    if (!allowGrowth)
        tree->stopGrowth = TRUE;
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1Ptr->berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].stage;
}

u8 ItemIdToBerryType(u16 item)
{
    u16 berry = item - FIRST_BERRY_INDEX;

    if (berry > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return ITEM_TO_BERRY(FIRST_BERRY_INDEX);
    else
        return ITEM_TO_BERRY(item);
}

u16 BerryTypeToItemId(u16 berry)
{
    u16 item = berry - 1;

    if (item > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;
    else
        return berry + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, BERRY_NAME_LENGTH);
    string[BERRY_NAME_LENGTH] = EOS;
}

void GetBerryCountStringByBerryType(u8 berry, u8 *dest, u32 berryCount)
{
    GetBerryCountString(dest, GetBerryInfo(berry)->name, berryCount);
}

void AllowBerryTreeGrowth(u8 id)
{
    GetBerryTreeInfo(id)->stopGrowth = FALSE;
}

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered1)
        count++;
    if (tree->watered2)
        count++;
    if (tree->watered3)
        count++;
    if (tree->watered4)
        count++;
    return count;
}

static u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

// Berries can be watered at 4 stages of growth. This function is likely meant
// to divide the berry yield range equally into quartiles. If you watered the
// tree n times, your yield is a random number in the nth quartile.
//
// However, this function actually skews towards higher berry yields, because
// it rounds `extraYield` to the nearest whole number.
//
// See resulting yields: https://gist.github.com/hondew/2a099dbe54aa91414decdbfaa524327d,
// and bug fix: https://gist.github.com/hondew/0f0164e5b9dadfd72d24f30f2c049a0b.
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0)
        return min;
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        // Round upwards
        if ((rand % NUM_WATER_STAGES) >= NUM_WATER_STAGES / 2)
            extraYield = rand / NUM_WATER_STAGES + 1;
        else
            extraYield = rand / NUM_WATER_STAGES;
        return extraYield + min;
    }
}

static u8 CalcBerryYield(struct BerryTree *tree)
{
    const struct Berry *berry = GetBerryInfo(tree->berry);
    u8 min = berry->minYield + 1;
    u8 max = berry->maxYield + 1;

    return CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));
}

static u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berryYield;
}

static u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->stageDuration * 60;
}

void ObjectEventInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 localId;
    u8 group;
    u8 num;

    id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    berry = GetBerryTypeByBerryTreeId(id);
    AllowBerryTreeGrowth(id);
    localId = gSpecialVar_LastTalked;
    num = gSaveBlock1Ptr->location.mapNum;
    group = gSaveBlock1Ptr->location.mapGroup;
    if (IsBerryTreeSparkling(localId, num, group))
        gSpecialVar_0x8004 = BERRY_STAGE_SPARKLING;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    GetBerryCountStringByBerryType(berry, gStringVar1, gSpecialVar_0x8006);
}

void ObjectEventInteractionGetBerryName(void)
{
    u8 berryType = GetBerryTypeByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    GetBerryNameByBerryType(berryType, gStringVar1);
}

void ObjectEventInteractionGetBerryCountString(void)
{
    u8 treeId = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(treeId);
    u8 count = GetBerryCountByBerryTreeId(treeId);

    if(count == 0)
        count = 1;
    
    GetBerryCountStringByBerryType(berry, gStringVar1, count);
}

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}

void Bag_ChooseBall(void)
{
    SetMainCallback2(CB2_ChooseBall);
}

void Bag_ChoosePokeblock(void)
{
    SetMainCallback2(CB2_ChoosePokeblock);
}

void ObjectEventInteractionPlantBerryTree(void)
{
    u8 berry = ItemIdToBerryType(gSpecialVar_ItemId);

    PlantBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent), berry, BERRY_STAGE_PLANTED, TRUE);
    ObjectEventInteractionGetBerryTreeData();
}

void ObjectEventInteractionPickBerryTree(void)
{
    u8 id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(id);
    u16 itemId = BerryTypeToItemId(berry);
    u8 count = GetBerryCountByBerryTreeId(id);

    count = Rogue_ModifyItemPickupAmount(itemId, count);
    gSpecialVar_0x8004 = AddBagItem(itemId, count);

    if(gSpecialVar_0x8004 == TRUE)
        Rogue_PushPopup_AddBerry(itemId, count);
    else
        Rogue_PushPopup_CannotTakeItem(itemId, count);
}

void ObjectEventInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    SetBerryTreeJustPicked(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(POCKET_BERRIES);
}

// Berry tree growth is frozen at their initial stage (usually, fully grown) until the player has seen the tree
// For all berry trees on screen, allow normal growth
void SetBerryTreesSeen(void)
{
    u16 cam_left;
    u16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            s16 x = gObjectEvents[i].currentCoords.x;
            s16 y = gObjectEvents[i].currentCoords.y;
            if (left <= x && x <= right && top <= y && y <= bottom)
                AllowBerryTreeGrowth(gObjectEvents[i].trainerRange_berryTreeId);
        }
    }
}
