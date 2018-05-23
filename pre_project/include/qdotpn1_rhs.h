if (ibody==0 && idim ==0 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==0 && iterm==1) {
qdot1[ibody][idim][iterm]=pax/ma;
}
else if (ibody==0 && idim ==0 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==0 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pax*(pax*pax+pay*pay+paz*paz)*pow(CC,-2.)*pow(ma,-3\
.);
}
else if (ibody==0 && idim ==0 && iterm==4) {

o1154=1/ma;
o1155=1/mb;
o1157=-qbx;
o1158=o1157+qax;
o11510=-qby;
o11511=o11510+qay;
o1159=o1158*o1158;
o11512=o11511*o11511;
o11513=-qbz;
o11514=o11513+qaz;
o11515=o11514*o11514;
o11516=o11512+o11515+o1159;
o11517=1./sqrt(o11516);
o1156=-7.*o1154*o1155*pbx;
o11525=-qax;
o11526=o11525+qbx;
o11527=o11526*o11526;
o11528=-qay;
o11529=o11528+qby;
o11530=o11529*o11529;
o11531=-qaz;
o11532=o11531+qbz;
o11533=o11532*o11532;
o11534=o11527+o11530+o11533;
o11535=1./sqrt(o11534);
o1152=pow(ma,-2.);
o1153=12.*o1152*pax;
o11543=1/mc;
o11545=-qcx;
o11546=o11545+qax;
o11548=-qcy;
o11549=o11548+qay;
o11547=o11546*o11546;
o11550=o11549*o11549;
o11551=-qcz;
o11552=o11551+qaz;
o11553=o11552*o11552;
o11554=o11547+o11550+o11553;
o11555=1./sqrt(o11554);
o11544=-7.*o1154*o11543*pcx;
o11563=o11525+qcx;
o11564=o11563*o11563;
o11565=o11528+qcy;
o11566=o11565*o11565;
o11567=o11531+qcz;
o11568=o11567*o11567;
o11569=o11564+o11566+o11568;
o11570=1./sqrt(o11569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o11517*(o1153+o1156-o11517*o1154*o1155*o1\
158*(o11517*o1158*pbx+o11511*o11517*pby+o11514*o11517*pbz))+ma*mb*o11535*(o1156-o\
11526*o11535*o1154*o1155*(o11526*o11535*pbx+o11529*o11535*pby+o11532*o11535*pbz))\
+ma*mc*o11555*(o1153+o11544-o1154*o11543*o11546*o11555*(o11546*o11555*pcx+o11549*\
o11555*pcy+o11552*o11555*pcz))+ma*mc*o11570*(o11544-o1154*o11543*o11563*o11570*(o\
11563*o11570*pcx+o11565*o11570*pcy+o11567*o11570*pcz)))*pow(CC,-2.);
}
else if (ibody==0 && idim ==0 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==1 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==1 && iterm==1) {
qdot1[ibody][idim][iterm]=pay/ma;
}
else if (ibody==0 && idim ==1 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==1 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pay*(pax*pax+pay*pay+paz*paz)*pow(CC,-2.)*pow(ma,-3\
.);
}
else if (ibody==0 && idim ==1 && iterm==4) {

o1254=1/ma;
o1255=1/mb;
o1259=-qbx;
o12510=o1259+qax;
o1257=-qby;
o1258=o1257+qay;
o12511=o12510*o12510;
o12512=o1258*o1258;
o12513=-qbz;
o12514=o12513+qaz;
o12515=o12514*o12514;
o12516=o12511+o12512+o12515;
o12517=1./sqrt(o12516);
o1256=-7.*o1254*o1255*pby;
o12528=-qay;
o12529=o12528+qby;
o12525=-qax;
o12526=o12525+qbx;
o12527=o12526*o12526;
o12530=o12529*o12529;
o12531=-qaz;
o12532=o12531+qbz;
o12533=o12532*o12532;
o12534=o12527+o12530+o12533;
o12535=1./sqrt(o12534);
o1252=pow(ma,-2.);
o1253=12.*o1252*pay;
o12543=1/mc;
o12547=-qcx;
o12548=o12547+qax;
o12545=-qcy;
o12546=o12545+qay;
o12549=o12548*o12548;
o12550=o12546*o12546;
o12551=-qcz;
o12552=o12551+qaz;
o12553=o12552*o12552;
o12554=o12549+o12550+o12553;
o12555=1./sqrt(o12554);
o12544=-7.*o1254*o12543*pcy;
o12565=o12528+qcy;
o12563=o12525+qcx;
o12564=o12563*o12563;
o12566=o12565*o12565;
o12567=o12531+qcz;
o12568=o12567*o12567;
o12569=o12564+o12566+o12568;
o12570=1./sqrt(o12569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o12517*(o1253+o1256-o12517*o1254*o1255*o1\
258*(o12510*o12517*pbx+o12517*o1258*pby+o12514*o12517*pbz))+ma*mb*o12535*(o1256-o\
12529*o12535*o1254*o1255*(o12526*o12535*pbx+o12529*o12535*pby+o12532*o12535*pbz))\
+ma*mc*o12555*(o1253+o12544-o1254*o12543*o12546*o12555*(o12548*o12555*pcx+o12546*\
o12555*pcy+o12552*o12555*pcz))+ma*mc*o12570*(o12544-o1254*o12543*o12565*o12570*(o\
12563*o12570*pcx+o12565*o12570*pcy+o12567*o12570*pcz)))*pow(CC,-2.);
}
else if (ibody==0 && idim ==1 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==2 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==2 && iterm==1) {
qdot1[ibody][idim][iterm]=paz/ma;
}
else if (ibody==0 && idim ==2 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==0 && idim ==2 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*paz*(pax*pax+pay*pay+paz*paz)*pow(CC,-2.)*pow(ma,-3\
.);
}
else if (ibody==0 && idim ==2 && iterm==4) {

o1354=1/ma;
o1355=1/mb;
o1357=-qbx;
o1358=o1357+qax;
o13510=-qby;
o13511=o13510+qay;
o1359=o1358*o1358;
o13512=o13511*o13511;
o13513=-qbz;
o13514=o13513+qaz;
o13515=o13514*o13514;
o13516=o13512+o13515+o1359;
o13517=1./sqrt(o13516);
o1356=-7.*o1354*o1355*pbz;
o13531=-qaz;
o13532=o13531+qbz;
o13525=-qax;
o13526=o13525+qbx;
o13527=o13526*o13526;
o13528=-qay;
o13529=o13528+qby;
o13530=o13529*o13529;
o13533=o13532*o13532;
o13534=o13527+o13530+o13533;
o13535=1./sqrt(o13534);
o1352=pow(ma,-2.);
o1353=12.*o1352*paz;
o13543=1/mc;
o13545=-qcx;
o13546=o13545+qax;
o13548=-qcy;
o13549=o13548+qay;
o13547=o13546*o13546;
o13550=o13549*o13549;
o13551=-qcz;
o13552=o13551+qaz;
o13553=o13552*o13552;
o13554=o13547+o13550+o13553;
o13555=1./sqrt(o13554);
o13544=-7.*o1354*o13543*pcz;
o13567=o13531+qcz;
o13563=o13525+qcx;
o13564=o13563*o13563;
o13565=o13528+qcy;
o13566=o13565*o13565;
o13568=o13567*o13567;
o13569=o13564+o13566+o13568;
o13570=1./sqrt(o13569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o13517*(o1353+o1356-o13514*o13517*o1354*o\
1355*(o13517*o1358*pbx+o13511*o13517*pby+o13514*o13517*pbz))+ma*mb*o13535*(o1356-\
o13532*o13535*o1354*o1355*(o13526*o13535*pbx+o13529*o13535*pby+o13532*o13535*pbz)\
)+ma*mc*o13555*(o1353+o13544-o1354*o13543*o13552*o13555*(o13546*o13555*pcx+o13549\
*o13555*pcy+o13552*o13555*pcz))+ma*mc*o13570*(o13544-o1354*o13543*o13567*o13570*(\
o13563*o13570*pcx+o13565*o13570*pcy+o13567*o13570*pcz)))*pow(CC,-2.);
}
else if (ibody==0 && idim ==2 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==0 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==0 && iterm==1) {
qdot1[ibody][idim][iterm]=pbx/mb;
}
else if (ibody==1 && idim ==0 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==0 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pbx*(pbx*pbx+pby*pby+pbz*pbz)*pow(CC,-2.)*pow(mb,-3\
.);
}
else if (ibody==1 && idim ==0 && iterm==4) {

o2152=1/ma;
o2153=1/mb;
o2155=-qbx;
o2156=o2155+qax;
o2158=-qby;
o2159=o2158+qay;
o2157=o2156*o2156;
o21510=o2159*o2159;
o21511=-qbz;
o21512=o21511+qaz;
o21513=o21512*o21512;
o21514=o21510+o21513+o2157;
o21515=1./sqrt(o21514);
o2154=-7.*o2152*o2153*pax;
o21523=-qax;
o21524=o21523+qbx;
o21525=o21524*o21524;
o21526=-qay;
o21527=o21526+qby;
o21528=o21527*o21527;
o21529=-qaz;
o21530=o21529+qbz;
o21531=o21530*o21530;
o21532=o21525+o21528+o21531;
o21533=1./sqrt(o21532);
o21534=pow(mb,-2.);
o21535=12.*o21534*pbx;
o21543=1/mc;
o21545=-qcx;
o21546=o21545+qbx;
o21548=-qcy;
o21549=o21548+qby;
o21547=o21546*o21546;
o21550=o21549*o21549;
o21551=-qcz;
o21552=o21551+qbz;
o21553=o21552*o21552;
o21554=o21547+o21550+o21553;
o21555=1./sqrt(o21554);
o21544=-7.*o2153*o21543*pcx;
o21563=o2155+qcx;
o21564=o21563*o21563;
o21565=o2158+qcy;
o21566=o21565*o21565;
o21567=o21511+qcz;
o21568=o21567*o21567;
o21569=o21564+o21566+o21568;
o21570=1./sqrt(o21569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o21515*(o2154-o21515*o2152*o2153*o2156*(o\
21515*o2156*pax+o21515*o2159*pay+o21512*o21515*paz))+ma*mb*o21533*(o21535+o2154-o\
2152*o21524*o2153*o21533*(o21524*o21533*pax+o21527*o21533*pay+o21530*o21533*paz))\
+mb*mc*o21555*(o21535+o21544-o2153*o21543*o21546*o21555*(o21546*o21555*pcx+o21549\
*o21555*pcy+o21552*o21555*pcz))+mb*mc*o21570*(o21544-o2153*o21543*o21563*o21570*(\
o21563*o21570*pcx+o21565*o21570*pcy+o21567*o21570*pcz)))*pow(CC,-2.);
}
else if (ibody==1 && idim ==0 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==1 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==1 && iterm==1) {
qdot1[ibody][idim][iterm]=pby/mb;
}
else if (ibody==1 && idim ==1 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==1 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pby*(pbx*pbx+pby*pby+pbz*pbz)*pow(CC,-2.)*pow(mb,-3\
.);
}
else if (ibody==1 && idim ==1 && iterm==4) {

o2252=1/ma;
o2253=1/mb;
o2257=-qbx;
o2258=o2257+qax;
o2255=-qby;
o2256=o2255+qay;
o2259=o2258*o2258;
o22510=o2256*o2256;
o22511=-qbz;
o22512=o22511+qaz;
o22513=o22512*o22512;
o22514=o22510+o22513+o2259;
o22515=1./sqrt(o22514);
o2254=-7.*o2252*o2253*pay;
o22526=-qay;
o22527=o22526+qby;
o22523=-qax;
o22524=o22523+qbx;
o22525=o22524*o22524;
o22528=o22527*o22527;
o22529=-qaz;
o22530=o22529+qbz;
o22531=o22530*o22530;
o22532=o22525+o22528+o22531;
o22533=1./sqrt(o22532);
o22534=pow(mb,-2.);
o22535=12.*o22534*pby;
o22543=1/mc;
o22547=-qcx;
o22548=o22547+qbx;
o22545=-qcy;
o22546=o22545+qby;
o22549=o22548*o22548;
o22550=o22546*o22546;
o22551=-qcz;
o22552=o22551+qbz;
o22553=o22552*o22552;
o22554=o22549+o22550+o22553;
o22555=1./sqrt(o22554);
o22544=-7.*o2253*o22543*pcy;
o22565=o2255+qcy;
o22563=o2257+qcx;
o22564=o22563*o22563;
o22566=o22565*o22565;
o22567=o22511+qcz;
o22568=o22567*o22567;
o22569=o22564+o22566+o22568;
o22570=1./sqrt(o22569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o22515*(o2254-o22515*o2252*o2253*o2256*(o\
22515*o2258*pax+o22515*o2256*pay+o22512*o22515*paz))+ma*mb*o22533*(o22535+o2254-o\
2252*o22527*o2253*o22533*(o22524*o22533*pax+o22527*o22533*pay+o22530*o22533*paz))\
+mb*mc*o22555*(o22535+o22544-o2253*o22543*o22546*o22555*(o22548*o22555*pcx+o22546\
*o22555*pcy+o22552*o22555*pcz))+mb*mc*o22570*(o22544-o2253*o22543*o22565*o22570*(\
o22563*o22570*pcx+o22565*o22570*pcy+o22567*o22570*pcz)))*pow(CC,-2.);
}
else if (ibody==1 && idim ==1 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==2 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==2 && iterm==1) {
qdot1[ibody][idim][iterm]=pbz/mb;
}
else if (ibody==1 && idim ==2 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==1 && idim ==2 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pbz*(pbx*pbx+pby*pby+pbz*pbz)*pow(CC,-2.)*pow(mb,-3\
.);
}
else if (ibody==1 && idim ==2 && iterm==4) {

o2352=1/ma;
o2353=1/mb;
o2355=-qbx;
o2356=o2355+qax;
o2358=-qby;
o2359=o2358+qay;
o2357=o2356*o2356;
o23510=o2359*o2359;
o23511=-qbz;
o23512=o23511+qaz;
o23513=o23512*o23512;
o23514=o23510+o23513+o2357;
o23515=1./sqrt(o23514);
o2354=-7.*o2352*o2353*paz;
o23529=-qaz;
o23530=o23529+qbz;
o23523=-qax;
o23524=o23523+qbx;
o23525=o23524*o23524;
o23526=-qay;
o23527=o23526+qby;
o23528=o23527*o23527;
o23531=o23530*o23530;
o23532=o23525+o23528+o23531;
o23533=1./sqrt(o23532);
o23534=pow(mb,-2.);
o23535=12.*o23534*pbz;
o23543=1/mc;
o23545=-qcx;
o23546=o23545+qbx;
o23548=-qcy;
o23549=o23548+qby;
o23547=o23546*o23546;
o23550=o23549*o23549;
o23551=-qcz;
o23552=o23551+qbz;
o23553=o23552*o23552;
o23554=o23547+o23550+o23553;
o23555=1./sqrt(o23554);
o23544=-7.*o2353*o23543*pcz;
o23567=o23511+qcz;
o23563=o2355+qcx;
o23564=o23563*o23563;
o23565=o2358+qcy;
o23566=o23565*o23565;
o23568=o23567*o23567;
o23569=o23564+o23566+o23568;
o23570=1./sqrt(o23569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mb*o23515*(o2354-o23512*o23515*o2352*o2353*(\
o23515*o2356*pax+o23515*o2359*pay+o23512*o23515*paz))+ma*mb*o23533*(o23535+o2354-\
o2352*o2353*o23530*o23533*(o23524*o23533*pax+o23527*o23533*pay+o23530*o23533*paz)\
)+mb*mc*o23555*(o23535+o23544-o2353*o23543*o23552*o23555*(o23546*o23555*pcx+o2354\
9*o23555*pcy+o23552*o23555*pcz))+mb*mc*o23570*(o23544-o2353*o23543*o23567*o23570*\
(o23563*o23570*pcx+o23565*o23570*pcy+o23567*o23570*pcz)))*pow(CC,-2.);
}
else if (ibody==1 && idim ==2 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==0 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==0 && iterm==1) {
qdot1[ibody][idim][iterm]=pcx/mc;
}
else if (ibody==2 && idim ==0 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==0 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pcx*(pcx*pcx+pcy*pcy+pcz*pcz)*pow(CC,-2.)*pow(mc,-3\
.);
}
else if (ibody==2 && idim ==0 && iterm==4) {

o3152=1/ma;
o3153=1/mc;
o3155=-qcx;
o3156=o3155+qax;
o3158=-qcy;
o3159=o3158+qay;
o3157=o3156*o3156;
o31510=o3159*o3159;
o31511=-qcz;
o31512=o31511+qaz;
o31513=o31512*o31512;
o31514=o31510+o31513+o3157;
o31515=1./sqrt(o31514);
o31523=1/mb;
o31525=o3155+qbx;
o31527=o3158+qby;
o31526=o31525*o31525;
o31528=o31527*o31527;
o31529=o31511+qbz;
o31530=o31529*o31529;
o31531=o31526+o31528+o31530;
o31532=1./sqrt(o31531);
o3154=-7.*o3152*o3153*pax;
o31540=-qax;
o31541=o31540+qcx;
o31542=o31541*o31541;
o31543=-qay;
o31544=o31543+qcy;
o31545=o31544*o31544;
o31546=-qaz;
o31547=o31546+qcz;
o31548=o31547*o31547;
o31549=o31542+o31545+o31548;
o31550=1./sqrt(o31549);
o31524=-7.*o31523*o3153*pbx;
o31551=pow(mc,-2.);
o31552=12.*o31551*pcx;
o31560=-qbx;
o31561=o31560+qcx;
o31562=o31561*o31561;
o31563=-qby;
o31564=o31563+qcy;
o31565=o31564*o31564;
o31566=-qbz;
o31567=o31566+qcz;
o31568=o31567*o31567;
o31569=o31562+o31565+o31568;
o31570=1./sqrt(o31569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mc*o31515*(o3154-o31515*o3152*o3153*o3156*(o\
31515*o3156*pax+o31515*o3159*pay+o31512*o31515*paz))+ma*mc*o31550*(o3154+o31552-o\
3152*o3153*o31541*o31550*(o31541*o31550*pax+o31544*o31550*pay+o31547*o31550*paz))\
+mb*mc*o31532*(o31524-o31523*o31525*o3153*o31532*(o31525*o31532*pbx+o31527*o31532\
*pby+o31529*o31532*pbz))+mb*mc*o31570*(o31524+o31552-o31523*o3153*o31561*o31570*(\
o31561*o31570*pbx+o31564*o31570*pby+o31567*o31570*pbz)))*pow(CC,-2.);
}
else if (ibody==2 && idim ==0 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==1 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==1 && iterm==1) {
qdot1[ibody][idim][iterm]=pcy/mc;
}
else if (ibody==2 && idim ==1 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==1 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pcy*(pcx*pcx+pcy*pcy+pcz*pcz)*pow(CC,-2.)*pow(mc,-3\
.);
}
else if (ibody==2 && idim ==1 && iterm==4) {

o3252=1/ma;
o3253=1/mc;
o3257=-qcx;
o3258=o3257+qax;
o3255=-qcy;
o3256=o3255+qay;
o3259=o3258*o3258;
o32510=o3256*o3256;
o32511=-qcz;
o32512=o32511+qaz;
o32513=o32512*o32512;
o32514=o32510+o32513+o3259;
o32515=1./sqrt(o32514);
o32523=1/mb;
o32526=o3257+qbx;
o32525=o3255+qby;
o32527=o32526*o32526;
o32528=o32525*o32525;
o32529=o32511+qbz;
o32530=o32529*o32529;
o32531=o32527+o32528+o32530;
o32532=1./sqrt(o32531);
o3254=-7.*o3252*o3253*pay;
o32543=-qay;
o32544=o32543+qcy;
o32540=-qax;
o32541=o32540+qcx;
o32542=o32541*o32541;
o32545=o32544*o32544;
o32546=-qaz;
o32547=o32546+qcz;
o32548=o32547*o32547;
o32549=o32542+o32545+o32548;
o32550=1./sqrt(o32549);
o32524=-7.*o32523*o3253*pby;
o32551=pow(mc,-2.);
o32552=12.*o32551*pcy;
o32563=-qby;
o32564=o32563+qcy;
o32560=-qbx;
o32561=o32560+qcx;
o32562=o32561*o32561;
o32565=o32564*o32564;
o32566=-qbz;
o32567=o32566+qcz;
o32568=o32567*o32567;
o32569=o32562+o32565+o32568;
o32570=1./sqrt(o32569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mc*o32515*(o3254-o32515*o3252*o3253*o3256*(o\
32515*o3258*pax+o32515*o3256*pay+o32512*o32515*paz))+ma*mc*o32550*(o3254+o32552-o\
3252*o3253*o32544*o32550*(o32541*o32550*pax+o32544*o32550*pay+o32547*o32550*paz))\
+mb*mc*o32532*(o32524-o32523*o32525*o3253*o32532*(o32526*o32532*pbx+o32525*o32532\
*pby+o32529*o32532*pbz))+mb*mc*o32570*(o32524+o32552-o32523*o3253*o32564*o32570*(\
o32561*o32570*pbx+o32564*o32570*pby+o32567*o32570*pbz)))*pow(CC,-2.);
}
else if (ibody==2 && idim ==1 && iterm==5) {

qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==2 && iterm==0) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==2 && iterm==1) {
qdot1[ibody][idim][iterm]=pcz/mc;
}
else if (ibody==2 && idim ==2 && iterm==2) {
qdot1[ibody][idim][iterm]=0.;
}
else if (ibody==2 && idim ==2 && iterm==3) {
qdot1[ibody][idim][iterm]=-0.5*pcz*(pcx*pcx+pcy*pcy+pcz*pcz)*pow(CC,-2.)*pow(mc,-3\
.);
}
else if (ibody==2 && idim ==2 && iterm==4) {

o3352=1/ma;
o3353=1/mc;
o3355=-qcx;
o3356=o3355+qax;
o3358=-qcy;
o3359=o3358+qay;
o3357=o3356*o3356;
o33510=o3359*o3359;
o33511=-qcz;
o33512=o33511+qaz;
o33513=o33512*o33512;
o33514=o33510+o33513+o3357;
o33515=1./sqrt(o33514);
o33523=1/mb;
o33525=o3355+qbx;
o33527=o3358+qby;
o33526=o33525*o33525;
o33528=o33527*o33527;
o33529=o33511+qbz;
o33530=o33529*o33529;
o33531=o33526+o33528+o33530;
o33532=1./sqrt(o33531);
o3354=-7.*o3352*o3353*paz;
o33546=-qaz;
o33547=o33546+qcz;
o33540=-qax;
o33541=o33540+qcx;
o33542=o33541*o33541;
o33543=-qay;
o33544=o33543+qcy;
o33545=o33544*o33544;
o33548=o33547*o33547;
o33549=o33542+o33545+o33548;
o33550=1./sqrt(o33549);
o33524=-7.*o33523*o3353*pbz;
o33551=pow(mc,-2.);
o33552=12.*o33551*pcz;
o33566=-qbz;
o33567=o33566+qcz;
o33560=-qbx;
o33561=o33560+qcx;
o33562=o33561*o33561;
o33563=-qby;
o33564=o33563+qcy;
o33565=o33564*o33564;
o33568=o33567*o33567;
o33569=o33562+o33565+o33568;
o33570=1./sqrt(o33569);
qdot1[ibody][idim][iterm]=-0.25*G*(ma*mc*o33515*(o3354-o33512*o33515*o3352*o3353*(\
o33515*o3356*pax+o33515*o3359*pay+o33512*o33515*paz))+ma*mc*o33550*(o3354+o33552-\
o3352*o3353*o33547*o33550*(o33541*o33550*pax+o33544*o33550*pay+o33547*o33550*paz)\
)+mb*mc*o33532*(o33524-o33523*o33529*o3353*o33532*(o33525*o33532*pbx+o33527*o3353\
2*pby+o33529*o33532*pbz))+mb*mc*o33570*(o33524+o33552-o33523*o3353*o33567*o33570*\
(o33561*o33570*pbx+o33564*o33570*pby+o33567*o33570*pbz)))*pow(CC,-2.);
}
else if (ibody==2 && idim ==2 && iterm==5) {

qdot1[ibody][idim][iterm]=0.
}
