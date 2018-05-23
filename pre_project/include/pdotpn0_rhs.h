if (ibody == 0 && idim == 0) {
o111=-qbx;
o112=o111+qax;
o1113=-qax;
o1114=o1113+qbx;
o1125=-qcx;
o1126=o1125+qax;
o1137=o1113+qcx;
o1116=-qay;
o1119=-qaz;
pdot[ibody][idim]=0.5*G*(-(ma*mb*o112*pow(o112*o112+pow(qay-qby,2.)+pow(qaz-qbz,2\
.),-1.5))+ma*mb*o1114*pow(o1114*o1114+pow(o1116+qby,2.)+pow(o1119+qbz,2.),-1.5)-m\
a*mc*o1126*pow(o1126*o1126+pow(qay-qcy,2.)+pow(qaz-qcz,2.),-1.5)+ma*mc*o1137*pow(\
o1137*o1137+pow(o1116+qcy,2.)+pow(o1119+qcz,2.),-1.5));
}
else if (ibody == 0 && idim == 1) {

o121=-qby;
o122=o121+qay;
o1213=-qay;
o1214=o1213+qby;
o1225=-qcy;
o1226=o1225+qay;
o1215=-qax;
o1237=o1213+qcy;
o1219=-qaz;
pdot[ibody][idim]=0.5*G*(-(ma*mb*o122*pow(o122*o122+pow(qax-qbx,2.)+pow(qaz-qbz,2\
.),-1.5))+ma*mb*o1214*pow(o1214*o1214+pow(o1215+qbx,2.)+pow(o1219+qbz,2.),-1.5)-m\
a*mc*o1226*pow(o1226*o1226+pow(qax-qcx,2.)+pow(qaz-qcz,2.),-1.5)+ma*mc*o1237*pow(\
o1237*o1237+pow(o1215+qcx,2.)+pow(o1219+qcz,2.),-1.5));
}
else if (ibody == 0 && idim == 2) {

o137=-qbz;
o138=o137+qaz;
o1313=-qaz;
o1314=o1313+qbz;
o1331=-qcz;
o1332=o1331+qaz;
o1315=-qax;
o1318=-qay;
o1337=o1313+qcz;
pdot[ibody][idim]=0.5*G*(-(ma*mb*o138*pow(o138*o138+pow(qax-qbx,2.)+pow(qay-qby,2\
.),-1.5))+ma*mb*o1314*pow(o1314*o1314+pow(o1315+qbx,2.)+pow(o1318+qby,2.),-1.5)-m\
a*mc*o1332*pow(o1332*o1332+pow(qax-qcx,2.)+pow(qay-qcy,2.),-1.5)+ma*mc*o1337*pow(\
o1337*o1337+pow(o1315+qcx,2.)+pow(o1318+qcy,2.),-1.5));
}
else if (ibody == 1 && idim == 0) {

o211=-qbx;
o212=o211+qax;
o2113=-qax;
o2114=o2113+qbx;
o2125=-qcx;
o2126=o2125+qbx;
o2137=o211+qcx;
o214=-qby;
o217=-qbz;
pdot[ibody][idim]=0.5*G*(ma*mb*o212*pow(o212*o212+pow(o214+qay,2.)+pow(o217+qaz,2\
.),-1.5)-ma*mb*o2114*pow(o2114*o2114+pow(-qay+qby,2.)+pow(-qaz+qbz,2.),-1.5)-mb*m\
c*o2126*pow(o2126*o2126+pow(qby-qcy,2.)+pow(qbz-qcz,2.),-1.5)+mb*mc*o2137*pow(o21\
37*o2137+pow(o214+qcy,2.)+pow(o217+qcz,2.),-1.5));
}
else if (ibody == 1 && idim == 1) {

o221=-qby;
o222=o221+qay;
o2213=-qay;
o2214=o2213+qby;
o2225=-qcy;
o2226=o2225+qby;
o223=-qbx;
o2237=o221+qcy;
o227=-qbz;
pdot[ibody][idim]=0.5*G*(ma*mb*o222*pow(o222*o222+pow(o223+qax,2.)+pow(o227+qaz,2\
.),-1.5)-ma*mb*o2214*pow(o2214*o2214+pow(-qax+qbx,2.)+pow(-qaz+qbz,2.),-1.5)-mb*m\
c*o2226*pow(o2226*o2226+pow(qbx-qcx,2.)+pow(qbz-qcz,2.),-1.5)+mb*mc*o2237*pow(o22\
37*o2237+pow(o223+qcx,2.)+pow(o227+qcz,2.),-1.5));
}
else if (ibody == 1 && idim == 2) {

o237=-qbz;
o238=o237+qaz;
o2313=-qaz;
o2314=o2313+qbz;
o2331=-qcz;
o2332=o2331+qbz;
o231=-qbx;
o234=-qby;
o2337=o237+qcz;
pdot[ibody][idim]=0.5*G*(ma*mb*o238*pow(o238*o238+pow(o231+qax,2.)+pow(o234+qay,2\
.),-1.5)-ma*mb*o2314*pow(o2314*o2314+pow(-qax+qbx,2.)+pow(-qay+qby,2.),-1.5)-mb*m\
c*o2332*pow(o2332*o2332+pow(qbx-qcx,2.)+pow(qby-qcy,2.),-1.5)+mb*mc*o2337*pow(o23\
37*o2337+pow(o231+qcx,2.)+pow(o234+qcy,2.),-1.5));
}
else if (ibody == 2 && idim == 0) {

o311=-qcx;
o312=o311+qax;
o3113=o311+qbx;
o314=-qcy;
o317=-qcz;
o3122=-qax;
o3123=o3122+qcx;
o3134=-qbx;
o3135=o3134+qcx;
pdot[ibody][idim]=0.5*G*(ma*mc*o312*pow(o312*o312+pow(o314+qay,2.)+pow(o317+qaz,2\
.),-1.5)+mb*mc*o3113*pow(o3113*o3113+pow(o314+qby,2.)+pow(o317+qbz,2.),-1.5)-ma*m\
c*o3123*pow(o3123*o3123+pow(-qay+qcy,2.)+pow(-qaz+qcz,2.),-1.5)-mb*mc*o3135*pow(o\
3135*o3135+pow(-qby+qcy,2.)+pow(-qbz+qcz,2.),-1.5));
}
else if (ibody == 2 && idim == 1) {

o321=-qcy;
o322=o321+qay;
o323=-qcx;
o3213=o321+qby;
o327=-qcz;
o3222=-qay;
o3223=o3222+qcy;
o3234=-qby;
o3235=o3234+qcy;
pdot[ibody][idim]=0.5*G*(ma*mc*o322*pow(o322*o322+pow(o323+qax,2.)+pow(o327+qaz,2\
.),-1.5)+mb*mc*o3213*pow(o3213*o3213+pow(o323+qbx,2.)+pow(o327+qbz,2.),-1.5)-ma*m\
c*o3223*pow(o3223*o3223+pow(-qax+qcx,2.)+pow(-qaz+qcz,2.),-1.5)-mb*mc*o3235*pow(o\
3235*o3235+pow(-qbx+qcx,2.)+pow(-qbz+qcz,2.),-1.5));

}
else if (ibody == 2 && idim == 2) {
o337=-qcz;
o338=o337+qaz;
o331=-qcx;
o334=-qcy;
o3317=o337+qbz;
o3322=-qaz;
o3323=o3322+qcz;
o3334=-qbz;
o3335=o3334+qcz;
pdot[ibody][idim]=0.5*G*(ma*mc*o338*pow(o338*o338+pow(o331+qax,2.)+pow(o334+qay,2\
.),-1.5)+mb*mc*o3317*pow(o3317*o3317+pow(o331+qbx,2.)+pow(o334+qby,2.),-1.5)-ma*m\
c*o3323*pow(o3323*o3323+pow(-qax+qcx,2.)+pow(-qay+qcy,2.),-1.5)-mb*mc*o3335*pow(o\
3335*o3335+pow(-qbx+qcx,2.)+pow(-qby+qcy,2.),-1.5));
}
