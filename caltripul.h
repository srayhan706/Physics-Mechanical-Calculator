#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

TTF_Font* sfont=NULL;
string ss1,ss2,ss3;
SDL_Rect srect[20];

bool initial(){
    bool suc=true;
    if(TTF_Init()<0){
        printf("Did not succeed\n");
        suc=false;
    }
    SDL_StartTextInput();
    return suc;
}

void stop(){
    TTF_CloseFont(sfont);
    sfont=NULL;
    TTF_Quit();
}
void Caltripulaccten(SDL_Window* waindow,SDL_Renderer* render,SDL_Texture* stex,string st1,string st2,string st3,string st4){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass1,mass2,gravity=9.8,ang1,ang2,theta1,theta2,acc,tension;
    mass1=stod(st1);
    mass2=stod(st2);
    theta1=stod(st3);
    theta2=stod(st4);
    ang1=(M_PI*theta1)/(180.0);
    ang2=(M_PI*theta2)/(180.0);
    acc=(gravity*(abs((mass1*ang1)-(mass2*ang2))))/((mass1*1.0)+(mass2*1.0));
    tension=(mass1*mass2*gravity*(sin(ang1)+sin(ang2)))/((mass1*1.0)+(mass2*1.0));
    ss1=to_string(acc);
    ss1+=" m/s2";
    ss2=to_string(tension);
    ss2+=" N";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //SDL_Renderer* srender=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int mouse_x,mouse_y;
    SDL_Rect rect={560,450,50,50};
    int vel_x=1,vel_y=1;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(sfont,"Value Of Acceleration (a): ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[2]);
        //for tension
        surface= TTF_RenderText_Solid(sfont,"Value Of Tension (T): ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[6]);
        surface=IMG_Load("Pic/pulley2.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[3]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[16]);

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<1000)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
       double angle=30.55;
        SDL_SetRenderDrawColor(render,0,255,0,255);
        SDL_RenderDrawLine(render,400,690,650,690);
        SDL_RenderDrawLine(render,650,690,650,440);
        SDL_RenderDrawLine(render,400,690,650,440);

        SDL_SetRenderDrawColor(render,0,0,255,255);
        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;
        surface=IMG_Load("Pic/sphere.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        SDL_FreeSurface(surface);
        SDL_RenderCopyEx(render,stex,NULL,&rect,angle,NULL,flip);
        if(rect.x<=360&&rect.y>=670){
            rect.x=560;
            rect.y=450;
        }
        rect.x-=vel_x;
        rect.y+=vel_y;
        //SDL_RenderFillRect(srender,&rect);
        SDL_RenderPresent(render);
        //SDL_Delay(5000);
    }
    stop();
}

void Caltripul2ang(SDL_Window* waindow,SDL_Renderer* render,SDL_Texture* stex,string st1,string st2,string st3,string st4){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass1,mass2,gravity=9.8,ang1,ang2,theta1,theta2,acc,tension;
    mass1=stod(st1);
    mass2=stod(st2);
    acc=stod(st3);
    tension=stod(st4);
    theta1=asin((abs(tension-(mass1*acc)))/(mass1*9.8));
    theta2=asin((tension+(mass2*acc))/(mass2*9.8));
    ang1=(180.0*theta1)/M_PI;
    ang2=(180.0*theta2)/M_PI;
    ss1=to_string(ang1);
    ss1+=" ";
    ss2=to_string(ang2);
    ss2+=" ";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //SDL_Renderer* srender=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int mouse_x,mouse_y;
    SDL_Rect rect={560,450,50,50};
    int vel_x=1,vel_y=1;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle 1: ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[2]);
        //for tension
        surface= TTF_RenderText_Solid(sfont,"Value Of Angle 2: ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[6]);
        surface=IMG_Load("Pic/pulley2.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[3]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[16]);

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<1000)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
       double angle=30.55;
        SDL_SetRenderDrawColor(render,0,255,0,255);
        SDL_RenderDrawLine(render,400,690,650,690);
        SDL_RenderDrawLine(render,650,690,650,440);
        SDL_RenderDrawLine(render,400,690,650,440);

        SDL_SetRenderDrawColor(render,0,0,255,255);
        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;
        surface=IMG_Load("Pic/sphere.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        SDL_FreeSurface(surface);
        SDL_RenderCopyEx(render,stex,NULL,&rect,angle,NULL,flip);
        if(rect.x<=360&&rect.y>=670){
            rect.x=560;
            rect.y=450;
        }
        rect.x-=vel_x;
        rect.y+=vel_y;
        //SDL_RenderFillRect(srender,&rect);
        SDL_RenderPresent(render);
        //SDL_Delay(5000);
    }
    stop();
}

void Caltripul2mass(SDL_Window* waindow,SDL_Renderer* render,SDL_Texture* stex,string st1,string st2,string st3,string st4){
    if(!initial()){
        printf("Did not Initial\n");
        return;
    }
    double mass1,mass2,gravity=9.8,ang1,ang2,theta1,theta2,acc,tension;
    ang1=stod(st1);
    ang2=stod(st2);
    acc=stod(st3);
    tension=stod(st4);
    theta1=(M_PI*ang1)/180.0;
    theta2=(M_PI*ang2)/180.0;
    mass1=tension/(acc+(gravity*sin(theta1)));
    mass2=tension/abs(acc-(gravity*sin(theta2)));
    ss1=to_string(mass1);
    ss1+=" kg";
    ss2=to_string(ang2);
    ss2+=" kg";
    int run=1;
    sfont= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //SDL_Renderer* srender=NULL;
    //srender=SDL_CreateRenderer(swindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    int mouse_x,mouse_y;
    SDL_Rect rect={560,450,50,50};
    int vel_x=1,vel_y=1;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for acceleration
        surface= TTF_RenderText_Solid(sfont,"Value Of mass 1: ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[0]={30,350,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[0]);
        srect[1]={300,350,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[1]);
        surface = TTF_RenderText_Solid(sfont, ss1.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[2]={300,350,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[2]);
        //for tension
        surface= TTF_RenderText_Solid(sfont,"Value Of mass 2: ",color);
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[4]={30,390,250,25};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[4]);
        srect[5]={300,390,300,35};
        SDL_SetRenderDrawColor(render,255,0,127,255);
        SDL_RenderFillRect(render,&srect[5]);
        surface = TTF_RenderText_Solid(sfont, ss2.c_str(), color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[6]={300,390,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[6]);
        surface=IMG_Load("Pic/pulley2.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        srect[3]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,stex,NULL,&srect[3]);
        ////back button
        srect[7]={0,0,100,50};
        SDL_SetRenderDrawColor(render,140,200,30,140);
        SDL_RenderFillRect(render,&srect[7]);
        surface = TTF_RenderText_Solid(sfont, " BACK ", color);
        stex = SDL_CreateTextureFromSurface(render, surface);
        srect[16]={10,6,surface->w,surface->h};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render, stex, NULL, &srect[16]);

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                        if((mouse_x>0&&mouse_x<1000)&&(mouse_y>0&&mouse_y<50))
                        run=0;
                    break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
       double angle=30.55;
        SDL_SetRenderDrawColor(render,0,255,0,255);
        SDL_RenderDrawLine(render,400,690,650,690);
        SDL_RenderDrawLine(render,650,690,650,440);
        SDL_RenderDrawLine(render,400,690,650,440);

        SDL_SetRenderDrawColor(render,0,0,255,255);
        SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;
        surface=IMG_Load("Pic/sphere.png");
        stex=SDL_CreateTextureFromSurface(render,surface);
        SDL_FreeSurface(surface);
        SDL_RenderCopyEx(render,stex,NULL,&rect,angle,NULL,flip);
        if(rect.x<=360&&rect.y>=670){
            rect.x=560;
            rect.y=450;
        }
        rect.x-=vel_x;
        rect.y+=vel_y;
        //SDL_RenderFillRect(srender,&rect);
        SDL_RenderPresent(render);
        //SDL_Delay(5000);
    }
    stop();
}


