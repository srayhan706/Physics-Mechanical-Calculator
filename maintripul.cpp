#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<iostream>
#include "probtripul.h"

using namespace std;

const int SCREEN_HEIGHT= 980;
const int SCREEN_WIDTH= 1260;
SDL_Window* window=NULL;
SDL_Surface* surface=NULL;
SDL_Renderer* render=NULL;
SDL_Texture* tex=NULL;

bool init(){
    bool success=true;
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("Couldn't Initialize %s\n",SDL_GetError());
        success= false;
    }
    else{
       window= SDL_CreateWindow("WELCOME!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);
       if(window==NULL){
           printf("NO Window %s\n",SDL_GetError());
           success=false;
       }
    }
    return success;
}
void mouse_ev(bool run,SDL_Event ev,SDL_Window* window,SDL_Renderer* render,SDL_Texture* tex)
{
    int mouse_x,mouse_y;
    SDL_Rect rect[10];
    while(run){
        while(SDL_PollEvent(&ev)){
            switch(ev.type){
                case SDL_MOUSEMOTION:
                    mouse_x=ev.motion.x;
                    mouse_y=ev.motion.y;
                    break;
                case SDL_QUIT:
                    run=0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    case SDL_BUTTON_LEFT:
                    if((mouse_x>100&&mouse_x<600)&&(mouse_y>100&&mouse_y<180))
                    tripul_acc_ten(window,render,tex);
                    else if((mouse_x>100&&mouse_x<600)&&(mouse_y>270&&mouse_y<350))
                    tripul_2ang(window,render,tex);
                    else if((mouse_x>100&&mouse_x<600)&&(mouse_y>440&&mouse_y<520))
                    tripul_2mass(window,render,tex);
            }
        }
        //cout<<mouse_x<<' '<<mouse_y<<endl;
        rect[0]={105,310,407,55};
        SDL_SetRenderDrawColor(render,255,255,255,255);
        SDL_RenderFillRect(render,&rect[0]);
        SDL_RenderClear(render);
        SDL_RenderCopy(render,tex,NULL,NULL);
        SDL_RenderPresent(render);
    }
}

void update(){
    bool run=true;
    SDL_Event ev;
    render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    surface= IMG_Load("Pic/pulley2.png");
    if(!surface){
        printf("Couldn't load image %s\n",SDL_GetError());
    }
    tex=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    if(!tex){
        printf("NO Texture %s\n",SDL_GetError());
    }
    SDL_RenderClear(render);
    SDL_RenderCopy(render,tex,NULL,NULL);
    SDL_RenderPresent(render);
    SDL_Delay(3000);
    surface=IMG_Load("Pic/pulley2.png");
    tex=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    mouse_ev(run,ev,window,render,tex);
}

void finish(){
    SDL_DestroyTexture(tex);
    tex=NULL;
    SDL_DestroyRenderer(render);
    render=NULL;
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_Quit();
}

int main(){
    if(!init()){
        printf("Initialization failed %s\n",SDL_GetError());
        return 1;
    }
    update();

    finish();

    return 0;
}

