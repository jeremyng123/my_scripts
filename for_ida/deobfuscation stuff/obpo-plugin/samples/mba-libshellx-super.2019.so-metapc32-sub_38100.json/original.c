int __usercall sub_38100@<eax>(unsigned __int16 *a1@<edx>, unsigned int a2@<ecx>, __m128i a3@<xmm0>, int *a4, unsigned int a5)
{
  int v6; // edx
  int v7; // eax
  int v8; // edi
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // edi
  __m128i v14; // xmm3
  int v15; // ecx
  int v16; // esi
  int v17; // eax
  unsigned int v18; // edx
  unsigned int v19; // ecx
  int v20; // esi
  __m128i v21; // xmm4
  __m128i v22; // xmm1
  __m128i v23; // xmm3
  __m128i v24; // xmm1
  __m128i v25; // xmm2
  __m128i v26; // xmm2
  __m128i v27; // xmm5
  __m128i v28; // xmm0
  __m128i v29; // xmm0
  __m128i v30; // xmm1
  __m128i v31; // xmm2
  __m128i v32; // xmm2
  __m128i v33; // xmm5
  __m128i v34; // xmm0
  int v35; // edx
  int v36; // edi
  int v37; // edx
  int result; // eax
  int *v39; // [esp+Ch] [ebp-280h]
  unsigned __int16 *v40; // [esp+10h] [ebp-27Ch]
  unsigned int v41; // [esp+14h] [ebp-278h]
  _DWORD *v42; // [esp+18h] [ebp-274h]
  bool v43; // [esp+1Dh] [ebp-26Fh]
  char v44; // [esp+1Eh] [ebp-26Eh]
  char v45; // [esp+1Fh] [ebp-26Dh]
  char v46; // [esp+20h] [ebp-26Ch]
  unsigned __int8 v47; // [esp+21h] [ebp-26Bh]
  char v48; // [esp+22h] [ebp-26Ah]
  unsigned __int8 v49; // [esp+23h] [ebp-269h]
  int v50; // [esp+24h] [ebp-268h]
  int v51; // [esp+24h] [ebp-268h]
  unsigned int v52; // [esp+28h] [ebp-264h]
  int v53; // [esp+2Ch] [ebp-260h]
  int v54; // [esp+30h] [ebp-25Ch]
  int v55; // [esp+34h] [ebp-258h]
  int v56; // [esp+38h] [ebp-254h]
  int v57; // [esp+3Ch] [ebp-250h]
  unsigned int v58; // [esp+40h] [ebp-24Ch]
  unsigned int v59; // [esp+44h] [ebp-248h]
  unsigned int v60; // [esp+48h] [ebp-244h]
  unsigned int v61; // [esp+4Ch] [ebp-240h]
  int v62; // [esp+50h] [ebp-23Ch]
  int v63; // [esp+54h] [ebp-238h]
  unsigned int v64; // [esp+58h] [ebp-234h]
  int v65; // [esp+5Ch] [ebp-230h]
  int v66; // [esp+60h] [ebp-22Ch]
  unsigned int v67; // [esp+64h] [ebp-228h]
  int v68; // [esp+68h] [ebp-224h]
  unsigned int v69; // [esp+6Ch] [ebp-220h]
  int v70; // [esp+70h] [ebp-21Ch]
  int v71; // [esp+70h] [ebp-21Ch]
  int v72; // [esp+74h] [ebp-218h]
  unsigned int v73; // [esp+78h] [ebp-214h]
  unsigned int v74; // [esp+7Ch] [ebp-210h]
  int v75; // [esp+80h] [ebp-20Ch]
  int v76; // [esp+84h] [ebp-208h]
  int v77; // [esp+88h] [ebp-204h]
  int v78; // [esp+8Ch] [ebp-200h]
  int v79; // [esp+90h] [ebp-1FCh]
  int v80; // [esp+94h] [ebp-1F8h]
  int v81; // [esp+98h] [ebp-1F4h]
  unsigned __int16 *v82; // [esp+9Ch] [ebp-1F0h]
  int v83; // [esp+A0h] [ebp-1ECh]
  int v84; // [esp+A4h] [ebp-1E8h]
  int v85; // [esp+A8h] [ebp-1E4h]
  int v86; // [esp+ACh] [ebp-1E0h]
  int v87; // [esp+B0h] [ebp-1DCh]
  int v88; // [esp+B4h] [ebp-1D8h]
  int v89; // [esp+B8h] [ebp-1D4h]
  int v90; // [esp+BCh] [ebp-1D0h]
  unsigned __int16 *v91; // [esp+C0h] [ebp-1CCh]
  int v92; // [esp+C4h] [ebp-1C8h]
  unsigned int v93; // [esp+C8h] [ebp-1C4h]
  unsigned int v94; // [esp+CCh] [ebp-1C0h]
  unsigned int v95; // [esp+D0h] [ebp-1BCh]
  int v96; // [esp+D4h] [ebp-1B8h]
  int v97; // [esp+D8h] [ebp-1B4h]
  int v98; // [esp+DCh] [ebp-1B0h]
  int v99; // [esp+E0h] [ebp-1ACh]
  int v100; // [esp+E4h] [ebp-1A8h]
  int v101; // [esp+E8h] [ebp-1A4h]
  int v102; // [esp+ECh] [ebp-1A0h]
  int v103; // [esp+F0h] [ebp-19Ch]
  int v104; // [esp+F4h] [ebp-198h]
  int v105; // [esp+F8h] [ebp-194h]
  int v106; // [esp+FCh] [ebp-190h]
  int v107; // [esp+100h] [ebp-18Ch]
  int v108; // [esp+104h] [ebp-188h]
  int v109; // [esp+108h] [ebp-184h]
  unsigned int v110; // [esp+10Ch] [ebp-180h]
  int *v111; // [esp+110h] [ebp-17Ch]
  unsigned __int16 *v112; // [esp+114h] [ebp-178h]
  unsigned int v113; // [esp+118h] [ebp-174h]
  unsigned int v114; // [esp+11Ch] [ebp-170h]
  unsigned int v115; // [esp+120h] [ebp-16Ch]
  int v116; // [esp+124h] [ebp-168h]
  unsigned int v117; // [esp+128h] [ebp-164h]
  unsigned __int16 *v118; // [esp+12Ch] [ebp-160h]
  int *v119; // [esp+130h] [ebp-15Ch]
  unsigned int v120; // [esp+134h] [ebp-158h]
  unsigned int v121; // [esp+138h] [ebp-154h]
  _BYTE *v122; // [esp+13Ch] [ebp-150h]
  int v123; // [esp+140h] [ebp-14Ch]
  int v124; // [esp+144h] [ebp-148h]
  int v125; // [esp+148h] [ebp-144h]
  int v126; // [esp+14Ch] [ebp-140h]
  unsigned int v127; // [esp+150h] [ebp-13Ch]
  unsigned int v128; // [esp+154h] [ebp-138h]
  unsigned int v129; // [esp+158h] [ebp-134h]
  unsigned int v130; // [esp+15Ch] [ebp-130h]
  int v131; // [esp+160h] [ebp-12Ch]
  int v132; // [esp+164h] [ebp-128h]
  int v133; // [esp+168h] [ebp-124h]
  int v134; // [esp+16Ch] [ebp-120h]
  int *v135; // [esp+170h] [ebp-11Ch]
  unsigned int *v136; // [esp+174h] [ebp-118h]
  int v137; // [esp+178h] [ebp-114h]
  int v138; // [esp+17Ch] [ebp-110h]
  int *v139; // [esp+180h] [ebp-10Ch]
  unsigned int v140; // [esp+184h] [ebp-108h]
  unsigned int v141; // [esp+188h] [ebp-104h]
  unsigned int v142; // [esp+18Ch] [ebp-100h]
  unsigned int v143; // [esp+190h] [ebp-FCh]
  int v144; // [esp+194h] [ebp-F8h]
  int v145; // [esp+198h] [ebp-F4h]
  unsigned int v146; // [esp+19Ch] [ebp-F0h]
  unsigned int v147; // [esp+1A0h] [ebp-ECh]
  unsigned __int16 *v148; // [esp+1A4h] [ebp-E8h]
  unsigned int v149; // [esp+1A8h] [ebp-E4h]
  unsigned int v150; // [esp+1ACh] [ebp-E0h]
  int v151; // [esp+1B0h] [ebp-DCh]
  int v152; // [esp+1B4h] [ebp-D8h]
  int v153; // [esp+1B8h] [ebp-D4h]
  int v154; // [esp+1BCh] [ebp-D0h]
  int v155; // [esp+1C0h] [ebp-CCh]
  int v156; // [esp+1C4h] [ebp-C8h]
  int v157; // [esp+1C8h] [ebp-C4h]
  int v158; // [esp+1CCh] [ebp-C0h]
  int v159; // [esp+1D0h] [ebp-BCh]
  int v160; // [esp+1D4h] [ebp-B8h]
  int v161; // [esp+1D8h] [ebp-B4h]
  int v162; // [esp+1DCh] [ebp-B0h]
  int v163; // [esp+1E0h] [ebp-ACh]
  unsigned int v164; // [esp+1E4h] [ebp-A8h]
  unsigned __int16 *v165; // [esp+1ECh] [ebp-A0h]
  unsigned int v166; // [esp+1F0h] [ebp-9Ch]
  unsigned __int8 *v167; // [esp+1F4h] [ebp-98h]
  int v168; // [esp+1F8h] [ebp-94h]
  _DWORD *v169; // [esp+1FCh] [ebp-90h]
  _BYTE *v170; // [esp+204h] [ebp-88h]
  unsigned int v171; // [esp+208h] [ebp-84h]
  unsigned int v172; // [esp+20Ch] [ebp-80h]
  unsigned int v173; // [esp+210h] [ebp-7Ch]
  _BYTE *v174; // [esp+214h] [ebp-78h]
  int v175; // [esp+218h] [ebp-74h]
  int v176; // [esp+21Ch] [ebp-70h]
  unsigned int v177; // [esp+220h] [ebp-6Ch]
  _BYTE *v178; // [esp+224h] [ebp-68h]
  unsigned int v179; // [esp+228h] [ebp-64h]
  unsigned __int8 *v180; // [esp+22Ch] [ebp-60h]
  unsigned int v181; // [esp+230h] [ebp-5Ch]
  int *v182; // [esp+234h] [ebp-58h]
  _BYTE v183[64]; // [esp+238h] [ebp-54h] BYREF
  int v184; // [esp+278h] [ebp-14h]

  v184 = *(_DWORD *)dword_3FD8C;
  v6 = 1817041339;
  if ( !a5 )
    v6 = 1332488870;
  v168 = v6;
  v167 = (unsigned __int8 *)(a2 + 128);
  v169 = (_DWORD *)a2;
  v7 = a2 + 64;
  v166 = a2 + 64;
  v8 = -1494591501;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( v8 <= 104595036 )
          {
            if ( v8 <= -985736833 )
            {
              if ( v8 > -1369963813 )
              {
                if ( v8 > -1183595433 )
                {
                  if ( v8 == -1183595432 )
                  {
                    v8 = -701314325;
                  }
                  else if ( v8 == -1181133112 )
                  {
                    v172 = v147 << 8;
                    a2 = HIBYTE(v147);
                    v173 = HIBYTE(v147);
                    v8 = -739444698;
                  }
                  else
                  {
                    v41 = v166;
                    *(_DWORD *)v166 = v54;
                    *(_DWORD *)(v166 + 4) = v55;
                    *(_DWORD *)(v166 + 8) = v56;
                    *(_DWORD *)(v166 + 12) = v57;
                    *(_DWORD *)(v166 + 16) = v58;
                    *(_DWORD *)(v166 + 20) = v59;
                    *(_DWORD *)(v166 + 24) = v60;
                    *(_DWORD *)(v166 + 28) = v61;
                    *(_DWORD *)(v166 + 32) = v62;
                    v73 = v166 + 36;
                    *(_WORD *)(v166 + 36) = v63;
                    v45 = BYTE2(v63);
                    a2 = v166 + 38;
                    v174 = (_BYTE *)(v166 + 38);
                    v8 = 2043915137;
                  }
                }
                else if ( v8 == -1369963812 )
                {
                  a2 = v93 + 1;
                  v177 = v93 + 1;
                  v8 = -1183595432;
                }
                else if ( v8 == -1327325526 )
                {
                  v8 = -1667608493;
                }
                else
                {
                  v49 = 64 - v52;
                  a2 = (unsigned int)v167;
                  v180 = v167;
                  v8 = 1907412205;
                }
              }
              else if ( v8 > -1625972520 )
              {
                if ( v8 == -1625972519 )
                {
                  v8 = 865651757;
                  a2 = -1044670562;
                  if ( v43 )
                    v8 = -1044670562;
                }
                else if ( v8 == -1535439727 )
                {
                  *(_BYTE *)(v74 + 2) = v46;
                  *(_BYTE *)(v74 + 3) = HIBYTE(v64);
                  *(_DWORD *)(v41 + 44) = v65;
                  *(_DWORD *)(v41 + 48) = v66;
                  *(_DWORD *)(v41 + 52) = v67;
                  *(_DWORD *)(v41 + 56) = v68;
                  *(_DWORD *)(v41 + 60) = v69;
                  a2 = HIBYTE(v69);
                  v8 = 865651757;
                }
                else
                {
                  v8 = 1810497602;
                }
              }
              else if ( v8 == -1875023108 )
              {
                v83 = v61 ^ ((*((unsigned __int8 *)v82 + 3) << 24) & v175 | (v175 | (*((unsigned __int8 *)v82 + 2) << 16)) ^ (*((unsigned __int8 *)v82 + 3) << 24));
                v84 = v62 ^ *((_DWORD *)v40 + 8);
                v85 = v63 ^ *((_DWORD *)v40 + 9);
                v86 = v64 ^ *((_DWORD *)v40 + 10);
                v87 = v65 ^ *((_DWORD *)v40 + 11);
                v88 = v66 ^ *((_DWORD *)v40 + 12);
                v89 = v67 ^ *((_DWORD *)v40 + 13);
                v90 = v68 ^ *((_DWORD *)v40 + 14);
                v91 = v40 + 30;
                v176 = v40[30];
                a2 = *((unsigned __int8 *)v40 + 62);
                v47 = *((_BYTE *)v40 + 62);
                v8 = 2145221106;
              }
              else if ( v8 == -1834143694 )
              {
                v119 = v139;
                v118 = (unsigned __int16 *)v139;
                v8 = 1065045693;
                a2 = v149;
                v115 = v149;
              }
              else
              {
                v8 = 297549867;
                v121 = 0;
              }
            }
            else if ( v8 <= -701314326 )
            {
              if ( v8 > -793126594 )
              {
                if ( v8 == -793126593 )
                {
                  a2 = v52 - 64;
                  v181 = v52 - 64;
                  v8 = -455795803;
                }
                else if ( v8 == -792305118 )
                {
                  v8 = 104564001;
                  a2 = v171;
                  v120 = v171;
                }
                else
                {
                  v165 = a1;
                  v9 = __ROL4__((v100 + v154) ^ v160, 16);
                  v10 = v9 + v158;
                  v11 = __ROL4__((v9 + v158) ^ v100, 12);
                  v12 = v11 + v100 + v154;
                  v13 = __ROL4__(v12 ^ v9, 8);
                  v71 = v13 + v10;
                  v14 = _mm_cvtsi32_si128(__ROL4__((v13 + v10) ^ v11, 7));
                  v15 = __ROL4__((v101 + v155) ^ v159, 16);
                  v16 = v15 + v163;
                  v17 = __ROL4__((v15 + v163) ^ v101, 12);
                  v18 = v17 + v101 + v155;
                  v19 = __ROL4__(v18 ^ v15, 8);
                  v20 = v19 + v16;
                  v51 = (v173 | v172) + v144;
                  v21 = _mm_cvtsi32_si128(__ROL4__(v51 ^ v145, 7));
                  v22 = _mm_cvtsi32_si128(v12);
                  a1 = v165;
                  v23 = _mm_unpacklo_epi32(v14, _mm_cvtsi32_si128(__ROL4__(v20 ^ v17, 7)));
                  v24 = _mm_add_epi32(
                          _mm_unpacklo_epi64(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v143), _mm_cvtsi32_si128(v140)),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v146), v22)),
                          _mm_unpacklo_epi64(_mm_unpacklo_epi32(_mm_cvtsi32_si128(v18), v21), v23));
                  v25 = _mm_xor_si128(
                          _mm_unpacklo_epi64(
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v13), _mm_cvtsi32_si128(v19)),
                            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v141), _mm_cvtsi32_si128(v173 | v172))),
                          v24);
                  v26 = _mm_or_si128(_mm_slli_epi32(v25, 0x10u), _mm_srli_epi32(v25, 0x10u));
                  a2 = v71 + _mm_cvtsi128_si32(_mm_shuffle_epi32(v26, 229));
                  v27 = _mm_unpacklo_epi64(
                          _mm_unpacklo_epi32(_mm_cvtsi32_si128(v51 + _mm_cvtsi128_si32(v26)), _mm_cvtsi32_si128(a2)),
                          _mm_unpacklo_epi32(
                            _mm_cvtsi32_si128(v20 + _mm_cvtsi128_si32(_mm_shuffle_epi32(v26, 78))),
                            _mm_cvtsi32_si128(v142 + _mm_cvtsi128_si32(_mm_shuffle_epi32(v26, 231)))));
                  v28 = _mm_xor_si128(_mm_unpacklo_epi64(_mm_unpacklo_epi32(_mm_cvtsi32_si128(v143), v21), v23), v27);
                  v29 = _mm_or_si128(_mm_slli_epi32(v28, 0xCu), _mm_srli_epi32(v28, 0x14u));
                  v30 = _mm_add_epi32(v24, v29);
                  v31 = _mm_xor_si128(v26, v30);
                  v32 = _mm_or_si128(_mm_slli_epi32(v31, 8u), _mm_srli_epi32(v31, 0x18u));
                  v33 = _mm_add_epi32(v27, v32);
                  v34 = _mm_xor_si128(v29, v33);
                  a3 = _mm_or_si128(_mm_slli_epi32(v34, 7u), _mm_srli_epi32(v34, 0x19u));
                  v7 = v151 - 2;
                  v50 = _mm_cvtsi128_si32(v33);
                  v72 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v33, 229));
                  v106 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v33, 78));
                  v70 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v33, 231));
                  v105 = _mm_cvtsi128_si32(v32);
                  v104 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v32, 229));
                  v103 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v32, 78));
                  v102 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v32, 231));
                  v107 = _mm_cvtsi128_si32(v30);
                  v53 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v30, 229));
                  v109 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v30, 78));
                  v108 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v30, 231));
                  v8 = 566106038;
                }
              }
              else if ( v8 == -985736832 )
              {
                v35 = __ROL4__((v98 + v152) ^ v162, 16);
                v36 = __ROL4__((v35 + v156) ^ v98, 12);
                v140 = v36 + v98 + v152;
                v141 = __ROL4__(v140 ^ v35, 8);
                v142 = v141 + v35 + v156;
                v143 = __ROL4__(v142 ^ v36, 7);
                v37 = __ROL4__((v99 + v153) ^ v161, 16);
                v144 = v37 + v157;
                v145 = __ROL4__(v99 ^ (v37 + v157), 12);
                a2 = v145 + v99 + v153;
                v146 = a2;
                v147 = a2 ^ v37;
                v8 = -1181133112;
              }
              else if ( v8 == -982258767 )
              {
                v44 = *((_BYTE *)v148 + v94);
                a2 = (unsigned int)&v183[v94];
                v170 = &v183[v94];
                v8 = 1002086742;
              }
              else
              {
                *v135 = v96;
                a2 = (unsigned int)v136;
                *v136 = v164;
                v8 = -1314581636;
              }
            }
            else if ( v8 <= -400637409 )
            {
              if ( v8 == -701314325 )
              {
                v8 = 518192825;
                a2 = v177;
                v117 = v177;
              }
              else if ( v8 == -665975104 )
              {
                v126 = v42[3];
                v127 = v42[4];
                v128 = v42[5];
                v129 = v42[6];
                a2 = v42[7];
                v130 = a2;
                v8 = -62399838;
              }
              else
              {
                a2 = (unsigned int)(v39 + 16);
                v182 = v39 + 16;
                v8 = 948632357;
              }
            }
            else if ( v8 > -62399839 )
            {
              if ( v8 == -62399838 )
              {
                v131 = v42[8];
                v132 = v42[9];
                v133 = v42[10];
                v134 = v42[11];
                v135 = v42 + 12;
                v116 = v42[12];
                v136 = v42 + 13;
                v114 = v42[13];
                v137 = v42[14];
                v138 = v42[15];
                v8 = -400637408;
                v113 = 0;
                v112 = a1;
                v111 = a4;
                a2 = a5;
                v110 = a5;
              }
              else
              {
                v94 = v120;
                v8 = 315455566;
                a2 = -982258767;
                if ( v120 < v52 )
                  v8 = -982258767;
              }
            }
            else if ( v8 == -400637408 )
            {
              v148 = v112;
              v149 = (unsigned int)v111;
              v93 = v114;
              v97 = v116;
              v52 = v110;
              v43 = v110 < 0x40;
              v8 = 1065045693;
              if ( v110 < 0x40 )
                v8 = 1117990146;
              v119 = v111;
              v118 = v112;
              a2 = v113;
              v115 = v113;
            }
            else
            {
              v8 = -1834143694;
            }
          }
          if ( v8 <= 1002086741 )
            break;
          if ( v8 > 1802790683 )
          {
            if ( v8 > 1907412204 )
            {
              if ( v8 == 1907412205 )
              {
                a2 = v49;
                *v180 = v49;
                v8 = 277704478;
              }
              else if ( v8 == 2043915137 )
              {
                *v174 = v45;
                *(_BYTE *)(v73 + 3) = HIBYTE(v63);
                v74 = v41 + 40;
                *(_WORD *)(v41 + 40) = v64;
                a2 = HIWORD(v64);
                v46 = BYTE2(v64);
                v8 = -1535439727;
              }
              else
              {
                v92 = v69 ^ ((*((unsigned __int8 *)v91 + 3) << 24) & v176 | (v176 | (v47 << 16)) ^ (*((unsigned __int8 *)v91 + 3) << 24));
                v96 = v97 + 1;
                v8 = 518192825;
                if ( v97 == -1 )
                  v8 = -1369963812;
                a2 = v93;
                v117 = v93;
              }
            }
            else if ( v8 == 1802790684 )
            {
              v54 = v152 + v123;
              v55 = v153 + v124;
              v56 = v154 + v125;
              v57 = v155 + v126;
              v58 = v98 + v127;
              v59 = v99 + v128;
              v60 = v100 + v129;
              v61 = v101 + v130;
              v62 = v156 + v131;
              v63 = v157 + v132;
              v64 = v158 + v133;
              a2 = v163 + v134;
              v65 = v163 + v134;
              v8 = 683336046;
            }
            else if ( v8 == 1810497602 )
            {
              v122 = v183;
              a2 = (unsigned int)v183;
              v8 = v168;
            }
            else
            {
              v42 = v169;
              v123 = *v169;
              v124 = v169[1];
              a2 = v169[2];
              v125 = a2;
              v8 = -665975104;
            }
          }
          else if ( v8 > 1265896513 )
          {
            if ( v8 == 1265896514 )
            {
              v8 = 104564001;
              v120 = 0;
            }
            else if ( v8 == 1332488870 )
            {
              v8 = 277704478;
            }
            else
            {
              v8 = 297549867;
              a2 = v179;
              v121 = v179;
            }
          }
          else if ( v8 == 1002086742 )
          {
            *v170 = v44;
            a2 = v94 + 1;
            v171 = v94 + 1;
            v8 = -792305118;
          }
          else if ( v8 == 1065045693 )
          {
            v150 = v115;
            v40 = v118;
            v39 = v119;
            v53 = v123;
            v109 = v124;
            v108 = v125;
            v107 = v126;
            a3 = _mm_unpacklo_epi64(
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v127), _mm_cvtsi32_si128(v128)),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v129), _mm_cvtsi32_si128(v130)));
            v70 = v131;
            v50 = v132;
            v72 = v133;
            v106 = v134;
            v105 = v137;
            v104 = v138;
            v103 = v97;
            v102 = v93;
            v8 = 566106038;
            v7 = 20;
          }
          else
          {
            v8 = 1265896514;
          }
        }
        if ( v8 > 518192824 )
          break;
        if ( v8 > 297549866 )
        {
          if ( v8 == 297549867 )
          {
            v95 = v121;
            v8 = -939707837;
            a2 = 289846144;
            if ( v121 < v52 )
              v8 = 289846144;
          }
          else if ( v8 == 315455566 )
          {
            a2 = (unsigned int)v183;
            v139 = (int *)v183;
            v8 = -364812147;
          }
          else
          {
            v8 = -939707837;
            a2 = -1327325526;
            if ( v43 )
              v8 = -1327325526;
          }
        }
        else if ( v8 == 104595037 )
        {
          *v178 = v48;
          a2 = v95 + 1;
          v179 = v95 + 1;
          v8 = 1748487395;
        }
        else if ( v8 == 277704478 )
        {
          a2 = (unsigned int)v122;
          v8 = 976680390;
        }
        else
        {
          v48 = *((_BYTE *)v39 + v95);
          a2 = v95 + v150;
          v178 = (_BYTE *)(v95 + v150);
          v8 = 104595037;
        }
      }
      if ( v8 > 865651756 )
        break;
      if ( v8 == 518192825 )
      {
        v164 = v117;
        *v39 = v75;
        v39[1] = v76;
        v39[2] = v77;
        v39[3] = v78;
        v39[4] = v79;
        v39[5] = v80;
        v39[6] = v81;
        v39[7] = v83;
        v39[8] = v84;
        v39[9] = v85;
        v39[10] = v86;
        v39[11] = v87;
        v39[12] = v88;
        v39[13] = v89;
        v39[14] = v90;
        v39[15] = v92;
        v8 = -793126593;
        a2 = 404472080;
        if ( v52 < 0x41 )
          v8 = 404472080;
      }
      else if ( v8 == 566106038 )
      {
        v151 = v7;
        v152 = v53;
        v153 = v109;
        v154 = v108;
        v155 = v107;
        v98 = _mm_cvtsi128_si32(a3);
        v99 = _mm_cvtsi128_si32(_mm_shuffle_epi32(a3, 229));
        v100 = _mm_cvtsi128_si32(_mm_shuffle_epi32(a3, 78));
        v101 = _mm_cvtsi128_si32(_mm_shuffle_epi32(a3, 231));
        v156 = v70;
        v157 = v50;
        v158 = v72;
        v159 = v104;
        v160 = v105;
        v161 = v102;
        v162 = v103;
        v163 = v106;
        v8 = -985736832;
        a2 = 1802790684;
        if ( !v7 )
          v8 = 1802790684;
      }
      else
      {
        v66 = v162 + v97;
        v67 = v161 + v93;
        v68 = v160 + v137;
        a2 = v159 + v138;
        v69 = v159 + v138;
        v8 = -1625972519;
      }
    }
    if ( v8 == 976680390 )
      break;
    if ( v8 == 865651757 )
    {
      v75 = v54 ^ (*v40 | (*((unsigned __int8 *)v40 + 2) << 16) | (*((unsigned __int8 *)v40 + 3) << 24));
      v76 = v55 ^ *((_DWORD *)v40 + 1);
      v77 = v56 ^ *((_DWORD *)v40 + 2);
      v78 = v57 ^ *((_DWORD *)v40 + 3);
      v79 = v58 ^ *((_DWORD *)v40 + 4);
      v80 = v59 ^ *((_DWORD *)v40 + 5);
      v81 = v60 ^ *((_DWORD *)v40 + 6);
      v82 = v40 + 14;
      a2 = *((unsigned __int8 *)v40 + 28);
      v175 = v40[14];
      v8 = -1875023108;
    }
    else
    {
      v112 = v40 + 32;
      v116 = v96;
      v110 = v181;
      v111 = v182;
      v114 = v164;
      v8 = -400637408;
      a2 = v150;
      v113 = v150;
    }
  }
  result = *(_DWORD *)dword_3FD8C;
  if ( *(_DWORD *)dword_3FD8C == v184 )
    return result;
  ((void (__fastcall *)(unsigned int))unk_1AA0)(a2);
  JUMPOUT(0x3994D);
  return result;
}
