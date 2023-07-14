#include<stdio.h>
#include<stdlib.h>

#define COPY    "\nObfuscated C Mandelbrot-/Julia-set generator."\
                "\n(C)opyright 2000-2001 by Stijn Wolters (stijnw@xs4all.nl)"\
                "\nAll rights reserved. No warranties are given, use of this"\
                " code is at own risk."

#define USAGE   "\nUsage (see also http://www.xs4all.nl/~stijnw/ocmjg/):"\
                "\nrn rm in im xmax ymax esc maxiter type file a b invmode"



                                                        q(
                                                       r,i,a
                                                      ,b,e,m)
                                                     double(
                                                      r),i,a
                                                      ,b,e;{
                                                       int(
                                           l);    double(h),u,v ;
                                            for (l=m;l>0;l--){h=r ;
                                            u=r *r;v=i*i;if(e<=(u+  v))
                                             break;r=u-v+a;i=(h+h)*i+b;
                                             }return(l);}main(int(argc
                                         ), char*argv[]){FILE*f;double
                                         a,b,e,r,i,s,t,u,v,co[4]={0,0,
                                          0,0};long(x)=0,y=0,xm=(5<argc
                                          )?atoi(argv[5]):30000,ym=(argc> 6
                                        )?atoi(argv[6]):30000;int(c)=0,j=0,
                          k    ,        l,m=(argc>8)?atoi(*(argv+8)):100
                          ,n ,o,        p;char(hx)=xm%0x100,lx=xm>>8,(hy)
                          =ym%0x100,   ly=ym>>8;n=(argc>9)?(((*(argv+9))[
                          0]|0x20)==   'm'):1;o=(argc>9)?(('s'-(((*(argv+
                        9))[1])|0x20)  )+1):0;o=(o>2||o<0)?0:o;;do{co[c]
                         =((argc>c+1)? atof(*(argv+c+1)):((c%2)?2:-2));}
                        while(++c<=3); if(!(f=fopen(((argc>=11)?argv[10]
                      : (n)?"Mandel.pcx":"Julia.pcx"),"wb+")))return(1);
                    fprintf(f,"\x0a\x5\x1\x8%c%c%c%c%c%c%c%c%c%c%c%c",
 0,0,0,0,hx-1,lx,hy-1,ly,hx,lx,hy,ly);for(l=0;l<=47;l++)fputc(l<<2,f)
                    ;fprintf(f,"%c\x01%c%c\x01",0,hx,lx);for(l=0;l<=58
                      ; l++)fputc(0,f);e=(argc>7)?atof(*(argv+7)):4;u=(*
                        (co+1)-*co)/xm ;v=(*(co+3)-*(co+2))/ym;;for(y=0;
                         y<=ym-1;y++){ for(x=0;x<=xm-1;x++){s=*co+x*u;t=
                        *(co+3)-y*v;a  =(n)?s:((argc>11)?atof(*(argv+11)
                          ):-1);b=(n   )?t:((argc>12)?atof(*(argv+12)):0)
                          ;r=(!n)?s:   0;i=(!n)?t:0;l=q(r,i,a,b,e,m);(o==
                          2) ?(k        =q(r,n?i:i-v,a,!n?b:b-v,e,m),p=!(
                          (    !        j&&l)||(j&&!l)||(!k&&l)||(k&&!l)
                                        )):(p=l);j=l;fputc((o)?((!p)?(0):
                                          (63)):(!p)?(0):(63-(p%63)),f) ;
                                          }printf("\r%3d%%",(int)((y+1)
                                         /(ym/100.0)));}fputc(0x0C,f);
                                         j= (argc>13)?(((*(argv+13))[0
                                             ]|0x20)=='i'):(0);for(k=0
                                             ;k<=0xFF;k++){l=(j)?0xFF-k
                                            :k; fprintf(f,"%c%c%c"  ,(l
                                            <<2 ),(l<<2),(l<<2)); }
                                           if(    f){fclose(f); }
                                                       puts
                                                      (COPY)
                                                      ;puts(
                                                     USAGE);
                                                      return(
                                                       (0));
                                                         ;} 

/*

Parameter	Default value	Description
remin	-2	Min. for real part of values.
remax	2	Max. for real part of values.
immin	-2	Min. for imaginary part of values.
immax	2	Max. for imaginary part of values.
xmax	300	Width of the image.
ymax	300	Height of the image.
escval	4	Escape value ^ 2.
maxiter	100	Total number of iterations.
type	ME	Select (M)andelbrot- / (J)ulia-set
(E)scapetime / (S)olid and (R) Boundarytrace.
filename	Mandel.pcx	Name of the file.
Julia.pcx	
re-c	-1	Real part of c.
im-c	0	Imaginary part of c.
palette	N	Select (N)ormal or (I)nverse palette.
Please note that for type:

M = Mandelbrot-set, any other character Julia-set
E = Escapetime Diagram, S = Solid and R = Boundarytrace
*/