#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include "caltripul.h"

using namespace std;


TTF_Font* font=NULL;
string st1,st2,st3,st4,st5,st6;



bool Pinit(){
    bool suc=true;
    if(TTF_Init()<0){
        printf("Did not succeed\n");
        suc=false;
    }
    SDL_StartTextInput();
    return suc;
}

void Pfinish(){
    SDL_StopTextInput();
    TTF_CloseFont(font);
    font=NULL;
    TTF_Quit();
}
void mass1(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface= TTF_RenderText_Solid(font,"Give the value of mass 1 (m1): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,350,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={300,350,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}
void mass2(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface=TTF_RenderText_Solid(font,"Give the value of mass 2 (m2):",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    rect1={30,400,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    rect2={350,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}
void theta1(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface=TTF_RenderText_Solid(font,"Give the value of angle 1: ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,450,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,450,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}
void theta2(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface=TTF_RenderText_Solid(font,"Give the value of angle 2: ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,490,300,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={350,490,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);

}
void acc(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface= TTF_RenderText_Solid(font,"Give the value of acceleration (a): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,350,250,25};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={300,350,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}


void ten(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    surface=TTF_RenderText_Solid(font,"Give the value of tension (T): ",color);
    tex=SDL_CreateTextureFromSurface(render,surface);
    //rect1={30,450,300,25};;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render,tex,NULL,&rect1);
    //rect2={480,400,300,30};
    SDL_SetRenderDrawColor(render,0,153,153,0);
    SDL_RenderFillRect(render,&rect2);
}


void calc_button(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(font, " CALCULATE ", color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={550,610,200,40};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}

void back_button(SDL_Renderer* render,SDL_Surface* surface,SDL_Texture* tex,SDL_Rect rect1,SDL_Rect rect2)
{
    SDL_Color color={255,255,255};
    SDL_SetRenderDrawColor(render,140,200,30,140);
    SDL_RenderFillRect(render,&rect1);
    surface = TTF_RenderText_Solid(font, " BACK ", color);
    tex = SDL_CreateTextureFromSurface(render, surface);
    rect2={10,6,surface->w,surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(render, tex, NULL, &rect2);
}
void tripul_acc_ten(SDL_Window* window, SDL_Renderer* render, SDL_Texture* tex){
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Rect rect[20];
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event e;
    bool renderText=false;
    int mouse_x,mouse_y;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass 1
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass1(render,surface,tex,rect[0],rect[4]);
        //for mass 2
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        mass2(render,surface,tex,rect[1],rect[5]);
        //for theta 1
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        theta1(render,surface,tex,rect[2],rect[6]);
        //for image
        surface=IMG_Load("Pic/pulley2.png");
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        //for theta 2
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        theta2(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        rect[17]={10,6,surface->w,surface->h};
        back_button(render,surface,tex,rect[14],rect[17]);

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();st4.clear();
                    run=0;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch(e.button.button){
                        case SDL_BUTTON_LEFT:
                        if((mouse_x>=500&&mouse_x<=700)&&(mouse_y>=600&&mouse_y<=640)){
                            if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                            else {
                                Caltripulaccten(window,render,tex,st1,st2,st3,st4);
                                st1.clear();st2.clear();st3.clear();st4.clear();
                            }
                        }
                        else if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                            st1.clear();st2.clear();st3.clear();st4.clear();
                            run=0;
                        }
                        break;
                    }
                case SDL_TEXTINPUT:
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480))
                        st3+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st4+=e.text.text;
                    break;
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)&&st3.size())
                    st3.pop_back();
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520)&&st4.size())
                    st4.pop_back();
				}
				break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3].x=300;
            rect[3].y=350;
            rect[3].w=surface->w;
            rect[3].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={350,400,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={350,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(font, st4.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12]={350,490,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }

        SDL_RenderPresent(render);
        }
        Pfinish();
}

void tripul_2ang(SDL_Window* window, SDL_Renderer* render, SDL_Texture* tex){
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Rect rect[20];
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event e;
    bool renderText=false;
    int mouse_x,mouse_y;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for mass 1
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        mass1(render,surface,tex,rect[0],rect[4]);
        //for mass 2
        rect[1]={30,400,450,25};
        rect[5]={480,400,300,30};
        mass2(render,surface,tex,rect[1],rect[5]);
        //for acceleration
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        acc(render,surface,tex,rect[2],rect[6]);
        //for image
        surface=IMG_Load("Pic/pulley2.png");
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        //for tension
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        ten(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        rect[17]={10,6,surface->w,surface->h};
        back_button(render,surface,tex,rect[14],rect[17]);

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();st4.clear();
                    run=0;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch(e.button.button){
                        case SDL_BUTTON_LEFT:
                        if((mouse_x>=500&&mouse_x<=700)&&(mouse_y>=600&&mouse_y<=640)){
                            if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                            else {
                                Caltripul2ang(window,render,tex,st1,st2,st3,st4);
                                st1.clear();st2.clear();st3.clear();st4.clear();
                            }
                        }
                        else if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                            st1.clear();st2.clear();st3.clear();st4.clear();
                            run=0;
                        }
                        break;
                    }
                case SDL_TEXTINPUT:
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480))
                        st3+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st4+=e.text.text;
                    break;
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)&&st3.size())
                    st3.pop_back();
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520)&&st4.size())
                    st4.pop_back();
				}
				break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3].x=300;
            rect[3].y=350;
            rect[3].w=surface->w;
            rect[3].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={350,400,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={350,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(font, st4.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12]={350,490,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }

        SDL_RenderPresent(render);
        }
        Pfinish();
}


void tripul_2mass(SDL_Window* window, SDL_Renderer* render, SDL_Texture* tex){
    if(!Pinit()){
        printf("ERROR %s\n",SDL_GetError());
        return;
    }
    font= TTF_OpenFont("Ubuntu/Ubuntu-Bold.ttf",26);
    SDL_Surface* surface=NULL;
    //render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(render,255,255,255,255);
    SDL_RenderClear(render);
    //static const unsigned char* keys = SDL_GetKeyboardState( NULL );
    if(!render)printf("NOT RENDERED %s\n",SDL_GetError());
    SDL_Color color={255,255,255};
    SDL_Rect rect[20];
    //SDL_RenderPresent(render);
    int run=1;
    SDL_Event e;
    bool renderText=false;
    int mouse_x,mouse_y;
    while(run){
        SDL_SetRenderDrawColor(render,0,20,55,0);
        SDL_RenderClear(render);
        //for theta 1
        rect[0]={30,350,250,25};
        rect[4]={300,350,300,30};
        theta1(render,surface,tex,rect[0],rect[4]);
        //for theta 2
        rect[1]={30,400,300,25};
        rect[5]={350,400,300,30};
        theta2(render,surface,tex,rect[1],rect[5]);
        //for accleration
        rect[2]={30,450,300,25};
        rect[6]={350,450,300,30};
        acc(render,surface,tex,rect[2],rect[6]);
        //for image
        surface=IMG_Load("Pic/pulley2.png");
        tex=SDL_CreateTextureFromSurface(render,surface);
        rect[7]={300,10,350,300};
        SDL_FreeSurface(surface);
        SDL_RenderCopy(render,tex,NULL,&rect[7]);
        //for tension
        rect[10]={30,490,300,25};
        rect[11]={350,490,300,30};
        ten(render,surface,tex,rect[10],rect[11]);
        ////for calculation button
        rect[13]={500,600,300,60};
        rect[16]={550,610,200,40};
        calc_button(render,surface,tex,rect[13],rect[16]);
        //for backButton
        rect[14]={0,0,100,50};
        rect[17]={10,6,surface->w,surface->h};
        back_button(render,surface,tex,rect[14],rect[17]);

        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    st1.clear();st2.clear();st3.clear();st4.clear();
                    run=0;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_x=e.motion.x;
                    mouse_y=e.motion.y;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    switch(e.button.button){
                        case SDL_BUTTON_LEFT:
                        if((mouse_x>=500&&mouse_x<=700)&&(mouse_y>=600&&mouse_y<=640)){
                            if(!st1.size()||!st2.size()||!st3.size()||!st4.size())
                            SDL_ShowSimpleMessageBox(10,"Invalid","Please fill Every box!",window);
                            else {
                                Caltripul2mass(window,render,tex,st1,st2,st3,st4);
                                st1.clear();st2.clear();st3.clear();st4.clear();
                            }
                        }
                        else if((mouse_x>=0&&mouse_x<=100)&&(mouse_y>=0&&mouse_y<=50)){
                            st1.clear();st2.clear();st3.clear();st4.clear();
                            run=0;
                        }
                        break;
                    }
                case SDL_TEXTINPUT:
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)){
                        st1+=e.text.text;
                    }
                    else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430))
                        st2+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480))
                        st3+=e.text.text;
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520))
                        st4+=e.text.text;
                    break;
                case SDL_KEYDOWN:
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
                    if((mouse_x>=300&&mouse_x<=600)&&(mouse_y>=350&&mouse_y<=375)&&st1.size())
					st1.pop_back();
					else if((mouse_x>=480&&mouse_x<=780)&&(mouse_y>=400&&mouse_y<=430)&&st2.size())
					st2.pop_back();
					else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=450&&mouse_y<=480)&&st3.size())
                    st3.pop_back();
                    else if((mouse_x>=350&&mouse_x<=650)&&(mouse_y>=490&&mouse_y<=520)&&st4.size())
                    st4.pop_back();
				}
				break;
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        if ( st1.size() ) {
            surface = TTF_RenderText_Solid(font, st1.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[3].x=300;
            rect[3].y=350;
            rect[3].w=surface->w;
            rect[3].h=surface->h;
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[3]);
        }
        if ( st2.size() ) {
            surface = TTF_RenderText_Solid(font, st2.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[8]={350,400,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[8]);
        }
        if ( st3.size() ) {
            surface = TTF_RenderText_Solid(font, st3.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[9]={350,450,surface->w,surface->h};
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[9]);
        }
        if ( st4.size() ) {
            surface = TTF_RenderText_Solid(font, st4.c_str(), color);
            tex = SDL_CreateTextureFromSurface(render, surface);
            rect[12]={350,490,surface->w,surface->h};
            //SDL_DestroyTexture(tex);
            SDL_FreeSurface(surface);
            SDL_RenderCopy(render, tex, NULL, &rect[12]);
        }

        SDL_RenderPresent(render);
        }
        Pfinish();
}

