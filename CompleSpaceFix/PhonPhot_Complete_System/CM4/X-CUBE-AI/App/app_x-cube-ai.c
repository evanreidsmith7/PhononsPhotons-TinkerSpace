
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "ann_756.h"
#include "ann_756_data.h"

/* USER CODE BEGIN includes */

#define NUM_FEATURES 756

static const float mean[NUM_FEATURES]  = {-46.40557841,-54.89891472,-59.8315255,-62.05286259,-62.96059529,-63.21379038,-63.33901459,-63.10575411,-62.6317879,-62.64818277,-63.36124144,-63.81283654,-63.39978041,-63.39898474,-63.85611651,-64.16177143,-64.33593858,-64.39451731,-64.4067415,-64.44084371,-64.33753355,-64.33276072,-64.32320858,-64.28602186,-64.22192435,-64.07765795,-63.89706753,-63.68619006,-63.42042887,-63.14916114,-62.97093129,-62.90983193,-63.01611493,-63.33154085,-63.48177882,-63.81296202,-64.1076238,-64.23952923,-63.6893137,-56.7173183,-37.71878331,-35.11763701,-45.01791541,-62.69456019,-64.75226528,-65.03743142,-65.153186,-65.10379374,-65.17549873,-65.30162261,-65.31923703,-65.32540021,-65.4164959,-65.41492399,-65.45664649,-65.09402085,-65.31518586,-65.6069675,-65.68643226,-65.73277863,-65.84845591,-65.90088053,-65.97703725,-65.45482451,-65.2911433,-65.85167579,-66.06326003,-64.9769275,-56.74408827,-57.62509819,-64.89571053,-64.42811997,-66.11195309,-66.48377565,-66.59883767,-66.59137669,-66.60148949,-66.70675245,-66.72324216,-66.54105077,-66.17239624,-66.38190734,-66.63873522,-66.92988375,-67.08989273,-67.0764084,-67.05696559,-67.12077829,-67.14635783,-67.16973161,-67.19941906,-67.14559157,-67.00927153,-66.93306822,-66.95012036,-66.91107502,-66.05542013,-65.89213186,-66.68217574,-67.00043794,-67.09262357,-66.21449892,-63.88896457,-66.07868463,-67.13486063,-67.11173188,-67.0462645,-65.73888229,-67.10401692,-68.06408224,-68.0416523,-67.96336646,-67.67301132,-67.42338666,-67.57417693,-67.78611464,-67.8509871,-67.82472466,-67.81068981,-67.94224797,-68.14742205,-68.15719639,-67.61270511,-66.14262761,-65.62414787,-68.02562443,-46.37645771,-54.84564137,-59.76477872,-61.88576772,-62.74622551,-63.37731436,-63.62394726,-63.60855254,-63.50937827,-63.51310414,-63.71495218,-63.91507418,-63.93584067,-63.96333643,-63.93677958,-64.02561893,-64.23110269,-64.26929364,-64.36166161,-64.30841834,-64.23310583,-64.29779755,-64.30631848,-64.30986505,-64.31777166,-64.25354081,-64.2813528,-64.26044853,-64.15596985,-64.03594284,-63.89503767,-63.9379394,-64.07705244,-64.01986497,-63.95920089,-64.00861687,-64.14356602,-64.22542231,-64.20462079,-63.45182937,-52.91817165,-50.43915683,-59.14675695,-64.80407143,-64.92739123,-65.06384765,-65.1602644,-65.16946957,-65.26352567,-65.3743726,-65.48280189,-65.50845658,-65.67280255,-65.75784083,-65.71180925,-65.30671324,-65.56187702,-65.886167,-65.99918481,-66.08416873,-66.21458314,-66.2786793,-66.31735503,-65.9458505,-65.76434635,-66.22271573,-66.06934041,-65.13939441,-57.44318718,-58.32737467,-65.45730266,-65.25854086,-66.62340724,-66.950602,-67.02519448,-67.03984826,-67.05451348,-67.09602998,-67.17744761,-67.04552888,-66.70034706,-66.80496904,-67.09907186,-67.31992056,-67.51115658,-67.48790558,-67.34972524,-67.47369718,-67.5224696,-67.54603565,-67.6145899,-67.4900276,-67.34895128,-67.37579789,-67.43768478,-67.41472877,-66.50855251,-66.37705897,-67.28502467,-67.57318475,-67.68601545,-66.65766855,-63.89593484,-66.4141475,-67.57551497,-67.49744554,-67.43949038,-66.22535033,-67.48493025,-68.37829198,-68.34734668,-68.31149255,-68.06187742,-67.94033983,-68.04882119,-68.26451833,-68.35445297,-68.27350619,-68.23746734,-68.39278006,-68.48216338,-68.4407359,-67.92648902,-66.27901149,-65.51594492,-68.23963878,-46.42299278,-54.88380692,-60.00778109,-62.6405393,-63.7773943,-64.21555559,-64.43741997,-64.39661471,-64.36555922,-64.33754738,-64.4372275,-64.74672928,-64.79887812,-64.93157653,-64.87808322,-65.00078281,-65.21006897,-65.25654768,-65.27697225,-65.19382976,-65.10858924,-65.03860115,-64.99780715,-64.92067106,-64.87625556,-64.76931853,-64.6312548,-64.38520468,-64.03214206,-63.77382559,-63.41999524,-62.43812654,-62.44314889,-63.48761281,-62.9849319,-63.49690795,-64.40981853,-64.67957909,-64.71631927,-64.31396644,-59.18931786,-57.31655559,-62.91557179,-64.96164631,-65.0474792,-65.07564094,-65.0935092,-65.01754172,-65.01749608,-64.98890949,-65.0878894,-65.13735045,-65.21971993,-65.25163599,-65.22585684,-65.14189456,-65.20146521,-65.22062954,-65.28582669,-65.27894944,-65.34449961,-65.30604113,-65.37799347,-64.98829881,-64.86952417,-65.3287167,-65.38052371,-65.02722439,-59.86906107,-60.59487359,-64.39574562,-63.73811713,-65.44362431,-65.83008166,-65.85921182,-65.88882894,-65.92883659,-66.0114555,-65.92245464,-65.79838045,-65.52267079,-65.64111674,-65.78128143,-65.80661581,-66.2324793,-66.30611498,-66.27152937,-66.24634231,-66.36349671,-66.44401256,-66.42851088,-66.38983677,-66.34644552,-66.27719579,-66.28817576,-66.19609041,-65.47495186,-65.35964843,-66.13060998,-66.43301666,-66.53326361,-66.44824076,-65.93252283,-66.4492718,-66.70976267,-66.81071316,-66.76354908,-65.93233308,-66.81786367,-67.45205412,-67.51280886,-67.54866145,-67.38186904,-67.2845424,-67.38689597,-67.48097927,-67.4774179,-67.48803526,-67.46784737,-67.55393318,-67.70121724,-67.73559305,-67.40167622,-65.53300834,-64.43372126,-67.50721007,-46.32888684,-54.75039331,-59.49514893,-61.57329177,-62.35871126,-62.78945204,-62.90984746,-62.91701439,-63.00976673,-63.05298961,-63.21430369,-63.44985186,-63.50468154,-63.49021201,-63.55001503,-63.67093353,-63.79934443,-63.8907831,-63.95470595,-63.9330769,-63.91434412,-63.93259408,-64.01688181,-63.97730698,-63.95397515,-63.87682097,-63.7983238,-63.6486362,-63.35428234,-63.18811427,-63.01037082,-62.43825743,-62.77438838,-63.60671898,-63.65026012,-64.06009826,-64.55133915,-64.82831533,-64.91353659,-64.72692641,-59.00732629,-56.89164314,-63.41913669,-65.58636899,-65.71183284,-65.75992819,-65.78533499,-65.6264102,-65.79993982,-66.00611222,-66.10374501,-66.25693165,-66.38494927,-66.47708729,-66.50365474,-66.52627583,-66.55328893,-66.61722365,-66.70638215,-66.77280273,-66.90147877,-66.95054246,-67.00576288,-66.34234686,-66.21102049,-66.92492545,-67.19118646,-66.7176123,-60.71178236,-61.49843595,-65.74020372,-64.75391309,-66.95652814,-67.58833216,-67.71023444,-67.80149982,-67.85466189,-67.90631574,-67.83709163,-67.6455282,-67.36554982,-67.444809,-67.6721994,-67.89314238,-68.16896627,-68.17067588,-68.09312496,-68.1245069,-68.23846675,-68.30372213,-68.23195601,-68.10628624,-67.99674337,-67.97007384,-67.91040229,-67.84661261,-67.00556534,-67.07022431,-67.88146427,-68.03406564,-68.08365898,-67.92922083,-67.40175543,-67.86792847,-68.04868386,-68.1810204,-68.29785481,-67.47735736,-68.34414314,-68.87398373,-68.81311212,-68.77276331,-68.5284006,-68.37641319,-68.50370806,-68.63040326,-68.63262012,-68.52610369,-68.49965281,-68.51903352,-68.62076409,-68.57734488,-68.30307511,-65.93602654,-64.27227127,-68.17899789,-46.36047629,-54.84222358,-59.96791017,-62.33964553,-63.36165312,-63.68982528,-63.78187801,-63.76559775,-63.82174095,-63.91537177,-63.99846633,-64.32104362,-64.29130231,-64.23254219,-64.49239634,-64.59300115,-64.69974144,-64.73859255,-64.78273693,-64.57843526,-64.25577407,-64.5737049,-64.63334787,-64.57668816,-64.433241,-64.30199607,-64.1475283,-63.98821269,-63.69811744,-63.44773213,-63.14080858,-62.67435901,-62.75536167,-63.04897048,-63.16705279,-63.55183967,-63.88156448,-64.05806702,-64.0956918,-63.82300513,-58.65606537,-56.61186081,-62.61913947,-64.39556575,-64.4763906,-64.51659935,-64.48119934,-64.50183812,-64.47973493,-64.49631014,-64.50998177,-64.56378226,-64.56978542,-64.54204684,-64.62053202,-64.58787728,-64.5480606,-64.58535146,-64.67800362,-64.73641685,-64.77949802,-64.77899547,-64.78221905,-64.35662182,-64.2089865,-64.7358733,-64.8658894,-64.59736364,-60.41862977,-60.70426399,-63.86035518,-63.69712614,-65.00677131,-65.33353908,-65.38905268,-65.39452242,-65.47682026,-65.53753852,-65.5182178,-65.41151432,-65.17778579,-65.28962532,-65.28887977,-65.33954188,-65.82954073,-65.92443779,-65.89465779,-65.92041529,-65.94651677,-66.08154713,-66.11963364,-66.07052226,-66.04121651,-66.02338703,-66.03080318,-65.9757821,-64.92884884,-65.00474419,-66.01107956,-66.24249037,-66.38866404,-66.180444,-65.52827346,-66.04877714,-66.35162818,-66.47141482,-66.52208017,-65.85486234,-66.66752739,-67.124167,-67.10689624,-67.13538043,-66.89242528,-66.78466397,-67.0323336,-67.13583458,-67.16348396,-67.16447883,-67.15517817,-67.23110253,-67.28518716,-67.34912435,-67.13292927,-65.1945942,-63.96349286,-67.09200495,-46.45047075,-54.89640967,-60.05037342,-62.76428881,-63.65613148,-63.5269231,-63.60136923,-63.29636078,-63.33702753,-63.55970618,-64.03867293,-64.51594088,-64.11187063,-64.30754063,-64.94643345,-65.22764353,-65.37230418,-65.54670547,-65.62232086,-65.58334645,-65.48318238,-65.45775171,-65.36710217,-65.2933316,-65.1736877,-64.95019468,-64.78260136,-64.51749653,-64.18269199,-63.90316839,-63.66563149,-63.57170095,-63.75830276,-64.01179875,-64.21759134,-64.60355778,-64.90894032,-65.07682624,-65.15945408,-64.46491396,-54.74174039,-52.5977576,-60.19662924,-65.49377296,-65.60025006,-65.63026726,-65.68327072,-65.66607773,-65.6548876,-65.65268993,-65.69092085,-65.70455608,-65.76873648,-65.77916893,-65.76992919,-65.70713952,-65.7485938,-65.77143878,-65.80044465,-65.84716351,-65.90294166,-65.87746873,-65.85852859,-65.7139744,-65.63032406,-65.89025136,-65.89658603,-65.14681216,-58.39931343,-59.23586303,-64.90671108,-64.91362142,-65.96075183,-66.22351759,-66.25652776,-66.25919854,-66.34139774,-66.39582719,-66.35299555,-66.23860583,-66.02262606,-66.10414107,-65.84969493,-65.75872099,-66.5706121,-66.6614746,-66.66010079,-66.69149909,-66.75302331,-66.78613719,-66.81914847,-66.77746141,-66.72540545,-66.74034617,-66.68476074,-66.61253939,-65.86947459,-65.73950687,-66.47417761,-66.69436997,-66.83095478,-66.78263624,-66.33403234,-66.81989554,-67.11479188,-67.22769943,-67.27165474,-66.79814614,-67.36811898,-67.66443308,-67.64287738,-67.67149719,-67.30102401,-67.14836288,-67.3734079,-67.48302311,-67.5420514,-67.59035298,-67.68091919,-67.76336883,-67.86643296,-67.92634228,-67.82990201,-66.15243876,-65.2187068,-67.86343661};
static const float stdev[NUM_FEATURES] = {0.8548696,1.17093348,1.71561933,1.98237764,2.04584038,2.01169268,2.09858536,2.40373574,2.36986726,2.38115454,2.25443126,2.22830852,2.27256506,2.27316531,2.14825579,2.05296687,2.03885736,2.01348876,1.95969836,2.00085477,1.98149018,2.0074479,2.03429125,2.00754406,2.03094435,2.04648644,2.01128954,2.04904712,2.06214402,2.13234782,2.12346537,2.06254263,2.00801851,2.04049009,2.04626791,2.01905868,1.99746622,1.97945053,2.0764489,4.44799411,5.29112224,5.29182362,5.29898885,2.66065892,1.97573263,1.98314663,1.97829134,1.94101068,1.97761146,1.97512445,2.0169493,1.94968471,1.97028127,1.97333422,1.95727973,1.9674956,1.97122644,1.93596939,1.99415049,1.95460703,1.94866501,1.93999257,1.967717,1.92474908,1.97272244,1.92982105,1.98879677,1.94334099,1.05523005,1.18600488,2.0051807,2.02712254,1.96277068,1.95078232,1.93951966,1.97559526,1.94537121,1.94715202,1.95920323,1.97395898,1.95701509,1.96852585,1.95117391,1.96457416,1.98538021,1.98693732,1.98535661,2.00411334,1.99885805,1.93258346,1.97868327,1.97527311,1.97399405,1.96413382,1.96516478,1.97608999,1.9244039,1.94783259,1.9479339,1.955868,1.92646748,1.94563977,1.83972255,1.95075162,1.95163778,1.95745749,1.96092625,1.95805776,1.97425395,1.98733197,1.94496443,1.98670861,1.98754735,1.97046646,1.96439008,1.97495573,1.97156618,1.95954978,1.97794618,1.93729558,1.96845748,1.96465188,1.97621354,1.9246545,1.87771298,1.97644361,0.86515809,1.22305122,1.72762367,1.93402605,2.00388747,2.01224278,2.03975793,2.08125515,2.09146665,2.1283703,2.1145897,2.07441179,2.07891719,2.07559469,2.01574752,2.01156865,2.00061699,1.9573961,1.9793985,1.98069505,1.96143192,1.9804209,1.98405405,1.96003113,1.96156137,1.97808899,1.98921536,1.98200511,2.00219654,1.97771449,1.98201278,1.99547882,1.96827526,1.94716967,1.96444052,1.96431566,1.97412897,1.9672234,1.98131656,1.9973226,4.75464648,4.92373221,3.75027256,1.9934464,1.96485386,1.95221441,1.95197311,1.98598631,1.98449386,1.97461052,1.96409639,1.93510673,1.96318398,1.98436571,1.97507544,1.98547611,1.96451427,1.96864391,1.95187592,1.96458335,1.95906308,1.98429688,1.99452982,1.95279516,1.94556182,1.97399551,1.9800293,1.96105851,1.12515408,1.27683277,1.97701528,2.00888283,1.98614624,1.97180505,1.96615328,1.97227911,1.97935921,1.95636881,1.99711487,1.97092284,1.95290457,1.96341388,1.97130762,1.95165643,1.95645821,1.98172889,1.95711738,1.96264186,1.96176342,1.94010224,1.97350901,1.95195659,1.95824216,1.99540175,2.0061676,1.98799549,1.95250245,1.93186443,1.92654128,1.96045554,1.95491931,1.96871535,1.74967184,1.96204762,1.99284667,1.99603746,1.95660009,1.96190094,1.98950217,1.98105602,1.9594882,1.94820717,1.95663325,1.9506941,1.97800628,1.9807043,1.96179747,1.98162649,1.9400623,1.98537325,1.98356833,1.98407553,1.98556206,1.88508376,1.839455,1.99093931,0.81609979,1.118795,1.63656485,1.93521476,1.99268012,2.03420928,2.07072631,2.29716777,2.22259065,2.26608491,2.22098171,2.17898807,2.19253795,2.15036941,2.03402644,2.03135446,2.03879634,2.0048755,1.97899984,1.95233236,1.96398503,2.00180275,1.98721681,1.96329667,1.96105187,1.97904747,2.02436213,2.01625044,2.01603569,2.05093082,2.05813979,1.96821934,2.01645366,1.9896868,1.98348255,1.97341585,1.97519561,1.94364907,1.9620922,1.94963014,4.49588493,5.08382342,2.90485978,1.95830436,1.97937354,1.96009646,1.97028808,1.95657567,1.99464945,1.96569446,1.98667701,1.96267598,1.98408908,1.9735299,1.97236356,1.9761357,1.9522028,1.94405876,1.95167244,1.98041151,1.96704271,1.96106635,1.9492073,1.95711987,1.94668761,1.96711979,1.97823844,1.97493199,1.57318828,1.67798004,2.00699177,2.00033199,1.99032069,1.95721054,1.97275609,1.98928481,1.98151588,1.96859109,1.97813914,2.00109412,1.95587466,1.96309077,1.99836045,1.96559361,1.96961145,1.95961438,1.98187824,1.96426928,1.9796144,1.98034369,1.97318263,1.9536451,1.93997811,1.98168223,1.96123698,1.96768135,1.9691302,1.95005858,1.97348746,1.97657882,1.96617748,1.94944442,1.95123253,1.99506024,1.98187243,1.97643046,1.96977619,1.96498651,1.96730784,1.98199212,1.97200904,1.94572237,1.96324877,2.00826976,1.95237126,1.96326053,1.97121141,1.98192006,1.96963805,1.95229468,1.96794432,1.98121162,1.93516922,1.8835533,1.80109254,1.97019311,0.90451002,1.29245112,1.80138978,1.97202705,2.0059054,1.98870441,2.01845209,2.12108823,2.09030633,2.10059351,2.11148529,2.04006295,2.046866,2.03031014,2.03597416,1.99809943,2.0140109,1.97990517,1.96227927,1.99120706,1.98836775,1.96366598,2.00003614,1.97211813,1.98632003,1.97736581,1.99276897,1.98949328,1.99411104,1.9988481,2.04496597,1.98381289,1.97253703,1.98142687,1.96364046,1.96904905,1.98156446,1.97242171,1.96323474,1.98907473,3.65037451,4.13622897,2.46110572,1.96310304,1.96079317,1.95239228,1.9672262,1.94759371,1.99795376,1.97977541,1.96768435,1.94950358,1.97207125,1.97939582,1.9880871,1.96097732,1.94720084,1.98666273,1.95149141,1.95191669,1.97096533,1.99230031,1.97471612,1.92201032,1.92813563,1.96987713,1.98446851,1.9951659,1.42825239,1.58498504,2.01233227,1.99604537,1.99487996,1.95508939,1.96447508,1.95960093,1.98165349,1.95720696,1.95165972,1.94929489,1.95067835,1.97207714,1.96942113,1.95096229,1.99008642,1.98360485,1.98773076,1.9635832,1.93454968,1.97787152,1.98698296,1.95813314,1.96427354,1.94964801,1.98933192,1.98473973,1.92825515,1.93702814,1.97549631,1.93134447,1.96986486,1.95782849,1.93006379,1.9624467,1.95790078,1.98116357,1.97513761,1.98445276,1.98748848,1.99438106,1.96958713,1.95026789,1.93972464,1.96138966,1.98854652,1.98225513,1.97427327,1.94736713,1.98650977,1.95650039,1.96851905,1.97767997,1.97054899,1.89377515,1.70508638,1.96771511,0.81196278,1.0954191,1.68051468,1.94161717,2.01923805,2.01925842,2.08373157,2.34621734,2.2090455,2.20040025,2.16829,2.11824302,2.12579124,2.11857256,2.06602612,2.00433163,2.00056443,1.98677444,1.98642907,1.98653618,1.96213584,1.98474766,2.01440314,2.00752424,1.98004025,1.98949924,1.98822832,1.99356823,2.02662633,2.01564628,2.00351662,1.98969847,1.96234384,2.01369468,2.00157039,1.97657318,1.95541363,1.92728795,1.95590486,1.98330705,3.52810787,4.03430577,2.32325342,1.96418577,1.96923103,1.98394662,1.95590583,1.98413146,1.97633312,1.98181006,1.9701602,1.95200627,1.9838495,1.94772121,1.97828366,1.98779238,1.95525831,1.98003284,1.95983638,1.94971414,1.96949422,1.98178712,1.9506517,1.94415676,1.9400376,1.96839056,1.96800261,1.98166601,1.71446391,1.80510599,1.96122025,1.95799738,1.96547802,1.94490998,1.97284722,1.94815969,1.9685573,1.97947057,1.98502214,1.97189758,1.98837589,1.98261355,1.94428734,1.98038403,1.94540687,1.96971812,1.97447209,1.97597679,1.97073293,1.95606598,1.96511239,1.98688553,1.98025023,1.97121326,1.94917902,1.95446598,1.91654054,1.93086002,1.98607457,1.97049816,1.96173125,1.940064,1.9701284,1.94104013,1.97286183,1.97272672,1.96920793,1.96101887,1.96539648,1.94702588,1.95668422,1.97183833,1.93584227,1.95082861,1.96137974,1.95346005,1.9689772,1.98765169,1.94514925,1.96883256,1.96490793,1.99823045,1.99060187,1.89601856,1.81546116,1.96500469,0.80502366,1.01005907,1.59664025,1.96942833,2.04472699,2.13441544,2.24300558,3.07061229,2.75199173,2.52360132,2.40058547,2.30860165,2.41045567,2.3422292,2.19073096,2.10938203,2.09369218,2.06912826,2.03191837,2.02023735,1.97715816,1.99393952,2.00772379,1.98547951,2.03997713,2.0292762,2.07367592,2.05445424,2.09953102,2.12466291,2.09316427,2.06465804,2.05141066,2.05450278,2.05417115,2.07101199,1.98996325,1.95935329,1.92938059,2.04604505,6.30833181,6.94993152,4.29367366,1.97048775,1.95110956,1.99874995,1.94400224,1.99209308,1.96076878,1.98775246,1.98913361,1.94834251,1.99060602,1.95480573,1.98464227,1.97842211,1.98227845,1.95975518,1.96835532,1.96712178,1.97698912,1.94167693,1.9684796,1.9883536,1.94670315,1.97534276,1.99961548,1.98815558,1.30886346,1.49660856,1.9463349,1.9929037,1.9457694,2.00023804,1.9995518,1.96031017,1.98193617,1.98345564,1.99020222,1.97241123,1.95053233,1.97726783,1.9462645,1.9363041,1.95951701,1.9712397,1.97704369,1.98260768,1.98344189,1.97087883,1.93651286,1.95879176,1.95711437,2.00228017,1.96479165,1.93354358,1.93538745,1.95312933,1.97342343,1.9439435,1.95466969,1.9798125,1.94970864,1.97058838,1.97814277,1.96024144,1.96671727,1.97792379,1.98241375,1.96419452,1.96581524,1.94461271,1.94248929,1.93380234,1.97704718,1.97243537,1.97516798,1.98411741,1.98342382,1.95832779,1.95620589,1.94506693,1.99920724,1.91893157,1.84280427,1.9438966};
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_ANN_756_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_float data_in_1[AI_ANN_756_IN_1_SIZE];
ai_float* data_ins[AI_ANN_756_IN_NUM] = {
data_in_1
};
#else
ai_float* data_ins[AI_ANN_756_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_ANN_756_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_float data_out_1[AI_ANN_756_OUT_1_SIZE];
ai_float* data_outs[AI_ANN_756_OUT_NUM] = {
data_out_1
};
#else
ai_float* data_outs[AI_ANN_756_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_ANN_756_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle ann_756 = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  //do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_ann_756_create_and_init(&ann_756, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_ann_756_create_and_init");
    return -1;
  }

  ai_input = ai_ann_756_inputs_get(ann_756, NULL);
  ai_output = ai_ann_756_outputs_get(ann_756, NULL);

#if defined(AI_ANN_756_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_ANN_756_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_756_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_ANN_756_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_ANN_756_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_ANN_756_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_ann_756_run(ann_756, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_ann_756_get_error(ann_756),
        "ai_ann_756_run");
    return -1;
  }

  return 0;
}

// standardize and load values into data_in_1, which is pointed to by ai_input struct
int acquire_and_process_data(ai_float data[AI_ANN_756_IN_1_SIZE], float mag_buffer[6][256]) {

	int total_iters = 0;
	float std_val   = 0.0;
    for (int idx = 0; idx < 6; idx++) {

    	// Skip first two values in FFT data
    	// Are below 20k and add noise (not in training dataset)
        for (int j = 0; j < 126; j++) {

            data[total_iters] = (mag_buffer[idx][j + 2] - mean[total_iters]) / stdev[total_iters];
            total_iters++;
        }
    }

    return 0;
}

int post_process(ai_float data[AI_ANN_756_OUT_1_SIZE])
{

      int8_t   prev_region, curr_region;
      // For testing
      float max_val;

      // process the predictions
      for (int idx = 0; idx < AI_ANN_756_OUT_1_SIZE; idx++) {

    	  // For testing
          //predicted_region[idx] = data[idx];
    	  //printf("data[%d] = %f\r\n\n", idx, data[idx]);
    	  // find largest output value
    	  if(max_val < data[idx]) curr_region = idx + 1;

          //if (data[idx] == 1.0) {
        	  //curr_region = idx + 1;
      	  //}
      }


      prev_region = IPCGetPredictedRegion();

      // Update IPC if predicted region has changed
      if( prev_region != curr_region) IPCSetPredictedRegion(curr_region);

      return 0;
}


/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{

  printf("\r\nMX_X_CUBE_AI_Init\r\n");

  ai_boostrap(data_activations0);
  printf("ann_756 returns  %d\r\n\n", ((uint8_t*) ann_756)[0]);

}

void MX_X_CUBE_AI_Process(float mag_buffer[6][256])
{

  int res = -1;

  printf("\nMX_X_CUBE_AI_Process\r\n\n");

  //printf("ann_756 %d\r\n", ((uint8_t*) ann_756)[0]);
  if (ann_756)
  {

    /* 1 - acquire and pre-process input data */
    res = acquire_and_process_data(data_in_1,mag_buffer);

    /* 2 - process the data - call inference engine */
    if (res == 0 ) res = ai_run();

    /* 3- post-process the predictions */
    if (res == 0) res = post_process(data_out_1);

  }

  if (res) {
    ai_error err = {AI_ERROR_INVALID_STATE, AI_ERROR_CODE_NETWORK};
    ai_log_err(err, "Process has FAILED");
  }
}
#ifdef __cplusplus
}
#endif
