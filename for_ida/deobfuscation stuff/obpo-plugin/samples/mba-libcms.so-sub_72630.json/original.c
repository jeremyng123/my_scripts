// positive sp value has been detected, the output may be wrong!
int __fastcall sub_72630(int a1, int a2, int a3, _DWORD *a4)
{
  int v4; // r8
  int v5; // r10
  _DWORD *v6; // r7
  _DWORD *v7; // r6
  int v8; // r4
  int v9; // r2
  int v10; // r1
  int v11; // r0
  _DWORD *v12; // r1
  int v13; // r0
  bool v14; // zf
  char v15; // r0
  _DWORD *v16; // r4
  _DWORD *v17; // r0
  int v18; // r1
  unsigned int v19; // r0
  int v20; // r5
  int v21; // r0
  int v22; // r4
  int v23; // r0
  _DWORD *v24; // r2
  int v25; // r0
  int v26; // r2
  int v27; // r0
  int v28; // r0
  char v29; // r0
  int v30; // r0
  int v31; // r2
  int v32; // r3
  int v33; // r2
  int v34; // r0
  char v35; // r0
  unsigned int v36; // r0
  int v37; // r0
  char v38; // r0
  int v39; // r0
  char v40; // r0
  int v41; // r0
  int v42; // r0
  int v43; // r1
  _DWORD *v44; // r2
  _DWORD *v45; // r0
  _DWORD *v46; // r0
  _DWORD *v47; // r0
  _DWORD *v48; // r0
  _DWORD *v49; // r0
  _DWORD *v50; // r0
  int v51; // r0
  char v52; // r0
  int v53; // r0
  int v54; // r1
  int v55; // r0
  int v56; // r1
  int v57; // r2
  int v58; // r3
  int v59; // r0
  int v60; // r0
  char v61; // r0
  int v62; // r0
  int v63; // r0
  int v64; // r0
  int result; // r0
  _DWORD v66[71]; // [sp-25E8h] [bp-2870h] BYREF
  int v67; // [sp-24CCh] [bp-2754h]
  int v68; // [sp-24C8h] [bp-2750h]
  int v69; // [sp-24C4h] [bp-274Ch]
  int v70; // [sp-24C0h] [bp-2748h]
  int v71; // [sp-24BCh] [bp-2744h]
  int v72; // [sp-24B8h] [bp-2740h]
  int v73; // [sp-24B4h] [bp-273Ch]
  int v74; // [sp-24B0h] [bp-2738h]
  int v75; // [sp-24ACh] [bp-2734h]
  int v76; // [sp-24A8h] [bp-2730h]
  int v77; // [sp-24A4h] [bp-272Ch]
  int v78; // [sp-24A0h] [bp-2728h]
  int v79; // [sp-249Ch] [bp-2724h]
  int v80; // [sp-2498h] [bp-2720h]
  int v81; // [sp-2494h] [bp-271Ch]
  int v82; // [sp-2490h] [bp-2718h]
  int v83; // [sp-248Ch] [bp-2714h]
  int v84; // [sp-2488h] [bp-2710h]
  int v85; // [sp-2484h] [bp-270Ch]
  int v86; // [sp-2480h] [bp-2708h]
  int v87; // [sp-247Ch] [bp-2704h]
  int v88; // [sp-2478h] [bp-2700h]
  int v89; // [sp-2474h] [bp-26FCh]
  int v90; // [sp-2470h] [bp-26F8h]
  int v91; // [sp-246Ch] [bp-26F4h]
  int v92; // [sp-2468h] [bp-26F0h]
  int v93; // [sp-2464h] [bp-26ECh]
  int v94; // [sp-2460h] [bp-26E8h]
  int v95; // [sp-245Ch] [bp-26E4h]
  int v96; // [sp-2458h] [bp-26E0h]
  int v97; // [sp-2454h] [bp-26DCh]
  int v98; // [sp-2450h] [bp-26D8h]
  int v99; // [sp-244Ch] [bp-26D4h]
  int v100; // [sp-2448h] [bp-26D0h]
  int v101; // [sp-2444h] [bp-26CCh]
  int v102; // [sp-2440h] [bp-26C8h]
  int v103; // [sp-243Ch] [bp-26C4h]
  int v104; // [sp-2438h] [bp-26C0h]
  int v105; // [sp-2434h] [bp-26BCh]
  int v106; // [sp-2430h] [bp-26B8h]
  int v107; // [sp-242Ch] [bp-26B4h]
  int v108; // [sp-2428h] [bp-26B0h]
  char v109; // [sp-23ECh] [bp-2674h]
  char v110; // [sp-23EBh] [bp-2673h]
  _DWORD v111[999]; // [sp-2360h] [bp-25E8h] BYREF
  __int64 v112; // [sp-13C4h] [bp-164Ch]
  int v113; // [sp-13BCh] [bp-1644h]
  _DWORD *v114; // [sp-13B8h] [bp-1640h]
  _DWORD *v115; // [sp-13B4h] [bp-163Ch]
  _DWORD v116[20]; // [sp-984h] [bp-C0Ch] BYREF
  _DWORD *v117; // [sp-934h] [bp-BBCh]
  _DWORD *v118; // [sp-930h] [bp-BB8h]
  _DWORD v119[143]; // [sp-92Ch] [bp-BB4h] BYREF
  __int64 v120; // [sp-6F0h] [bp-978h]
  int v121; // [sp-6E8h] [bp-970h]
  int v122; // [sp-6E4h] [bp-96Ch]

  v6 = v111;
  v7 = v66;
  v66[4] = a1;
  v8 = -1092892356;
  v66[5] = dword_E1758;
  v66[6] = *(_DWORD *)dword_E1758;
  v66[8] = 378;
  v66[7] = 287;
  v9 = 1202922957;
  v110 = 0;
  v10 = -1839474801;
  v109 = 1;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( v10 <= -64647749 )
            {
              if ( v10 <= v8 )
              {
                if ( v10 > -1719518995 )
                {
                  if ( v10 > -1481242399 )
                  {
                    if ( v10 > -1415891569 )
                    {
                      if ( v10 > -1184883268 )
                      {
                        if ( v10 == -1096468175 )
                        {
                          v80 = 47;
                          v79 = 348;
                          v10 = -351002657;
                          v9 = 1202922957;
                        }
                      }
                      else if ( v10 == -1415891568 )
                      {
                        v10 = 441023298;
                      }
                      else
                      {
                        __dmb(0xBu);
                        dword_EEE34 = 1;
                        v9 = 1202922957;
                        v10 = 1181180590;
                        if ( !dword_EEE38 )
                          v10 = -699899797;
LABEL_121:
                        __dmb(0xBu);
                      }
                    }
                    else if ( v10 == -1443025340 )
                    {
                      v10 = -1970057431;
                      v7[1] = *(v6 - 16);
                    }
                    else
                    {
                      v10 = 309053727;
                      if ( *((_BYTE *)v6 - 129) )
                        v10 = -569516394;
                    }
                  }
                  else if ( v10 > -1593330836 )
                  {
                    if ( v10 > -1570464020 )
                    {
                      v10 = 1181180590;
                    }
                    else
                    {
                      v66[20] = 385;
                      v66[19] = 183;
                      v9 = 1202922957;
                      v10 = 4750090;
                    }
                  }
                  else if ( v10 > -1618417234 )
                  {
                    if ( v10 == -1618417233 )
                    {
                      v41 = *(_DWORD *)*(v6 - 32);
                      *(v6 - 19) = *(v6 - 21);
                      v42 = ((int (__fastcall *)(int, _DWORD))dword_75918[0])(v41, *(v6 - 19));
                      *(v6 - 18) = *(v6 - 31);
                      v43 = *(v6 - 18);
                      dword_EEE24 = v42;
                      ((void (__fastcall *)(int, int))unk_BC78)(v43, 84);
                      v44 = (_DWORD *)*(v6 - 31);
                      *v44 = &byte_E5521;
                      v44[1] = &byte_E5525;
                      v44[2] = dword_E1AF4;
                      v45 = (_DWORD *)*(v6 - 31);
                      v45[3] = &byte_E552B;
                      v45[4] = &byte_E5530;
                      v45[5] = dword_E1AF8;
                      v46 = (_DWORD *)*(v6 - 31);
                      v46[6] = &byte_E5547;
                      v46[7] = &byte_E5550;
                      v46[8] = dword_E1AFC;
                      v47 = (_DWORD *)*(v6 - 31);
                      v47[9] = &unk_D7FB2;
                      v47[10] = &byte_E5592;
                      v47[11] = dword_E1B00;
                      v48 = (_DWORD *)*(v6 - 31);
                      v48[12] = &unk_D7FB4;
                      v48[13] = &byte_E5592;
                      v48[14] = dword_E1B04;
                      v49 = (_DWORD *)*(v6 - 31);
                      v49[15] = &byte_E5599;
                      v49[16] = &unk_E559C;
                      v49[17] = dword_E1B08;
                      v50 = (_DWORD *)*(v6 - 31);
                      v50[18] = &byte_E55A1;
                      v50[19] = &byte_E55AB;
                      v50[20] = byte_75A5D;
                      v51 = ((int (__fastcall *)(_DWORD, _DWORD))dword_764D8[0])(*(_DWORD *)*(v6 - 32), *(v6 - 21));
                      v106 = 326;
                      v105 = 309;
                      v8 = -1092892356;
                      a4 = (_DWORD *)&unk_4702F;
                      v10 = 646009675;
                      v14 = v51 == 0;
                      v52 = 0;
                      LOWORD(v9) = 9677;
                      if ( v14 )
                        v52 = 1;
                      HIWORD(v9) = 18355;
                      *((_BYTE *)v6 - 65) = v52;
                    }
                    else
                    {
                      v10 = 1655508071;
                    }
                  }
                  else
                  {
                    v11 = *(v6 - 13);
                    *(v6 - 23) = *(v6 - 32);
                    v12 = (_DWORD *)*(v6 - 32);
                    *(v6 - 24) = v11 - 2252;
                    *v12 = 0;
                    v13 = ((int (__fastcall *)(_DWORD, _DWORD, void *))dword_75824[0])(
                            *(v6 - 24),
                            *(v6 - 32),
                            &unk_10006);
                    v98 = 281;
                    v97 = 131;
                    v8 = -1092892356;
                    a4 = (_DWORD *)&unk_16080;
                    v10 = 910872068;
                    v14 = v13 == 0;
                    v15 = 0;
                    LOWORD(v9) = 9677;
                    if ( v14 )
                      v15 = 1;
                    HIWORD(v9) = 18355;
                    *((_BYTE *)v6 - 85) = v15;
                  }
                }
                else if ( v10 > -1849048262 )
                {
                  if ( v10 > -1825725366 )
                  {
                    if ( v10 > -1792529888 )
                    {
                      if ( v10 == -1792529887 )
                      {
                        v10 = -503741376;
                      }
                      else
                      {
                        v66[64] = 18;
                        v66[63] = 19;
                        v9 = 1202922957;
                        v10 = 714239098;
                      }
                    }
                    else if ( v10 == -1825725365 )
                    {
                      v10 = -1096468175;
                      if ( *((_BYTE *)v6 - 130) )
                        v10 = -219422521;
                    }
                    else
                    {
                      *(v6 - 38) = 13;
                      *(v6 - 39) = 6;
                      v9 = 1202922957;
                      v10 = -287559172;
                      if ( 641 * (*(v6 - 38) | 7) * (*(v6 - 38) | 7) == 563 * (*(v6 - 39) | 6) * (*(v6 - 39) | 6) )
                        v10 = -279426178;
                      *(v6 - 10) = v7[2];
                    }
                  }
                  else if ( v10 > -1839474802 )
                  {
                    if ( v10 == -1839474801 )
                    {
                      v10 = 1451987441;
                      if ( *((_BYTE *)v6 - 139) )
                        v10 = 169767367;
                      if ( *((_BYTE *)v6 - 140) )
                        v10 = 169767367;
                    }
                    else
                    {
                      v66[44] = 369;
                      v66[43] = 36;
                      v9 = 1202922957;
                      v10 = 1966400796;
                    }
                  }
                  else if ( v10 == -1849048261 )
                  {
                    v66[28] = 430;
                    v66[27] = 72;
                    v10 = -443199757;
                  }
                  else
                  {
                    v16 = (_DWORD *)(v8 + 112);
                    a4 = (_DWORD *)v16[1];
                    v7 = (_DWORD *)v16[2];
                    v6 = (_DWORD *)v16[3];
                    v8 = (int)(v16 + 4);
                    v90 = 444;
                    v89 = 400;
                    v9 = 1202922957;
                    v10 = -344222330;
                  }
                }
                else if ( v10 > -1970057432 )
                {
                  if ( v10 > -1897333440 )
                  {
                    if ( v10 == -1897333439 )
                    {
                      byte_E55AB = byte_DCB6B ^ 0xCE;
                      byte_E55AC = byte_DCB6C ^ 0xB5;
                      byte_E55AD = byte_DCB6D ^ 0x19;
                      byte_E55AE = byte_DCB6E ^ 0x43;
                      byte_E55AF = byte_DCB6F ^ 0x4C;
                      byte_E55B0 = byte_DCB70 ^ 0x71;
                      byte_E55B1 = byte_DCB71 ^ 0xFA;
                      byte_E55B2 = byte_DCB72 ^ 0x1C;
                      v86 = 24;
                      v85 = 26;
                      v9 = 1202922957;
                      v10 = -142282591;
                    }
                    else
                    {
                      v66[24] = 94;
                      v66[23] = 14;
                      v10 = 687254910;
                      v9 = 1202922957;
                    }
                  }
                  else if ( v10 == -1970057431 )
                  {
                    *(v6 - 46) = 454;
                    *(v6 - 47) = 215;
                    v10 = 1655508071;
                    if ( *(v6 - 46) * *(v6 - 46) + 1 == 7 * *(v6 - 47) * *(v6 - 47) )
                      v10 = -1603528414;
                    *(v6 - 12) = v7[1];
                  }
                  else
                  {
                    v10 = -503741376;
                    if ( *((_BYTE *)v6 - 132) )
                      v10 = -1733692719;
                  }
                }
                else if ( v10 == -2088117646 )
                {
                  v10 = -1849749670;
                }
                else
                {
                  v66[48] = 249;
                  v66[47] = 453;
                  v9 = 1202922957;
                  v10 = -535871965;
                }
              }
              else if ( v10 <= -510511411 )
              {
                if ( v10 > -658937760 )
                {
                  if ( v10 > -569516395 )
                  {
                    if ( v10 > -552622952 )
                    {
                      byte_E5550 = byte_DCB10 ^ 0x93;
                      byte_E5551 = byte_DCB11 ^ 0x16;
                      byte_E5552 = byte_DCB12 ^ 0x8A;
                      byte_E5553 = byte_DCB13 ^ 8;
                      byte_E5554 = byte_DCB14 ^ 0x8E;
                      byte_E5555 = byte_DCB15 ^ 0x5A;
                      byte_E5556 = byte_DCB16 ^ 0x16;
                      byte_E5557 = byte_DCB17 ^ 0xC1;
                      byte_E5558 = byte_DCB18 ^ 0xDB;
                      byte_E5559 = byte_DCB19 ^ 0x73;
                      byte_E555A = byte_DCB1A ^ 0x9C;
                      byte_E555B = byte_DCB1B ^ 0xB;
                      byte_E555C = byte_DCB1C ^ 0xCA;
                      byte_E555D = byte_DCB1D ^ 0xEC;
                      byte_E555E = byte_DCB1E ^ 0xCD;
                      byte_E555F = byte_DCB1F ^ 0x11;
                      byte_E5560 = byte_DCB20 ^ 0x5E;
                      byte_E5561 = byte_DCB21 ^ 0xC3;
                      byte_E5562 = byte_DCB22 ^ 0x3B;
                      byte_E5563 = byte_DCB23 ^ 0xE6;
                      byte_E5564 = byte_DCB24 ^ 0x8F;
                      byte_E5565 = byte_DCB25 ^ 0x7B;
                      byte_E5566 = byte_DCB26 ^ 0x5F;
                      byte_E5567 = byte_DCB27 ^ 0x5B;
                      byte_E5568 = byte_DCB28 ^ 0xBF;
                      byte_E5569 = byte_DCB29 ^ 0x69;
                      byte_E556A = byte_DCB2A ^ 0x22;
                      byte_E556B = byte_DCB2B ^ 0xF2;
                      byte_E556C = byte_DCB2C ^ 0xB;
                      byte_E556D = byte_DCB2D ^ 0xE5;
                      byte_E556E = byte_DCB2E ^ 0xF1;
                      byte_E556F = byte_DCB2F ^ 0xFA;
                      byte_E5570 = byte_DCB30 ^ 0x1E;
                      byte_E5571 = byte_DCB31 ^ 0xF3;
                      byte_E5572 = byte_DCB32 ^ 0x43;
                      byte_E5573 = byte_DCB33 ^ 0x32;
                      byte_E5574 = byte_DCB34 ^ 0x81;
                      byte_E5575 = byte_DCB35 ^ 0xCD;
                      byte_E5576 = byte_DCB36 ^ 0x67;
                      byte_E5577 = byte_DCB37 ^ 0xA2;
                      byte_E5578 = byte_DCB38 ^ 0x82;
                      byte_E5579 = byte_DCB39 ^ 0x2E;
                      byte_E557A = byte_DCB3A ^ 6;
                      byte_E557B = byte_DCB3B ^ 0xB8;
                      byte_E557C = byte_DCB3C ^ 0x1F;
                      byte_E557D = byte_DCB3D ^ 0xC4;
                      byte_E557E = byte_DCB3E ^ 0x36;
                      byte_E557F = byte_DCB3F ^ 0xFB;
                      byte_E5580 = byte_DCB40 ^ 0x87;
                      byte_E5581 = byte_DCB41 ^ 0x6D;
                      byte_E5582 = byte_DCB42 ^ 0x5A;
                      byte_E5583 = byte_DCB43 ^ 0x2C;
                      byte_E5584 = byte_DCB44 ^ 0xE9;
                      byte_E5585 = byte_DCB45 ^ 0x9B;
                      byte_E5586 = byte_DCB46 ^ 0x17;
                      byte_E5587 = byte_DCB47 ^ 0xC1;
                      byte_E5588 = byte_DCB48 ^ 0x5A;
                      byte_E5589 = byte_DCB49 ^ 0xEA;
                      byte_E558A = byte_DCB4A ^ 0xCD;
                      byte_E558B = byte_DCB4B ^ 0x5A;
                      byte_E558C = byte_DCB4C ^ 0x61;
                      byte_E558D = byte_DCB4D ^ 0xB1;
                      byte_E558E = byte_DCB4E ^ 0x18;
                      byte_E558F = byte_DCB4F ^ 0x77;
                      byte_E5590 = byte_DCB50 ^ 0xEF;
                      byte_E5591 = byte_DCB51 ^ 0x65;
                      v66[50] = 338;
                      v66[49] = 440;
                      v10 = 1911140485;
                      v9 = 1202922957;
                    }
                    else if ( v10 == -569516394 )
                    {
                      v84 = 320;
                      v83 = 100;
                      v9 = 1202922957;
                      v10 = -1897333439;
                    }
                    else
                    {
                      v10 = -1808129874;
                      v7[2] = *(v6 - 11);
                    }
                  }
                  else if ( v10 == -658937759 )
                  {
                    __dmb(0xBu);
                    dword_EEE38 = 1;
                    v62 = dword_EEE3C;
                    __dmb(0xBu);
                    v66[38] = 385;
                    v66[37] = 272;
                    v10 = 829416071;
                    v9 = 1202922957;
                    *((_BYTE *)v6 - 135) = v62 == 0;
                  }
                  else
                  {
                    v10 = -1264071445;
                    if ( *((_BYTE *)v6 - 136) )
                      v10 = -1849048261;
                  }
                }
                else if ( v10 > -757665603 )
                {
                  if ( v10 > -699899798 )
                  {
                    v66[32] = 25;
                    v66[31] = 13;
                    v9 = 1202922957;
                    v10 = 641039356;
                  }
                  else if ( v10 == -757665602 )
                  {
                    __dmb(0xBu);
                    *(_DWORD *)(dword_75814 + 480390) = 1;
                    v63 = *(_DWORD *)(dword_75818 + 480392);
                    __dmb(0xBu);
                    v66[62] = 503;
                    v66[61] = 307;
                    v10 = -1940439662;
                    v9 = 1202922957;
                    *((_BYTE *)v6 - 132) = v63 == 0;
                  }
                  else
                  {
                    v20 = *(_DWORD *)*(v6 - 32);
                    v21 = (*(int (__fastcall **)(int))(*(_DWORD *)v20 + 912))(v20);
                    v9 = 1202922957;
                    v8 = -1092892356;
                    v10 = 1631489775;
                    v7[3] = -1;
                    if ( v21 )
                    {
                      v22 = ((int (__fastcall *)(int, int, int))dword_7CC40[0])(v20, 1631489775, 1202922957);
                      ((void (__fastcall *)(int))dword_7CD50[0])(v20);
                      ((void (__fastcall *)(int, int))dword_77C84[0])(v20, v22);
                      v9 = 1202922957;
                      v8 = -1092892356;
                      v23 = -1;
                      goto LABEL_214;
                    }
                  }
                }
                else if ( v10 > -909150153 )
                {
                  if ( v10 == -909150152 )
                  {
                    __dmb(0xBu);
                    *(_DWORD *)(dword_7580C + 480804) = 1;
                    v64 = *(_DWORD *)(dword_75810 + 480806);
                    __dmb(0xBu);
                    v66[18] = 313;
                    v66[17] = 341;
                    a4 = (_DWORD *)&unk_51;
                    v10 = 363411641;
                    v9 = 1202922957;
                    *((_BYTE *)v6 - 137) = v64 == 0;
                  }
                  else
                  {
                    v10 = 986024035;
                    v66[56] = 19;
                    v66[55] = 9;
                  }
                }
                else if ( v10 == -1048516463 )
                {
                  v10 = 1607041602;
                  if ( *((_BYTE *)v6 - 131) )
                    v10 = -447932475;
                }
              }
              else if ( v10 <= -300802085 )
              {
                if ( v10 > -443199758 )
                {
                  if ( v10 > -351002658 )
                  {
                    if ( v10 == -351002657 )
                    {
                      __dmb(0xBu);
                      dword_EEE54 = 1;
                      v60 = dword_EEE58;
                      __dmb(0xBu);
                      v82 = 123;
                      v81 = 265;
                      a4 = (_DWORD *)&unk_A1C0;
                      v10 = -1437929951;
                      v14 = v60 == 0;
                      v61 = 0;
                      LOWORD(v9) = 9677;
                      if ( v14 )
                        v61 = 1;
                      HIWORD(v9) = 18355;
                      *((_BYTE *)v6 - 129) = v61;
                    }
                    else
                    {
                      v10 = 1202922958;
                    }
                  }
                  else if ( v10 == -443199757 )
                  {
                    byte_E5525 = byte_DCAE5 ^ 0xED;
                    byte_E5526 = byte_DCAE6 ^ 0x5E;
                    byte_E5527 = byte_DCAE7 ^ 0x17;
                    byte_E5528 = byte_DCAE8 ^ 0xB;
                    byte_E5529 = byte_DCAE9 ^ 0x79;
                    byte_E552A = byte_DCAEA ^ 0x15;
                    v66[30] = 370;
                    v66[29] = 198;
                    v9 = 1202922957;
                    v10 = 42386027;
                  }
                  else
                  {
                    v88 = 245;
                    v87 = 77;
                    v10 = -1844764132;
                    v9 = 1202922957;
                  }
                }
                else if ( v10 > -465942480 )
                {
                  if ( v10 == -465942479 )
                  {
                    v54 = *(v6 - 28);
                    *(v6 - 27) = *(_DWORD *)(v54 + 4);
                    v55 = *(_DWORD *)(v54 + 8);
                    v56 = *(v6 - 28);
                    *(v6 - 26) = v55;
                    *(v6 - 25) = *(_DWORD *)(v56 + 12);
                    ((void (__fastcall *)(_DWORD))unk_B9A8)(v7[4]);
                    v9 = 1202922957;
                    v94 = 335;
                    v93 = 509;
                    v8 = -1092892356;
                    v10 = 1458408300;
                  }
                  else
                  {
                    v68 = 46;
                    v67 = 236;
                    v9 = 1202922957;
                    v10 = 1537678586;
                  }
                }
                else if ( v10 == -510511410 )
                {
                  byte_E5547 = byte_DCB07 ^ 0xAC;
                  byte_E5548 = byte_DCB08 ^ 0x1B;
                  v9 = 1202922957;
                  byte_E5549 = byte_DCB09 ^ 0x96;
                  v10 = -70745028;
                }
                else
                {
                  v66[68] = 414;
                  v66[67] = 423;
                  v10 = 2125750387;
                }
              }
              else if ( v10 <= -219422522 )
              {
                if ( v10 > -279426179 )
                {
                  if ( v10 == -279426178 )
                  {
                    v10 = -287559172;
                  }
                  else
                  {
                    v10 = -70745028;
                    if ( *((_BYTE *)v6 - 134) )
                      v10 = -510511410;
                  }
                }
                else if ( v10 == -300802084 )
                {
                  v10 = -1835040958;
                }
                else
                {
                  v68 = -287559172;
                  v69 = -287559172;
                  v70 = v9;
                  v71 = (int)a4;
                  v67 = 470598;
                  v17 = (_DWORD *)((int (__fastcall *)(int, int, int, _DWORD *))word_77D92)(
                                    -287559172,
                                    -287559172,
                                    v9,
                                    a4);
                  a4 = (_DWORD *)&unk_13;
                  v18 = *(v6 - 14) - 9008;
                  v8 = -1092892356;
                  *v17 = *(v6 - 15) - 8496;
                  v17[1] = v18;
                  *(v6 - 36) = 31;
                  *(v6 - 37) = 19;
                  v9 = 1202922957;
                  v10 = 1534835701;
                  if ( 457 * (*(v6 - 36) | 0xA) * (*(v6 - 36) | 0xA) == 769 * (*(v6 - 37) | 5) * (*(v6 - 37) | 5) )
                    v10 = -279426178;
                }
              }
              else if ( v10 <= -142282592 )
              {
                if ( v10 == -219422521 )
                {
                  v76 = 18;
                  v75 = 31;
                  v9 = 1202922957;
                  v10 = 827195886;
                }
                else
                {
                  byte_E5510 = byte_DCAD0 ^ 0xB5;
                  byte_E5511 = byte_DCAD1 ^ 0x35;
                  byte_E5512 = byte_DCAD2 ^ 0x70;
                  byte_E5513 = byte_DCAD3 ^ 0x60;
                  byte_E5514 = byte_DCAD4 ^ 0xC6;
                  byte_E5515 = byte_DCAD5 ^ 0xC4;
                  byte_E5516 = byte_DCAD6 ^ 0x4A;
                  byte_E5517 = byte_DCAD7 ^ 0x92;
                  byte_E5518 = byte_DCAD8 ^ 0xB;
                  byte_E5519 = byte_DCAD9 ^ 0x4F;
                  byte_E551A = byte_DCADA ^ 0xF3;
                  byte_E551B = byte_DCADB ^ 0xAB;
                  byte_E551C = byte_DCADC ^ 0xB0;
                  byte_E551D = byte_DCADD ^ 0x92;
                  byte_E551E = byte_DCADE ^ 0x70;
                  byte_E551F = byte_DCADF ^ 0xA;
                  byte_E5520 = byte_DCAE0 ^ 0x7B;
                  v66[14] = 30;
                  v66[13] = 17;
                  v9 = 1202922957;
                  v10 = -1415891568;
                }
              }
              else if ( v10 == -142282591 )
              {
                v10 = 309053727;
              }
              else
              {
                if ( v10 != -74432247 )
                {
                  __dmb(0xBu);
                  *(_DWORD *)(dword_75804 + 481144) = 1;
                  v9 = 1202922957;
                  v10 = 1758425489;
                  if ( !*(_DWORD *)(dword_75808 + 481146) )
                    v10 = -2070799387;
                  goto LABEL_121;
                }
                v108 = 486;
                v107 = 296;
                v9 = 1202922957;
                v10 = 743973074;
              }
            }
            if ( v10 > v9 )
              break;
            if ( v10 > 646009674 )
            {
              if ( v10 > 827195885 )
              {
                if ( v10 > 986024034 )
                {
                  if ( v10 > 1110672737 )
                  {
                    if ( v10 == 1110672738 )
                    {
                      v66[60] = 262;
                      v66[59] = 490;
                      v9 = 1202922957;
                      v10 = -757665602;
                    }
                    else
                    {
                      v66[36] = 431;
                      v66[35] = 425;
                      v9 = 1202922957;
                      v10 = -658937759;
                    }
                  }
                  else if ( v10 == 986024035 )
                  {
                    byte_E5592 = byte_DCB52 ^ 0x1C;
                    byte_E5593 = byte_DCB53 ^ 0x73;
                    byte_E5594 = byte_DCB54 ^ 0x35;
                    byte_E5595 = byte_DCB55 ^ 0xDF;
                    byte_E5596 = byte_DCB56 ^ 0x49;
                    byte_E5597 = byte_DCB57 ^ 8;
                    byte_E5598 = byte_DCB58 ^ 0x6D;
                    v66[58] = 455;
                    v66[57] = 133;
                    v9 = 1202922957;
                    v10 = 1713093708;
                  }
                  else
                  {
                    *(v6 - 42) = 218;
                    *(v6 - 43) = 454;
                    v9 = 1202922957;
                    v10 = -64647748;
                    if ( (4 * *(v6 - 42) * *(v6 - 42) + 4) % 0x13u )
                      v10 = 299071115;
                    if ( (int)*(v6 - 43) > 243 )
                      v10 = 299071115;
                    *(v6 - 11) = v7[3];
                  }
                }
                else if ( v10 > 838860791 )
                {
                  v10 = -1808129874;
                  if ( *((_BYTE *)v6 - 85) )
                    v10 = 1868724096;
                  v7[2] = -1;
                }
                else if ( v10 == 827195886 )
                {
                  byte_E55A1 = byte_DCB61 ^ 0x63;
                  byte_E55A2 = byte_DCB62 ^ 0xC7;
                  byte_E55A3 = byte_DCB63 ^ 0x5C;
                  byte_E55A4 = byte_DCB64 ^ 0xCD;
                  byte_E55A5 = byte_DCB65 ^ 0x6F;
                  byte_E55A6 = byte_DCB66 ^ 0xFB;
                  byte_E55A7 = byte_DCB67 ^ 0x37;
                  byte_E55A8 = byte_DCB68 ^ 2;
                  byte_E55A9 = byte_DCB69 ^ 0xFB;
                  v9 = 1202922957;
                  byte_E55AA = byte_DCB6A ^ 0x64;
                  v78 = 9;
                  v77 = 11;
                  v10 = 1528049684;
                }
                else
                {
                  v10 = -1835040958;
                  if ( *((_BYTE *)v6 - 135) )
                    v10 = 589600417;
                }
              }
              else if ( v10 > 719621081 )
              {
                if ( v10 > 743973073 )
                {
                  v120 = ((__int64 (__fastcall *)(_DWORD))dword_765A4[0])(*(_DWORD *)*(v6 - 32));
                  v121 = v57;
                  v122 = v58;
                  v119[142] = 479616;
                  v59 = ((int (__fastcall *)(_DWORD, _DWORD, int, int))unk_2E470)(
                          *(_DWORD *)*(v6 - 32),
                          HIDWORD(v120),
                          v57,
                          v58);
                  *(v6 - 48) = 85;
                  *(v6 - 49) = 205;
                  v8 = -1092892356;
                  v10 = -1443025340;
                  LOWORD(v9) = 9677;
                  if ( *(v6 - 48) * *(v6 - 48) + 1 == 7 * *(v6 - 49) * *(v6 - 49) )
                    v10 = 1576522684;
                  HIWORD(v9) = 18355;
                  *(v6 - 16) = v59;
                }
                else if ( v10 == 719621082 )
                {
                  v23 = *(v6 - 12);
LABEL_214:
                  v10 = 1028868465;
                  v7[3] = v23;
                }
                else
                {
                  v10 = 441023298;
                  if ( *((_BYTE *)v6 - 138) )
                    v10 = 605851807;
                }
              }
              else if ( v10 > 687254909 )
              {
                if ( v10 == 687254910 )
                {
                  __dmb(0xBu);
                  dword_EEE30 = 1;
                  v53 = dword_EEE34;
                  __dmb(0xBu);
                  v66[26] = 180;
                  v66[25] = 313;
                  a4 = (_DWORD *)&unk_51;
                  v10 = -649123293;
                  v9 = 1202922957;
                  *((_BYTE *)v6 - 136) = v53 == 0;
                }
                else
                {
                  byte_E5599 = byte_DCB59 ^ 0xD9;
                  byte_E559A = byte_DCB5A ^ 0x65;
                  byte_E559B = byte_DCB5B ^ 0x85;
                  v66[66] = 153;
                  v66[65] = 194;
                  v9 = 1202922957;
                  v10 = -1792529887;
                }
              }
              else
              {
                v10 = -1970057431;
                if ( *((_BYTE *)v6 - 65) )
                  v10 = -74432247;
                v7[1] = -1;
              }
            }
            else if ( v10 > 362867669 )
            {
              if ( v10 > 555459583 )
              {
                if ( v10 > 605851806 )
                {
                  if ( v10 == 605851807 )
                  {
                    v66[12] = 77;
                    v66[11] = 168;
                    v10 = -158151206;
                  }
                  else
                  {
                    byte_E552B = byte_DCAEB ^ 0x26;
                    byte_E552C = byte_DCAEC ^ 0x30;
                    byte_E552D = byte_DCAED ^ 0x7D;
                    v9 = 1202922957;
                    byte_E552E = byte_DCAEE ^ 0x9C;
                    v66[34] = 16;
                    v66[33] = 38;
                    v10 = -1548342424;
                  }
                }
                else
                {
                  v66[40] = 109;
                  v66[39] = 2;
                  v9 = 1202922957;
                  v10 = 1353745436;
                }
              }
              else if ( v10 > 441023297 )
              {
                v66[16] = 148;
                v66[15] = 351;
                v9 = 1202922957;
                v10 = -909150152;
              }
              else
              {
                v10 = -1849749670;
                if ( *((_BYTE *)v6 - 137) )
                  v10 = -1582505180;
              }
            }
            else if ( v10 > 169767366 )
            {
              if ( v10 > 309053726 )
              {
                if ( v10 == 309053727 )
                {
                  __dmb(0xBu);
                  dword_EEE58 = 1;
                  *(v6 - 32) = v119;
                  *(v6 - 31) = v116;
                  v116[18] = v119;
                  v116[19] = v119;
                  v117 = v119;
                  v118 = v119;
                  v116[17] = 479398;
                  a4 = v119;
                  *(v6 - 30) = v119;
                  *(v6 - 29) = v119;
                  v117 = (_DWORD *)(unsigned __int8)v117;
                  v10 = 1202922958;
                  v9 = 1202922957;
                  if ( !(((int)v117 * (int)v117 + 1) % 7u) )
                    v10 = -381279259;
                }
                else
                {
                  v24 = (_DWORD *)*(v6 - 32);
                  dword_EEE20 = *(v6 - 24);
                  v25 = (*(int (__fastcall **)(_DWORD, char *))(*(_DWORD *)*v24 + 24))(*v24, &byte_E5510);
                  *(v6 - 21) = v25;
                  v111[657] = v25;
                  v111[658] = 449;
                  v111[659] = v26;
                  v111[660] = a4;
                  v111[656] = 474108;
                  v27 = *(v6 - 21);
                  v102 = 449;
                  v101 = 153;
                  v8 = -1092892356;
                  v10 = 1540291310;
                  v9 = 1202922957;
                  *((_BYTE *)v6 - 77) = v27 != 0;
                }
              }
              else if ( v10 == 169767367 )
              {
                v34 = dword_EEE2C;
                __dmb(0xBu);
                v66[10] = 415;
                v66[9] = 251;
                a4 = (_DWORD *)&unk_300D8;
                v10 = 729136515;
                v14 = v34 == 0;
                v35 = 0;
                LOWORD(v9) = 9677;
                if ( v14 )
                  v35 = 1;
                HIWORD(v9) = 18355;
                *((_BYTE *)v6 - 138) = v35;
              }
              else
              {
                *(v6 - 40) = 93;
                *(v6 - 41) = 257;
                v19 = *(v6 - 40) + *(v6 - 40) * *(v6 - 40) + 7;
                v10 = -567837442;
                if ( v19 == 81 * (v19 / 0x51) )
                  v10 = -64647748;
                if ( (int)*(v6 - 41) <= 185 )
                  v10 = -567837442;
                v9 = 1202922957;
              }
            }
            else if ( v10 > 42386026 )
            {
              if ( v10 == 42386027 )
              {
                v10 = -1264071445;
              }
              else
              {
                v10 = 1110672738;
                if ( *((_BYTE *)v6 - 133) )
                  v10 = -860245807;
              }
            }
            else if ( v10 == -64647748 )
            {
              v10 = 299071115;
            }
            else
            {
              byte_E5521 = byte_DCAE1 ^ 0x9F;
              byte_E5522 = byte_DCAE2 ^ 0x9C;
              byte_E5523 = byte_DCAE3 ^ 0x4A;
              v9 = 1202922957;
              byte_E5524 = byte_DCAE4 ^ 0xE2;
              v66[22] = 13;
              v66[21] = 126;
              v10 = -2088117646;
            }
          }
          if ( v10 <= 1579310616 )
            break;
          if ( v10 > 1713093707 )
          {
            if ( v10 > 1966400795 )
            {
              if ( v10 > 2052554883 )
              {
                __dmb(0xBu);
                dword_EEE4C = 1;
                v30 = dword_EEE50;
                __dmb(0xBu);
                v66[70] = 92;
                v66[69] = 93;
                a4 = (_DWORD *)&unk_51;
                v10 = -1048516463;
                v9 = 1202922957;
                *((_BYTE *)v6 - 131) = v30 == 0;
              }
              else
              {
                __dmb(0xBu);
                dword_EEE3C = 1;
                v37 = dword_EEE40;
                __dmb(0xBu);
                v66[46] = 210;
                v66[45] = 69;
                a4 = (_DWORD *)&unk_1D779;
                v10 = -272970211;
                v14 = v37 == 0;
                v38 = 0;
                LOWORD(v9) = 9677;
                if ( v14 )
                  v38 = 1;
                HIWORD(v9) = 18355;
                *((_BYTE *)v6 - 134) = v38;
              }
            }
            else if ( v10 > 1868724095 )
            {
              if ( v10 == 1868724096 )
              {
                v100 = 29;
                v99 = 27;
                v9 = 1202922957;
                v10 = 359358929;
              }
              else
              {
                v10 = 1758425489;
              }
            }
            else if ( v10 == 1713093708 )
            {
              v10 = 1110672738;
            }
            else
            {
              v66[52] = 157;
              v66[51] = 422;
              v9 = 1202922957;
              v10 = 1692495761;
            }
          }
          else if ( v10 > 1655508070 )
          {
            if ( v10 > 1681807348 )
            {
              __dmb(0xBu);
              dword_EEE44 = 1;
              v28 = dword_EEE48;
              __dmb(0xBu);
              v66[54] = 117;
              v66[53] = 216;
              a4 = (_DWORD *)&unk_3D18;
              v10 = 156193097;
              v14 = v28 == 0;
              v29 = 0;
              LOWORD(v9) = 9677;
              if ( v14 )
                v29 = 1;
              HIWORD(v9) = 18355;
              *((_BYTE *)v6 - 133) = v29;
            }
            else
            {
              ((void (__fastcall *)(_DWORD, _DWORD))dword_77C84[0])(*(_DWORD *)*(v6 - 32), *(v6 - 19));
              *(v6 - 44) = 117;
              *(v6 - 45) = 296;
              v8 = -1092892356;
              v36 = *(v6 - 44) + *(v6 - 44) * *(v6 - 44) + 7;
              v9 = 1202922957;
              v10 = 719621082;
              if ( v36 == 81 * (v36 / 0x51) )
                v10 = -1603528414;
              if ( (int)*(v6 - 45) <= 302 )
                v10 = 719621082;
            }
          }
          else if ( v10 > 1609481109 )
          {
            if ( v10 == 1609481110 )
            {
              __dmb(0xBu);
              dword_EEE50 = 1;
              v39 = dword_EEE54;
              __dmb(0xBu);
              v74 = 103;
              v73 = 384;
              a4 = (_DWORD *)&unk_2F58;
              v10 = -1825725365;
              v14 = v39 == 0;
              v40 = 0;
              LOWORD(v9) = 9677;
              if ( v14 )
                v40 = 1;
              HIWORD(v9) = 18355;
              *((_BYTE *)v6 - 130) = v40;
            }
            else
            {
              v104 = 29;
              v103 = 9;
              v10 = -1618417233;
            }
          }
          else if ( v10 == 1579310617 )
          {
            v10 = 1607041602;
          }
          else
          {
            v72 = 295;
            v71 = 210;
            v10 = 1609481110;
          }
        }
        if ( v10 > 1528049683 )
          break;
        if ( v10 > 1337831982 )
        {
          if ( v10 > 1451987440 )
          {
            if ( v10 == 1451987441 )
            {
              v10 = 169767367;
            }
            else
            {
              v10 = 1247267520;
              *v7 = *(v6 - 27);
              v5 = *(v6 - 26);
              v4 = *(v6 - 25);
            }
          }
          else
          {
            byte_E5530 = byte_DCAF0 ^ 0x16;
            byte_E5531 = byte_DCAF1 ^ 0x98;
            byte_E5532 = byte_DCAF2 ^ 0x98;
            byte_E5533 = byte_DCAF3 ^ 0x22;
            byte_E5534 = byte_DCAF4 ^ 0x1C;
            byte_E5535 = byte_DCAF5 ^ 0xE7;
            byte_E5536 = byte_DCAF6 ^ 0x8F;
            byte_E5537 = byte_DCAF7 ^ 0xEF;
            byte_E5538 = byte_DCAF8 ^ 0x81;
            byte_E5539 = byte_DCAF9 ^ 0xAC;
            byte_E553A = byte_DCAFA ^ 0xE5;
            byte_E553B = byte_DCAFB ^ 0x5D;
            byte_E553C = byte_DCAFC ^ 0x37;
            byte_E553D = byte_DCAFD ^ 0x91;
            byte_E553E = byte_DCAFE ^ 1;
            byte_E553F = byte_DCAFF ^ 0x97;
            byte_E5540 = byte_DCB00 ^ 0x71;
            byte_E5541 = byte_DCB01 ^ 0x84;
            byte_E5542 = byte_DCB02 ^ 0xE7;
            byte_E5543 = byte_DCB03 ^ 0x16;
            byte_E5544 = byte_DCB04 ^ 0x4B;
            byte_E5545 = byte_DCB05 ^ 0xAB;
            byte_E5546 = byte_DCB06 ^ 0xDE;
            v66[42] = 126;
            v66[41] = 455;
            v9 = 1202922957;
            v10 = -300802084;
          }
        }
        else if ( v10 > 1247267519 )
        {
          v96 = 22;
          v95 = 7;
          *(v6 - 14) = v5;
          *(v6 - 15) = *v7;
          v10 = -1709362745;
          *(v6 - 13) = v4;
        }
        else if ( v10 == 1202922958 )
        {
          *(_DWORD *)(dword_E1760 + 20) = dword_E17C0 + 4656;
          *v7 = 0;
          ((void (__fastcall *)(int, _DWORD, int, int))unk_BDBC)(dword_E1AD8, 0, 4656, dword_E1760);
          ((void (__fastcall *)(int, _DWORD))unk_BDBC)(dword_E1ADC, 0);
          ((void (__fastcall *)(int, _DWORD))unk_BDBC)(dword_E1AE0, 0);
          ((void (__fastcall *)(int, _DWORD))unk_BDBC)(dword_E1AE4, 0);
          ((void (__fastcall *)(_DWORD, _DWORD, int, int))unk_BDBC)(unk_E1AE8, 0, v31, v32);
          ((void (__fastcall *)(int, _DWORD))unk_BDBC)(dword_E1AEC, 0);
          ((void (__fastcall *)(int, _DWORD))unk_BDBC)(dword_E1AF0, 0);
          v112 = ((__int64 (__fastcall *)(void *, _DWORD))unk_BDBC)(&unk_EEE28, 0);
          v113 = v33;
          v114 = a4;
          v115 = v6;
          v111[998] = 476648;
          v10 = 1214228038;
          *(v6 - 28) = v7[4];
          v9 = 1202922957;
          v8 = -1092892356;
          if ( !*(v6 - 28) )
            v10 = 1247267520;
          v5 = 0;
          v4 = 0;
        }
        else
        {
          v92 = 5;
          v91 = 28;
          v9 = 1202922957;
          v10 = -465942479;
        }
      }
      if ( v10 <= 1537678585 )
        break;
      if ( v10 == 1537678586 )
      {
        *(_BYTE *)(dword_75820 + 480586) = *(_BYTE *)(dword_7581C + 480584) ^ 0xDE;
        *(_BYTE *)(dword_75820 + 480587) = *(_BYTE *)(dword_7581C + 480585) ^ 0xF3;
        *(_BYTE *)(dword_75820 + 480588) = *(_BYTE *)(dword_7581C + 480586) ^ 0x3E;
        *(_BYTE *)(dword_75820 + 480589) = *(_BYTE *)(dword_7581C + 480587) ^ 0x99;
        v9 = 1202922957;
        *(_BYTE *)(dword_75820 + 480590) = *(_BYTE *)(dword_7581C + 480588) ^ 0xAB;
        v70 = 32;
        v69 = 94;
        v10 = 1579310617;
      }
      else if ( v10 == 1540291310 )
      {
        v10 = 1028868465;
        if ( *((_BYTE *)v6 - 77) )
          v10 = -732367793;
        v7[3] = -1;
      }
      else
      {
        v10 = 743973074;
      }
    }
    if ( v10 == 1534835701 )
      break;
    v10 = -1096468175;
  }
  result = *(v6 - 10);
  if ( *(_DWORD *)v7[5] == v7[6] )
    return result;
  ((void (__fastcall *)(int))unk_B96C)(result);
  JUMPOUT(0x75804);
  return result;
}
