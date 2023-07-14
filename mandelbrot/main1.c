#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define COPY    "\nObfuscated C Mandelbrot-/Julia-set generator."\
                "\n(C)opyright 2000-2001 by Stijn Wolters (stijnw@xs4all.nl)"\
                "\nAll rights reserved. No warranties are given, use of this"\
                " code is at own risk."

#define USAGE   "\nUsage (see also http://www.xs4all.nl/~stijnw/ocmjg/):"\
                "\nrn rm in im xmax ymax esc maxiter type file a b invmode"

#define CLK_TCK	CLOCKS_PER_SEC


                                                        it
                                                       (r,i,
                                                      a,b,ev,
                                                     u,v,mi)
                                                      double
                                                      r,i,a,
                                                       b,ev
                                           ,u,    v;{double(h), c
                                            =r, d=i,x,y;int(j)=0, l
                                            =mi ,p=sqrt(l);while(l  >0)
                                             {j++;x=r*r;y=i*i;if(x+y>ev
                                             )break;h=r;r=x-y+a;i=2*h*
                                         i+ b;if(fabs(r-c)<u&&fabs(i-d
                                         )<v){l=0;break;}if(j>p){j=0;c
                                          =r;d=i;}l--;}return+l;}main(w
                                          ,z)char**z;{FILE*f;double(a), b
                                        ,e,r,i,s,t,u,v,h,co[04];long(xm)=
                          5    <        w?atoi(*(z+5)):300,ym=(6<w)?atoi
                          (* (z+        6)):300,x,y;int(c)=0,j=0,k,l,m=(w
                          >8)?atoi(*   (z+8)):100,n,o,p;char(lx)=xm>>8,hx
                          =xm%256,ly   =ym>>8,hy=ym%256;n=(w>9)?(z[9][0]|
                        32)=='m':1;o=  (w>9)?(('s'-(z[9][1]|32))+1):0;o=
                         (o<0||o>2)?0: o;h=clock();do{co[c]=(w>c+1)?atof
                        (*(z+c+1)):((c %2)?2:-2);}while(++c<4);f=fopen((
                      ( w>=11)?*(z+10):n?"Mandel.pcx":"Julia.pcx"),"wb+"
                    );if(!f)return+1;fprintf(f,"\x0a\x05\x1\x08%c%c%c"
 "%c%c%c%c%c%c%c%c%c",0,0,0,0,hx-1,lx,hy-1,ly,hx,lx,hy,ly);for(l=0;l<
                    48;l++)fputc(l<<2,f);fprintf(f,"%c\x1%c%c\x1",0,hx
                      , lx);for(l=0;l<59;l++)fputc(0,f);e=(w>7)?atof(*(z
                        +7)):4;u=(*(co +1)-*co)/xm;v=(*(co+3)-*(co+2))/(
                         ym);for(y=0;y <=ym-1;y++){for(x=0;x<=xm-1;x++){
                        s=*co+x*u;t=*  (co+3)-y*v;a=(n)?s:((w>11)?atof(z
                          [+11]):-1)   ;b=(n)?t:((w>12)?atof(*(z+12)):0);
                          r=(!n)?s:0   ;i=(!n)?t:0;l=it(r,i,a,b,e,u,v,m);
                          (o ==2        )?(k=it(r,n?i:i-v,a,!n?b:b-v,e,u,
                          v    ,        m),p=!((!j&&l)||(j&&!l)||(!k&&l)
                                        ||(k&&!l))):(p=l);j=l;fputc(o?(!p
                                          ?0:63):((!p)?0:(63-p%63)),f); }
                                          printf("\r%3.2f%%",(y+1)/(ym/
                                         100.0));fflush(stdout);}j=(w>
                                         13 )?(*z[13]|32)=='i':0;fputc
                                             (12,f);b=clock();printf((
                                             ",%fs.\n"),(b-h)/CLK_TCK);
                                            for (k=0;k<=767;k++){l  =j?
                                            767 -k:k;fputc((l/3)* (
                                           4),    f);}fclose(f) ;
                                                       puts
                                                      (COPY)
                                                      ;puts(
                                                     USAGE);
                                                      return(
                                                       (0));
                                                         ;}