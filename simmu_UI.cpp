// generated by Fast Light User Interface Designer (fluid) version 1.0103

#include "simmu_UI.h"
#include <stdio.h>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Ask.H>
#include <FL/Fl_Help_Dialog.H>
#include "Building.h"
#include "Utils.h"
class Game;
class smu_UI;
#include "Game.h"

inline void smu_UI::cb_newItem_i(Fl_Menu_*, void*) {
  newGame();
}
void smu_UI::cb_newItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_newItem_i(o,v);
}

inline void smu_UI::cb_loadItem_i(Fl_Menu_*, void*) {
  loadGame();
}
void smu_UI::cb_loadItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_loadItem_i(o,v);
}

inline void smu_UI::cb_saveItem_i(Fl_Menu_*, void*) {
  saveGame();
}
void smu_UI::cb_saveItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_saveItem_i(o,v);
}

inline void smu_UI::cb_quitItem_i(Fl_Menu_*, void*) {
  hide();
}
void smu_UI::cb_quitItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_quitItem_i(o,v);
}

inline void smu_UI::cb_budgetItem_i(Fl_Menu_*, void*) {
  budget();
}
void smu_UI::cb_budgetItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_budgetItem_i(o,v);
}

inline void smu_UI::cb_helpItem_i(Fl_Menu_*, void*) {
  help();
}
void smu_UI::cb_helpItem(Fl_Menu_* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_helpItem_i(o,v);
}

Fl_Menu_Item smu_UI::menu_mainMenu[] = {
 {"File", 0,  0, 0, 64, 0, 0, 14, 56},
 {"New Game", 0x8006e,  (Fl_Callback*)smu_UI::cb_newItem, 0, 0, 0, 1, 14, 56},
 {"Load Game", 0x8006c,  (Fl_Callback*)smu_UI::cb_loadItem, 0, 0, 0, 0, 14, 56},
 {"Save Game", 0x80073,  (Fl_Callback*)smu_UI::cb_saveItem, 0, 0, 0, 0, 14, 56},
 {"Quit Game", 0x80071,  (Fl_Callback*)smu_UI::cb_quitItem, 0, 0, 0, 1, 14, 56},
 {0},
 {"Budget", 0x80062,  (Fl_Callback*)smu_UI::cb_budgetItem, 0, 0, 0, 0, 14, 56},
 {"Help", 0x80062,  (Fl_Callback*)smu_UI::cb_helpItem, 0, 0, 0, 0, 14, 56},
 {0}
};
Fl_Menu_Item* smu_UI::fileSub = smu_UI::menu_mainMenu + 0;
Fl_Menu_Item* smu_UI::newItem = smu_UI::menu_mainMenu + 1;
Fl_Menu_Item* smu_UI::loadItem = smu_UI::menu_mainMenu + 2;
Fl_Menu_Item* smu_UI::saveItem = smu_UI::menu_mainMenu + 3;
Fl_Menu_Item* smu_UI::quitItem = smu_UI::menu_mainMenu + 4;
Fl_Menu_Item* smu_UI::budgetItem = smu_UI::menu_mainMenu + 6;
Fl_Menu_Item* smu_UI::helpItem = smu_UI::menu_mainMenu + 7;

#include <FL/Fl_Pixmap.H>
static const char *idata_title[] = {
"199 39 -128 1",
"!\224w6\"\364\324\217#jT&$\234\233\242%\313\311\333&\257\215Z\'\371\346\261(\
\243\242\253)\323\321\345*\304\302\323+\225\224\232,\304\304\307-\t\6\b.\363\
\331\250/\360\310T0\253\253\263""1\372\354\305""2\316\275\251""3;-\23""43/15B6\
\33""6\360\262J7\323\322\336""8\323\230\'9\212\210\221:\205\204\214;\276\275\
\315<\370\327|=UT[>\332\250O?\333\331\355@wv|A\263\262\271""B\274\272\313""C\
\276\275\301""DedkEFDJF\256\207<G\315\251tH\351\266pI\326\324\350J\273\272\
\276K\231\231\240L\371\340\226M\256\236\215N\277\251\214O\333\312\257P\253\
\252\257Q\330\326\352R\320\317\341S(\30\16T\245\244\257U\255\254\267V\365\323`\
W\236\236\245X\370\360\342Y\222\221\230Z\320\317\333[\363\306y\\\257\257\262][\
Y`^\264\263\304_|z\201`v]Fa\367\313""abjioc\355\307gd\310\307\330""e\241\240\
\247""f\276\233""Eg\216\215\225h\236\235\253iKJNj\312\311\314k\356\334\277l$\
\31 m\316\314\336n\335\333\357o\337\307\232p\332\331\343q\201\177\206r\250\
\247\261s\224\223\241t\227\226\235u\201""d-vQOTwJ<5x\267\266\300y\353\305\206z\
\231\207{{\307\306\322|\260\257\267}\242\223}~ZC$\177\272\255\245\200\340\336\
\357\201\270\267\272\202\306\305\326\203\231\227\246\204\272\263\261\205\276\
\240p\206<9<\207\230\220\217\210\325\275{\211\26\20\24\212\247\246\254\213\
\301\270\244\214_^e\215_QK\216\362\320q\217\271\267\310\220pow\221\261\260\
\300\222""A?C\223\240\231\227\224\301\277\320\225,%%\226\326\325\340\227\251\
\250\270\230\350\276O\231\301\300\303\232\304\275\265\233\342\321x\234\337\
\324\304\235\260\247\234\236\213u\\\237\256\255\275\240MVT",
"PJ\231\231\231\231\231\231\231,,\231""CCCJJ\201""A0P\212\212\212\212\212\212\
\212\212\212\\\201""CCCCCCCCCCCCCCCCC\231,jj,,,,,,,,jj,\231\231\231""CCC\201\\\
\\\\\\\\\\\\\\\\\\\\\201""C\231\231\231\231\231""CCCCJJJJCCC,jj,\231\231\231\
\231\231""C\201JCCC\231\231\231""CCCJJJJJJJ\201\201""C\231\231\231\231\231\
\231\231,,\231""CCCJJ\201""A\\P\212\212\212\212t++++K\212\\\\\\\\\\\\\\JCCCCCC\
CCC\231,jj,,,,,,,,jj,\231\231\231""CAt",
";CCCCCC\231\231\231\231\231""CCJJJ\201\201JJJJJJJJJJJ\231,,\231""CCCCCCCCCCCC\
C\231,jjjjjjjjjjjjjj,,,,,\231\231,ZZZZZZZZZZ7\226p\226\226\226\226\226\226\
\226\226\226\226\226\226""777\226ppp\226\226\226\226\226\226\226ZZ777ZZ%{{{{{{\
{{{{dZ7\226\226\226\226\226\226\226\226\226\226\226""7777ZZZ7777ZZZjZjZ\226""7\
ZZZZZj\231""CCCCCCC\231,jjjjjjjjjjjjjj,\231,,Jeq",
"ZJ\\PPPP000\\\\\\\\\\PP\212P0\\\\\\\\\\\\\\\\\\AJC\201""AAA\\\\\\PPPPP0\\AJ\
\231\231\231J\201\201\201\201\201JJJ\201""A\\\\\\AAA\201\201,pp\226\226\226""7\
7777ppp\226""7777\226\226\226pppppppppp\226""7\226\226\226\226\226\226RZ77Rm%d\
*;;BBBBBB\202m77\226\226\226""7\226""77\226\226\226\226\226\226""77777\226""7\
\226\226\226\226\226""77\226ppp\226\226\226\226""7Z|PPPPP0\\\201""C\231\231""C\
\201""AA\201\201JJJ\201""AA\\\\|Ae:@",
"7AWYYYYYY+++K$$t+YY+++++t+t+KePPe$WWeeWW$Ktt$e\212PP(WKtttttKK+gY++++ttK$|%ZZ\
ZZm%%d%mmd*****\202\202""dd%mZR777Zd***\202""dd\202*B\217*\224""B\217\217""BBB\
B\217\217\217\217\217\217\202%%d\202\202\202\202""dddddd%%%%d**\202""dddddd\
\202\202""d%77m%%%%%*eK++Y+$(PP\212WKt+ttttt+gY++++tqbb",
"7AWYYYYY++ttKK$$t+++++++ttttWPPeKtK$We((\212\212((\212P\212(WKtttttttttY9Y+++\
++++tr\202""d%%mZZZRZZ%\202******\202\202""dd%%%mZ%d\202\224\224""B^r\203g\
\203\227""B%%d**d%%%%%%%%%mRm%ddddddddd%%%mm%dd\202""dddddddd%Z7Zd\202""dd%%{\
\212((ee(\212\212(WK++++++ttt+9g+ttttqDD",
"7AWYYYYYXk...[$$$Mt++Y\231\204""e\223\223\223""2\'.[>t1XX111\'1\'\210\212(W$t\
tKKKK\232\204""ee\223\223""e+_\214""e,Je\223\223K$\220-\202\202""d%mZmd\202*\
\201\201$$$$+9\236u%111\'111\'11\'\205Yg11\'111\'\'\'\'kO\177\235\223\223@\
\225RR%\232\232""2k1\'\'\'\'111\'\'\'\'\"Fd\202\202""dd\202""dddm\201\204O\'\'\
L<\202\202\224""e$e((eeg\231\201\235\235""2k\'\'\'LfK+9\234j\212t$\213\210!D",
"ZAWYYYYXXy5~8[H\":ut$$$\211S}\223\207s\177H333tK!\233""111\'.\210w$KKtKKKKKK\
\223\204\223\223\207""94---t-l\207\223\207YY\225-\202*\202\202\202""d*;**q\
\201YYY:l-\211S\221rF/\'\'\'\'LV555B%L1\'LLV\230\230/\".O2M\207:\211-RRm\236\
\213N\210<\216VV<L11\'\'\'.f3%m%%%%%d\231\231""C9\236HL\'<\"\";$+tKttt+--E\
\223\177\234k\216#55K+9#\225""E+D333D",
"ZAWYYY\234Xw\206""5@33!.y3KP0P0-\211S\211\211""433tttKK~\236y</>!3YtKKKK$$$$\
\213zSSS\211--tttt-\211S\211\211\211\211-\202\202\202\202**B^\224*_\220\211ll\
\211--\217\237hgq~!\230""aV!55*\202m7</55553355!>F~S\211--7Rm~3S\225""555555Fc\
c\230\230!33R777)77J\231""e--\211S35/<HHH+++YgY+++--~\205""f35KKKY9gt---S_DD",
"RAWYY\207\201`49:q_@3#uS\212PP0\\\\SS-\211SSKKKKK$$\205\"<c>uS\211tKKKK$WW1kM\
5SS--+ttttt\211l\211\211\211\211--*\202\202\202\202\224\221;_+Dll\225\211-;B^\
\221\237\237\\fVVV#5\202\202%R)V555\202\224\224\224%Z<\"\205u3--R)Rm~-\211\
\225""d\202\202*\224\217L</\230>3377)))\226\226\201Jq---\202""d\202""3#f>H68+t\
+gg+++\211""4w\236#33$$KY9Yt\211l-\211qDb",
"RAWYY\207_\211\225ggYYt$~33PeWWe(3w\211\211\211S$KKKKK$\"\"<cF#--+KtKK$WW11\
\205#3S--+tttttlwl\211\211l--*\202\202\202\202*\221\217""D_4ll\225\211-\224\
\224\224*d%%/<VV#5\202%mRR\230""3\217\227\203g99gL\'LH&5\211-R)Rm5-%%%dd\202*\
\'1LV\230!33\226RmmmmAJg\211--\202\202\202\202\202~u866Fut+gg+++\225w3`~3KKKKg\
9YK4--Sqbb",
"ZAWY_+w-YYYYtePA~3W$$$$$w\215\211\211\211SKK$KK$$\".[H!3--+tt+Yg9q11\210""F#3\
--YKtttt4i\211\211\211\211\211-*****\224\237^_\220\211\211ll\211-***\202""d%%V\
<VV#5%mRRmF3\217\227h\203sss\'\'\216[GS\211m))RmS-%%%%dd\202""11L\216>53\226Rm\
mmm\223Pg4--*d\202\202\202*,!8668uKtg9YYY4E\225#53@@@@@qYK4--tqb\220",
"RAWY]@4\211-YYtW\212\\P#3$$$$$$\206v\211l\211S$$$$$$$\"y&FuSSSSKt+g:@\'\'\"GG\
!5--+Ktt++\225l\211\211\211\211\211--sss\203$h@:\225\211\211ll--**\202\202""d%\
%V<VV#5RRRmd~*\224\224*\202\202\202L\'\"\230""a!\225SZ))Rm-mmm%%%d\'1\'<\216!5\
5Rmmmmm\207\207""4\211--\202""d\202****FF>66!#tg9YYg4iS~53\214\214\214\214\
\220:YK\206--+_\214]",
"ZAWY\206]\225\211-+tW\212\212(W$3WWWW$W\206vll\211\211$$$KKKK\"`3#~S\211\211\
\211tt+Yg9\"f5!Hf#\211-Kttt+Yl--\211\211\211\211--q9Yh\227^]\211-\211\211\211l\
\211-*\202\202""dd%%/<VV#5I))md5\202""d%RRRRLL\230""6>53RR))Rm-mmmmm%%L\'\"<\
\210""55mmRRmmM\223\214\211\211--dd\202\202**\224\224""FFF88#q_qgYg4l\211SS3qq\
q:Y$$K\206--t@=i",
"ZAWY4]\225l\211\211W((WKK$3eeWWWW\206vl\211-\211W$$KKKt\"3_u3---\211+KKttK\'5\
Wfa>!S-$ttt+Yl-:\211\211----\202%mZZZq-*\211\211ll\211-\202\202\202""ddmR/\
\216>F55)))RR%%%%mRRRLL\230\230u33R)))RmRmmmmmmm\'\'\216<\236""55mRRRRmM\215-\
\211--d%dd\202**\224;>~3u8u3D@9YY\225---S3$$$$(T$t\206--t@]=",
"ZAeY\211ll\225""4\211-e$t+Y+Yg99::9\206\215\211--\211""eW$$$Kt\"5:#\211--:SK$\
$K$L\'5e\216<\230""f3\211$ttt++\206-$\211---7\211\226\226""77Z@:-*l\222\211l\
\211-\202""dddmR)/<!555RR)))RmmmmRRo.\216/>33)))II)RRRmmmmR\'\'\"\216\210""55d\
\202*\224""B^o&-----%%%d\202**\224""BG#q86#S@:YYY\225-t-$3$$$W(($K4--t_Db",
"7x\212t\211-\211""4\225\225\225i\215+Yg9_\220""bDDD@4\225--e\211""eeWW$KKL3K~\
\211$le`3$$$WL~5Wc\216>!\225S$K$KK$i-r--Z\211""7=-%d\202\202]--\224\225i\211\
\211--dd%mR)7//55m5RRR))))RRRR)Mffa!33))IQQIIIII))))\'\216>c!55*\217\227\203g9\
y`Y-\217--%%%%d\202*\224;&HYL<5S+KK++\206-t\211K3$$$W((WK4--W9@_",
"\226""CPWWllllllll~+g9q__@@:t\225\211--e\211(eeeW$$L5WW~(Y\215SSWWWWL5eW\230\
\230#53SWWWee(i-Px\211""dgE\211-****q-*Bl\211----d%mR)7R/#55m5RRR))II))))}M)Gc\
33))IQ?\?QQQQQQQQ\'\'I<\216""55d*B\221\227(hyG;Sml-m%%%dd**\224~\205kk\210""3\
\211K$$t+E-KSK#$$$WT\212""eW\206--\212t_q",
"7J\212$W\225l\211\211\225l--\225\236sY+KKKeP|4-e-(S((((eWWL3he`\206l-T5eWWL\'\
3eefu5503e((((ei-eU\206""4\211-*\211***@:-\202""B\211\211--\202-%mRRRmm/5%5muR\
))))IIQI))zS5&!33)IQ?\?QIIIIIQQQ.a/\216""F55%\202**d%%H\234!SRv-mm%%%dd***#NN\
\236S-tK$ttE-KS$#$$WTPr((w--\212g\220\220",
"ZAe+t\211\211\211ll\211-tS@N\"KWWePAU\222-e\211(S(TT(((eL3((5-(l\212\236#eW\"\
55eef\212#3A3(eeWW$E-+e\211-U\211\227v-rr]--\237\217\211""d--d-mRRmm%%c~%F%#))\
RRmmR)II2\215\226\211""3S3IIQ?n?I))IIIIIO[I!!33m%%%%RRR>o#\211mi-mm%%%%d\202**\
3\236~3--tK$Kt\222-$SK#$eP|A0((w--e:DD",
"ZAe+++-\211ll--\225t\225\215&uWW(UU\212""E-e\225\212STT\212TT((\"3(((\211Tg~~\
5((.5e(\212""cA\230~\\#(eW$KtE-ggY\211q9E\211-__9-:\203^\225%l-%\211mRmm%%%c#d\
/*#x\227(hhhhh\237;O5?wnS3n\200\200\200?QIIIII)))OFIaI33Rmm%mRRR>Hw\211%i-mmm%\
%%ddd*\225\215l---tK$Kt\206-KS$#(0AA|r(ew--WqD\214",
"ZAe++tt---\211""e\207q\211K``$er0rev-(w\212\211\212TTTT(T<5(((\206\206\211-\
\212&(1\'3TrU<A\233""F(u((W$KKE-gY\203\206\206\211-g\206Y\231Y-\221\202""dv%]\
\211m\211mm%%%%%\216""Fd\216\224#Tsg99999\203kon~\215S\211\200\200\200\200nQQI\
IIIIII\213oI/\"H3I))mmmRR)HH3\211%v-mmm%%%ddd\202""4v\211\211--tK$$K\206-KSe~|\
A|P((((w--WqD\214",
"RAe++ttt---bq\211\211""4W&\215\212Pr($]=K\206YS99::99+<5(TT\211-T\225rOkk33UA\
A\"0.\"eu(((W$KE-Yhx\211-B4B\201\201(--Z7m\220""dg=m\211%%d%%%%<<d\216*#;BB\
\217\217\217\217%Q1\210n#?--?\?\?\?I)IIIIIIIIO\210I/I!3QQI))RR)I[#3S{\215-B\
\221\227\227TTTr\237;E=\211\211--ttK$K\206\211WSP~\\P(eee(T~--W:DD",
"ZAe++tttK$--\211\211T@\236\205\236rr(W$v(4l@SbbDDDbq\216""3TTTT\225T\201\232""\
22!3|A|U\'T1\'/~(((eW\203""E-t(B;\225\224\201\201""Ag\211-77md+d\201Yl-%%%%%%%\
<\'a\230""dum)IIIIQ\200""11F##Q--QQQ)%RIQQIIII\207\232!u\230Q#3IQQQI))II[#d5*_\
-\203""9:qq__qY\237""bl----ttK$KE\211\212""bP#(eWWee((\215--e:DD",
"RAe+++tt$$$---]v\211(H~Te$$Eq\225l9S:::::9$[3|||U=P\204\207`u~3|UrT.11.F5((((\
(WE-KTBBv\212\\g=4--7%d\202q\201P_\211-%m%%%%%VLa\230%!R))II?\200\200""1\'Q!Q`\
-QQQQ)mRQQQIIII\235NQ!Q<5QIIQQQIIII\"ydO*\235-\237\227TT(hh(\221@\220-----We((\
e\240\214r\223(#WWWeee((\215\211-\212:bD",
"RAeYp5tt$WWWW-\211--zN4(WWW\222]\225""4\211\211TTrrr|x\216""3xxxJ\211\225i5S~\
S30rTT[.\"c#5(((T\212(\222-KTBB\211\211\222""4\211\211--%\202\202\202vq]4--mmm\
m%%mV<a\216V~R)II?\200\200""11\'cc?5\211?\?Q))))QQQQIIz\204}G\216Qf3QQIIQQQQI)\
[.\"k\234\236-\202%%%%%%mRvb\\\211P--\\\\|\\PiW@\223\236""3WWWe((((`\211-0gbb",
"ZAeY23+t$WeWWW\211-(z`3WWWW\206]\225""4\211-rrrUAC\231\216""3|AAxxS\225SSSS3T\
TTT\216yH\230#5((T(T\212w-$rBB;\211\211\211\211---*\202\202\202\206v\211l\211-\
mmmmmmmV</\216""F5R)I?n\200?11c!ffS?\?QQ))?QIQQQII\207Mu`f>3QQQIIIII)))>>c\"o5\
-%m%m%%R7\226\222""9bgb--PP0P(\222@vD5SWWee(((T\236l-0Y\220""b",
"ZAeYM\215YYYg9:::\211lq\207""3S$Wee4\215lS--rrUxCCx\216""3rrrr\227Slll\211\
\211TTTTT\216y>\230#3\212\212T((\212w-erBB;\211\211\211\211--***\202\202\206vl\
l--mmRRRmma\216//#5)I?nn?\'1.f!?3\225?\?Q))?\?\?1/QQIMM\236#uZ33*B\217^\221\
\221\221\237""1c%m!f\230>5\211%%%mmR\226\226""7v_vD\211-K$$WWKl\225-\211""33WW\
eee(TT\236\225-0Y@\220",
"ZAWYYOw9q@bDD\214\214l]w-\211Weee\225\215lS--r|xCJAU\216""300rTrSlll--\212rTT\
(\216y>\230#3rr\212T((\215-e0;\224*\211\211\211\211--***\202""d\206vl\211\211-\
mmRRRRRa\216\230/#5I?\?\?QQ\'\'L\216\230!3?\?\?)RQ?\?n.#?QQGN!F>!3\227\203g9::\
:q:.#dR!F>>!S%%mm7\226\226R%@\220\211\211--+tKKKK\211\211-\211~~3WWWe(\212r\
\236l-rg\220\220",
"ZAeYYkzg:q_____\225w---eee(\225\215lS--|xJx|0\227<30rrrrrll\211--TrTT(\216y>6\
#3$tYg9:\236-Y0*{d%\211\211---**\202\202""d\206vll--mmmRRRRV\216\230\230#5Q?\?\
QI)1\'<<&33?\?)R)?nnn\210""3QQQoof>F53\217\221U\227\227\227TTT[3RRZ!f>>~\211mR\
7I7m%:K\214\211---tKK$$$s\211\211S~~3WWWW$$K\235--g\220]]",
"ZAeYYk.wYtK$$WWv]--\212((e(4\215ll--xxAUrr0<50rTr00l\225\211-((rTTT\216\"\
\230""6#3:@bbDD}\211@e*{{{\211\211--\224**\202\202""d\206vl\211\211-mmmRRR)V\
\216//#5?QI))11\'L<u5?\?)mR?nnnn23)Q..y>>u3RRIQQQQIII.3)RRu#F6!S77)Rm%d+Y4---+\
tK$$$$tl\211l~~3$W$K+9\234\177-bbv\206\222",
"7AeYYok\236tK$$Wee:\214--T(ee(\215\214ll--AU0rr00LF0rr000ll--(eTrTT\"\"/\230u\
3g::q__owtU\224;;;\211\211--\224\224*\202""ddv\214l\211\211-mmmRR))\216</au5QQ\
I))11LL<Gu\237\217\224%Innnn\232~S)Q..\230""66F#)IQQQQQQI163I)RZ3~Ff5S)R%%d\\P\
\214\211--YtKK$$$W\203\211\211S~u#WWWKt1k\211-:qDvD",
"7AeYY\205\210G\205KK$WWAP\211--T\212(((\207@ll\211\211""0rrr00U\'/#rrUUUU\
\211--reTrTT\'\'a\230""f~e((((ek\236\211x;B;;\224\211--;\224*\202""dd9@\211\
\211\211-mmmRRRmL\"//f#QQQQ11\'LL<<<L.O\213\235""eWP\231\177-\200?..[66>>6\
\230\"\"O2\235M2kk3II)RmR3~!u3\211%ddCJq\211---YtKK$$$W$s\211l#F>6HW$11!\211\
\212rrg_+",
"7xe++t`\215\205oM$WC\204\211--(rUPT\223\215\211----3TTTr01\"u5T0UUUU\211-00e(\
rTk\"u5335u((((kk~-ABB;;\224--;;B;\224*Kv-----\211mRRR)\'\216#3355!QQ?\'\210""\
555555!>>!~S\225l\211--n?H8333333u88F`SSu!33QQI))))33~~4]$CCv----g+K$K$$$WWt--\
S!6[[\"11FS\211rrr+gK",
"7x(+++5554}\235\232]---rUx\201""El-------\211S5T[&33355\225UUUU--U0Tew5355533\
333F6!35\225\211--BB;\224--B;\217^4\211----------R#u533333555&u55555555533\
\225\211------nS333333333333S--S333nn?QQII)3S\211--\211\211----\217Yg+KK$$$$WW\
$s-\211""3333u~35S\212rrreYg",
"7A(+++ttKK5\225\211--UAxJJx||A|0rTTT\212rT(eKg9Y$0||UUUUUUUrW(rTTTTT(((((((r|\
0(r\217""BB;\224\224\224""BB\217\221\227T\237""B\224\202*\224;;BB;;;^\217m))))\
IIQ?\?nnn?Qn\200\200\200nnnnnnnn?\?\?)mIQQQQQIQQQ?nnnn\200\200\200n?QQI)RmmS--\
----\227hh9YK$$$$WWWWW++eS333333(\212TrrUrgq",
"drK++ttKWeTP\\A\201JJxA|0rr00rrTTTTTT(WtgY$(rrT(eWhW$$KY$TTTTTT((((((\212UU\
\212WT\217\217""B;\224**\224""BB\217\217\202%d\221hsg999999gh^R))))IIIQ?\?n\
\200nn\200\200\200?)R%\224\217^\221\221\237\237\237\221\221\224I?Q?nnnnn\200\
\200\200\200\200\200\200?QI)I))Rm%%d\202\202\224""B^\227r\227Yg+Ygggggggg9g$eW\
ee(((TTTrrAr:\220",
"\227q\220""b\220@_q9gYtKK+Ygq_@@@@_____@@@@@@\220\220@::\220\214=iEEEEEEEEi\
\214\220_@@@@@@@@@_:9:@\220@:::9ggg9q:9g$h9@D\214]]=====\214_gs\203\203\203\
\203\203\203\203hT\227\237^\224\224;^(\203g:\220\214==vvvvvv]@sT\227\237^;\
\202mR)Rm\202;\221Th\203\203\203\203hh\203sssYgg99:9ssb=iE\222\222\222\222\
\222\222\222\222\222vb\220\220@@@@@@@@_:Yg\220""b",
"^\220=v=]]\214\214\214]]=vviiEEiiiivvvvviiiiiEEiv]=\222""444444444\225""44\
\222vviiiiiiiiiv]]vEEivviE\222\206""444\222=]D\214vvv========]\220""b\214\214\
\214\214]]]]]]=vv=]DD\214]=viEEEE\222\222\222\222\222""E]\220_q::9::q_@\220""b\
D\214]]\214""DDDDDD\214\214]]]====]D\214\222""4\225\225\225\225\225\225\225\
\225\225\225\225\206iiiiiiiiiiiv\214\214\214\214""b",
"rb]]==vvviiiEiiiiEEiiivvvvvvviiiiiii==iEEEEEEEEEEEv\214\220""b\214=viiiiiiv=]\
=iEEEviE\206""44444\206=\214\214]==]\214\214""DDDDD\214\220_\220]\214\214]]]]=\
i\222\206\206\206\206\206\206=\214]]]\214""Dbbbbbbbb\220q9q_@@\220\220""bDDDDD\
D\214]\214""DDDDDDDD\214]]]]==]\214\214=\222\206\206\222\222\222\222\222\222\
\222\222""E=DD]=viiiiiii=\214]vv="
};
static Fl_Pixmap image_title(idata_title);

inline void smu_UI::cb_G_NameInput_i(Fl_Input*, void*) {
  renamePlayer();
}
void smu_UI::cb_G_NameInput(Fl_Input* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_G_NameInput_i(o,v);
}

inline void smu_UI::cb_T_BuildChoice_i(Fl_Choice*, void*) {
  evalBuildPrice();
}
void smu_UI::cb_T_BuildChoice(Fl_Choice* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_T_BuildChoice_i(o,v);
}

inline void smu_UI::cb_T_PlaceButton_i(Fl_Button*, void*) {
  modePlace();
}
void smu_UI::cb_T_PlaceButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->parent()->user_data()))->cb_T_PlaceButton_i(o,v);
}

inline void smu_UI::cb_T_SelectButton_i(Fl_Button*, void*) {
  modeSelect();
}
void smu_UI::cb_T_SelectButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->parent()->user_data()))->cb_T_SelectButton_i(o,v);
}

inline void smu_UI::cb_T_DownButton_i(Fl_Button*, void*) {
  modeGroundDown();
}
void smu_UI::cb_T_DownButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->parent()->user_data()))->cb_T_DownButton_i(o,v);
}

static const char *idata_grnddn[] = {
"20 20 -12 1",
" \377\377\377!\20@\0\"Ph<#0`\4$h|L%\374\370\200&\314\210\b\'\374\234\0(\374\
\260""0)\234`\20*\20\20\20+dd\210",
"        ***         ",
"       *%(\'*        ",
"       *(\'&*        ",
"       *(\'&*        ",
"       *(\'&*        ",
"       *(\'&*        ",
"      **(\')**       ",
"     *\'((\'\'\'&*      ",
"     *&\'\'\'\'\')*      ",
"      *\'\'\'\'&*       ",
"      *&\'\'\')**      ",
"    **!\"\'\'&\"\"!**    ",
"  **!\"#$&\')$#\"\"!**  ",
"**!\"\"$\"\"+&#\"\"\"$$\"!**",
"!\"#\"\"$\"\"#)$\"$#\"$#$\"!",
"**!\"\"$\"\"+\"#\"\"\"$$\"!**",
"  **!\"#$\"$\"$#\"\"!**  ",
"    **!\"#$\"\"\"!**    ",
"      **!\"\"!**      ",
"        ****        "
};
static Fl_Pixmap image_grnddn(idata_grnddn);

inline void smu_UI::cb_T_UpButton_i(Fl_Button*, void*) {
  modeGroundUp();
}
void smu_UI::cb_T_UpButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->parent()->user_data()))->cb_T_UpButton_i(o,v);
}

static const char *idata_grndup[] = {
"20 20 -12 1",
" \377\377\377!\20@\0\"Ph<#0`\4$h|L%\314\210\b&\374\234\0\'\374\260""0(\234`\
\20)\200""D\b*\20\20\20+dd\210",
"         *          ",
"        *\'*         ",
"        *\'*         ",
"       *\'&\'*        ",
"       *\'&&*        ",
"      *\'&&&\'*       ",
"      *\'&&&&*       ",
"     *\'&&&&&\'*      ",
"     *&%&&&%%*      ",
"      **&&(**       ",
"      **\'&%!**      ",
"    **!\"\'&%\"\"!**    ",
"  **!\"#$\'&%$#\"\"!**  ",
"**!\"\"$\"\"&&(\"\"\"$$\"!**",
"!\"#\"\"$\"\"%()\"$#\"$#$\"!",
"**!\"\"$\"\"+\"#\"\"\"$$\"!**",
"  **!\"#$\"$\"$#\"\"!**  ",
"    **!\"#$\"\"\"!**    ",
"      **!\"\"!**      ",
"        ****        "
};
static Fl_Pixmap image_grndup(idata_grndup);

inline void smu_UI::cb_B_NameInput_i(Fl_Input*, void*) {
  renameBuilding();
}
void smu_UI::cb_B_NameInput(Fl_Input* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_B_NameInput_i(o,v);
}

inline void smu_UI::cb_B_UpgradeButton_i(Fl_Button*, void*) {
  upgradeBldg();
}
void smu_UI::cb_B_UpgradeButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_B_UpgradeButton_i(o,v);
}

inline void smu_UI::cb_B_DemolishButton_i(Fl_Button*, void*) {
  demolishBldg();
}
void smu_UI::cb_B_DemolishButton(Fl_Button* o, void* v) {
  ((smu_UI*)(o->parent()->user_data()))->cb_B_DemolishButton_i(o,v);
}

smu_UI::smu_UI() {
  Fl_Window* w;
  { Fl_Window* o = mainWin = new Fl_Window(887, 686, "SimMizzou V1.2");
    w = o;
    o->user_data((void*)(this));
    { Fl_Menu_Bar* o = mainMenu = new Fl_Menu_Bar(0, 0, 160, 35);
      o->menu(menu_mainMenu);
    }
    { Fl_Box* o = toolBox = new Fl_Box(0, 250, 160, 160, "Tools");
      o->box(FL_UP_BOX);
      o->color(50);
      o->labelfont(3);
      o->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
    }
    { Fl_Box* o = schoolBox = new Fl_Box(0, 35, 160, 215, "School Info");
      o->box(FL_UP_BOX);
      o->color(50);
      o->labelfont(3);
      o->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
    }
    { glWindow* o = drawWindow = new glWindow(160, 60, 725, 625);
      o->box(FL_NO_BOX);
      o->color(49);
      o->selection_color(49);
      o->labeltype(FL_NORMAL_LABEL);
      o->labelfont(0);
      o->labelsize(14);
      o->labelcolor(56);
      o->align(FL_ALIGN_CENTER);
      o->when(FL_WHEN_RELEASE);
    }
    { Fl_Box* o = logoBox = new Fl_Box(160, 0, 200, 40);
      o->image(image_title);
    }
    { Fl_Input* o = G_NameInput = new Fl_Input(10, 80, 140, 20, "Your Name");
      o->labelsize(13);
      o->textsize(13);
      o->callback((Fl_Callback*)cb_G_NameInput);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Value_Output* o = G_ApprovalOutput = new Fl_Value_Output(10, 125, 140, 20, "Your Approval: (%)");
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Output* o = G_MoneyOutput = new Fl_Output(10, 170, 140, 20, "Current Budget Surplus:");
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Output* o = G_MonthOutput = new Fl_Output(10, 215, 100, 20, "Date:");
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Value_Output* o = G_YearOutput = new Fl_Value_Output(110, 215, 40, 20);
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_CENTER);
    }
    { Fl_Output* o = O_OpinionOutput = new Fl_Output(160, 40, 655, 20, "Student Opinion");
      o->align(FL_ALIGN_TOP_RIGHT);
    }
    { Fl_Value_Output* o = O_PercentOutput = new Fl_Value_Output(815, 40, 70, 20, "% Agreeing");
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_TOP_RIGHT);
    }
    { Fl_Choice* o = T_BuildChoice = new Fl_Choice(10, 295, 140, 20, "Building Type:");
      o->down_box(FL_BORDER_BOX);
      o->labelsize(13);
      o->textsize(13);
      o->callback((Fl_Callback*)cb_T_BuildChoice);
      o->align(FL_ALIGN_TOP);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Value_Output* o = T_PriceOutput = new Fl_Value_Output(60, 315, 90, 20, "Price $:");
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(13);
      o->textsize(13);
    }
    { Fl_Group* o = modeGroup = new Fl_Group(5, 365, 175, 35);
      { Fl_Button* o = T_PlaceButton = new Fl_Button(5, 365, 45, 30, "Place");
        o->type(102);
        o->callback((Fl_Callback*)cb_T_PlaceButton);
      }
      { Fl_Button* o = T_SelectButton = new Fl_Button(50, 365, 45, 30, "Select");
        o->type(102);
        o->callback((Fl_Callback*)cb_T_SelectButton);
      }
      { Fl_Button* o = T_DownButton = new Fl_Button(95, 365, 30, 30);
        o->type(102);
        o->image(image_grnddn);
        o->callback((Fl_Callback*)cb_T_DownButton);
      }
      { Fl_Button* o = T_UpButton = new Fl_Button(125, 365, 30, 30);
        o->type(102);
        o->image(image_grndup);
        o->callback((Fl_Callback*)cb_T_UpButton);
      }
      o->end();
    }
    { Fl_Box* o = buildingBox = new Fl_Box(0, 410, 160, 275, "Building Info");
      o->box(FL_UP_BOX);
      o->color(50);
      o->labelfont(3);
      o->align(FL_ALIGN_TOP|FL_ALIGN_INSIDE);
    }
    { Fl_Input* o = B_NameInput = new Fl_Input(10, 455, 140, 20, "Building Name");
      o->labelsize(13);
      o->textsize(13);
      o->callback((Fl_Callback*)cb_B_NameInput);
      o->align(FL_ALIGN_TOP_LEFT);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Output* o = B_MonthOutput = new Fl_Output(10, 500, 95, 20, "Date Completed:");
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_TOP_LEFT);
    }
    { Fl_Value_Output* o = B_YearOutput = new Fl_Value_Output(105, 500, 40, 20);
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(13);
      o->textsize(13);
      o->align(FL_ALIGN_CENTER);
    }
    { Fl_Output* o = B_TypeOutput = new Fl_Output(70, 530, 75, 20, "Bldg Type:");
      o->labelsize(11);
      o->textsize(11);
    }
    { Fl_Value_Output* o = B_UpgradeLevelOutput = new Fl_Value_Output(70, 550, 75, 20, "Upgrade Lvl:");
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(11);
      o->textsize(11);
    }
    { Fl_Value_Output* o = B_UpgradePriceOutput = new Fl_Value_Output(70, 570, 75, 20, "Next Lvl $:");
      o->box(FL_DOWN_BOX);
      o->color(7);
      o->labelsize(11);
      o->textsize(11);
    }
    { Fl_Button* o = B_UpgradeButton = new Fl_Button(20, 600, 115, 30, "Upgrade Bulding");
      o->callback((Fl_Callback*)cb_B_UpgradeButton);
    }
    { Fl_Button* o = B_DemolishButton = new Fl_Button(20, 640, 115, 30, "Demolish Bulding");
      o->callback((Fl_Callback*)cb_B_DemolishButton);
    }
    { Fl_Box* o = infoBox = new Fl_Box(360, 0, 525, 20, "SimMizzou V1.2 - By John Loyd & Scott Parker - For CECS361 WS03");
      o->labelsize(15);
      o->align(196|FL_ALIGN_INSIDE);
    }
    { Fl_Box* o = modeBox = new Fl_Box(10, 345, 140, 20, "Cursor Mode");
      o->labelsize(15);
      o->align(192|FL_ALIGN_INSIDE);
    }
    o->end();
  }
  game = new Game(this);
setGameOver();

T_BuildChoice->add(typesTitlesLong[0]);
T_BuildChoice->add(typesTitlesLong[1]);
T_BuildChoice->add(typesTitlesLong[2]);
T_BuildChoice->add(typesTitlesLong[3]);
T_BuildChoice->add(typesTitlesLong[4]);
T_BuildChoice->add(typesTitlesLong[5]);
T_BuildChoice->add(typesTitlesLong[6]);
T_BuildChoice->add(typesTitlesLong[7]);
T_BuildChoice->add(typesTitlesLong[8]);
T_BuildChoice->add(typesTitlesLong[9]);
T_BuildChoice->value(0);
T_SelectButton->setonly();
}

void smu_UI::budget() {
  printf("IMPLEMENT budget() in smu_UI\n");
}

void smu_UI::evalBuildPrice() {
  T_PriceOutput->value( typesPrices[T_BuildChoice->value()]);
}

const char* smu_UI::getName() {
  return G_NameInput->value();
}

void smu_UI::help() {
  Fl_Help_Dialog *hd = new Fl_Help_Dialog();
hd->load("help.html");
hd->show();
}

void smu_UI::loadGame() {
  char *newfile = fl_file_chooser("Load Save SimMizzou Game (*.smu)", "*.smu", NULL );

if(newfile != NULL)
	game->loadGame(newfile);

game->informUI();
saveItem->activate();
G_NameInput->activate();
}

void smu_UI::loadBuilding(Building *bldg) {
  curBuilding = bldg;

if(curBuilding == NULL)
{
	B_NameInput->value("None Selected");
	B_NameInput->deactivate();
	B_MonthOutput->value("NONE");
	B_MonthOutput->deactivate();
	B_YearOutput->deactivate();
	B_TypeOutput->value("NONE");
	B_TypeOutput->deactivate();
	B_UpgradeLevelOutput->deactivate();
	B_UpgradePriceOutput->deactivate();
	B_UpgradeButton->deactivate();
	B_DemolishButton->deactivate();
}
else
{
	B_NameInput->activate();
	B_NameInput->value( bldg->getName() );
	B_MonthOutput->activate();
	B_MonthOutput->value( bldg->getMonth() );
	B_YearOutput->activate();
	B_YearOutput->value( bldg->getYear() );
	B_TypeOutput->activate();
	B_TypeOutput->value( bldg->getTypeShort() );
	B_UpgradeLevelOutput->activate();
	B_UpgradeLevelOutput->value( bldg->getUpgradeLevel() );
	B_UpgradePriceOutput->activate();
	B_UpgradePriceOutput->value( bldg->getUpgradePrice() );
	B_UpgradeButton->activate();
	B_DemolishButton->activate();
}
}

void smu_UI::newGame() {
  game->newGame();
game->informUI();
saveItem->activate();
G_NameInput->activate();
}

void smu_UI::renameBuilding() {
  if(curBuilding != NULL)
	curBuilding->rename( B_NameInput->value() );
}

void smu_UI::renamePlayer() {
  if(game != NULL)
	game->setName( G_NameInput->value() );
}

void smu_UI::saveGame() {
  char *newfile = fl_file_chooser("Save SimMizzou Game (*.smu)", "*.smu", NULL );

if(newfile != NULL)
	game->saveGame(newfile);
}

void smu_UI::setGameApproval(int approval) {
  G_ApprovalOutput->value(approval);
}

void smu_UI::setGameMoney(char* money) {
  G_MoneyOutput->value(money);
}

void smu_UI::setGameMonth(char *month) {
  G_MonthOutput->value(month);
}

void smu_UI::setGameName(char *name) {
  G_NameInput->value(name);
}

void smu_UI::setGameOver() {
  saveItem->deactivate();

G_NameInput->value("None");
G_NameInput->deactivate();
G_ApprovalOutput->value(0);
G_MoneyOutput->value(0);
G_MonthOutput->value(months[0]);
G_YearOutput->value(0);
O_OpinionOutput->value("Please start a new game or load a saved game");
O_PercentOutput->value(100);

loadBuilding(NULL);
}

void smu_UI::setGameYear(int year) {
  G_YearOutput->value(year);
}

void smu_UI::setOpinion(char *opinion) {
  O_OpinionOutput->value( opinion );
}

void smu_UI::setOpinionPercent(int percent) {
  O_PercentOutput->value( percent );
}

void smu_UI::show() {
  mainWin->show();
}

void smu_UI::hide() {
  mainWin->hide();
exit(0);
}

void smu_UI::modePlace() {
  game->setMode(MODE_PLACE);
}

void smu_UI::modeSelect() {
  game->setMode(MODE_SELECT);
}

void smu_UI::modeGroundDown() {
  game->setMode(MODE_GROUND_DOWN);
}

void smu_UI::modeGroundUp() {
  game->setMode(MODE_GROUND_UP);
}

void smu_UI::upgradeBldg() {
  game->upgradeBuilding(curBuilding->getX(), curBuilding->getY());
}

void smu_UI::demolishBldg() {
  game->removeBuilding(curBuilding->getX(), curBuilding->getY());
}
