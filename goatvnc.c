/*
 * Lame code to fuck with sensationalist idiots
 */
#include <stdio.h>

#include <gd.h>
#include <rfb/rfb.h>


int
main(int argc,char *argv[])
{
    FILE *FP;
    int width,height;
    gdImagePtr userimg;
    int c,r,g,b;
    int x,y;
    
    width = 0;
    height = 0;
    
    FP = fopen("./hello.gif","r");
    if(FP==NULL){
        printf("can't open ./hello.gif :(\n");
        return(-1);
    }

    userimg = gdImageCreateFromGif(FP);
    width = gdImageSX(userimg);
    height = gdImageSY(userimg);
    
    rfbScreenInfoPtr server=rfbGetScreen(&argc,argv,width,height,8,3,4);
    server->frameBuffer=malloc(width*height*4);
    /* sorry. was lazy and didn't want to be smarter. */
    for(x = 0;x<width;x++){
        for(y = 0;y<height;y++){
            c = gdImageGetPixel(userimg,x,y);
            server->frameBuffer[width*y*4+x*4+0] = userimg->red[c];
            server->frameBuffer[width*y*4+x*4+1] = userimg->green[c];
            server->frameBuffer[width*y*4+x*4+2] = userimg->blue[c];
            server->frameBuffer[width*y*4+x*4+3] = 0x00;
        }
    }

    fclose(FP);
    
    rfbInitServer(server);
    rfbRunEventLoop(server,-1,FALSE);
    return(0);
}
