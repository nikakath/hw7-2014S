/***********************
 * Project 100         *
 * Picture Suite       *
 * 11/11/13            *
 *                     *
 * Written by          *
 *  Rostom Mbarek      *
 *  Tyler Dewey        *
 ***********************/

#include <stdio.h>
#include "MyroC.h"
#include <string.h>
#include <math.h>

void pixelStrip(Picture *pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect(Picture *pic, int xCenter, int yCenter, int radius);
void ghost(Picture * pic1, Picture * pic3);

int main()
{
  printf("The program makes the robot performs different actions to "
         "pictures \n");
  rConnect("/dev/rfcomm0");
  
  // begin pixelStrip test
  
  // pixel-strip R
  Picture * pic = rTakePicture();
  rSavePicture(pic, "pre-strip-R");
  pixelStrip(pic, 'R');
  rSavePicture(pic, "pixel-strip-R");
  
  // pixel-strip G
  pic = rTakePicture();
  rSavePicture(pic, "pre-strip-G");
  pixelStrip(pic, 'G');
  rSavePicture(pic, "pixel-strip-G");
  
  // pixel-strip B
  pic = rTakePicture();
  rSavePicture(pic, "pre-strip-B");
  pixelStrip(pic, 'B');
  rSavePicture(pic, "pixel-strip-B");
  
  // end pixelStrip testing
  
  
  // begin color intenisfication function testing
  
  // pictureRedder
  pic = rTakePicture();
  rSavePicture(pic, "pre-redder");
  pictureRedder(pic);
  rSavePicture(pic, "post-redder");
  
  // pictureGreener
  pic = rTakePicture();
  rSavePicture(pic, "pre-greener");
  pictureGreener(pic);
  rSavePicture(pic, "post-greener");
  
  // pictureBluer
  pic = rTakePicture();
  rSavePicture(pic, "pre-bluer");
  pictureBluer(pic);
  rSavePicture(pic, "post-bluer");
  
  // end color intenisfication function testing
  
  
  // begin circleSelect function testing
  printf("this function chooses a circle and makes it gray\n");
  int x, y, r; Picture *pic1;
  printf("enter the the x center:");   
  scanf("%d", &x);
  printf("enter the the y center:");
  scanf("%d", &y);
  printf("enter the the radius:");
  scanf("%d", &r);
  pic1=rTakePicture(); 
  rSavePicture(pic1, "circle1.jpg");
  circleSelect(pic1, x, y, r);
  rSavePicture(pic1, "circle2.jpg");
  // end circleSelect testing function
  
  /*~~~~~~~~~~~~~~~~*
   *  ~CREATIVITY~  *
   *~~~~~~~~~~~~~~~~*/

  // begin ghost function testing
  Picture *pic3;
  pic1=rTakePicture();
  rSavePicture(pic1, "first.jpg");//saves the first picture 
  rTurnLeft(1,1);
  pic3=rTakePicture();
  rSavePicture(pic3, "second.jpg");//saves the second picture
  ghost(pic1, pic3);
  rSavePicture(pic3, "ghost.jpg");/*saves the result picture*/
  /* end ghost function testing*/
     
  rDisconnect();
  return 0;
}

/* pixelStrip
 * Sets the R, G, or B value of every pixel in a picture, pic,
 * to zero, if given 'R', 'G', or 'B' respectively.
 *
 * Preconditions: char color is either 'R', 'G', or 'B', and * pic
 * is a valid picture.
 * Postconditions: the R, G, or B value of every pixel in pic will
 * be set to zero, depending on color's value.
 */

void pixelStrip(Picture *pic, char color)
{
    int i, j;
    Pixel pix;
    int width = rGetPictureWidth (pic);
    int height = rGetPictureHeight (pic);
    
    if (color == 'R')
        for (i=0;i<width;i++)
        {
            for(j=0;j<height;j++)
            {
                pix = rGetPicturePixel (pic, i, j);
                
                pix.R=0;
                
                rSetPicturePixel (pic, i, j, pix);
            }
        }
    
    else if (color == 'G')
        for (i=0;i<width;i++)
        {
            for(j=0;j<height;j++)
            {
                pix = rGetPicturePixel (pic, i, j);
                
                pix.G=0;
                
                rSetPicturePixel (pic, i, j, pix);
            }
        }
    
    else if (color == 'B')
        for (i=0;i<width;i++)
        {
            for(j=0;j<height;j++)
            {
                pix = rGetPicturePixel (pic, i, j);
                
                pix.B=0;
                
                rSetPicturePixel (pic, i, j, pix);
            }
        }
    
    else
    {
        printf("Error, color not recognized");
        return;
    }
}

/* pictureRedder
 * Increases the red component of each pixel in a picture,
 * more so for less-red pixels and less so for more-red pixels
 *
 * Preconditions: pic is a picture
 * Postconditions: pic has been altered so its pixels have more
 * red.
 */
void pictureRedder (Picture * pic)
{
    int i, j;
    int width = rGetPictureWidth(pic);
    int height = rGetPictureHeight(pic);
    
    Pixel pix;
    
    for(j = 0; j < height; j++)
    {
        for(i = 0; i < width; i++)
        {
            pix = rGetPicturePixel(pic, i, j);
            
            if (pix.R == 0)
                pix.R += 255;
            else
                pix.R += 256 - 32 * log2(pix.R + 1);
            
            rSetPicturePixel(pic, i, j, pix);
        }
    }
}

/* pictureGreener
 * Increases the green component of each pixel in a picture,
 * more so for less-green pixels and less so for more-green pixels
 *
 * Preconditions: pic is a picture
 * Postconditions: pic has been altered so its pixels have a larger
 * green component.
 */
void pictureGreener (Picture * pic)
{
    int i, j;
    int width = rGetPictureWidth(pic);
    int height = rGetPictureHeight(pic);
    
    Pixel pix;
    
    for(j = 0; j < height; j++)
    {
        for(i = 0; i < width; i++)
        {
            pix = rGetPicturePixel(pic, i, j);
            
            if (pix.G == 0)
                pix.G += 255;
            else
                pix.G += 256 - 32 * log2(pix.G + 1);
            
            rSetPicturePixel(pic, i, j, pix);
        }
    }
}

/* pictureBluer
 * Increases the blue component of each pixel in a picture,
 * more so for less-blue pixels and less so for more-blue pixels
 *
 * Preconditions: pic is a picture
 * Postconditions: pic has been altered so its pixels have a larger
 * blue component.
 */
void pictureBluer (Picture * pic)
{
    int i, j;
    int width = rGetPictureWidth(pic);
    int height = rGetPictureHeight(pic);
    
    Pixel pix;
    
    for(j = 0; j < height; j++)
    {
        for(i = 0; i < width; i++)
        {
            pix = rGetPicturePixel(pic, i, j);
            
            if (pix.B == 0)
                pix.B += 255;
            else
                pix.B += 256 - 32 * log2(pix.B + 1);
            
            rSetPicturePixel(pic, i, j, pix);
        }
    }
}

/* circleSelect
 * Turns the pixels grey in a circular region described by x and y coordinates
 * of it's center and a radius, all three of which are entered at runtime by
 * the user.
 *
 * Preconditions: pic is a valid picture, xCenter is an integer, yCenter
 * is an integer, radius is an integer.
 * Postconditions: Any pixels that fall within the circle centered at
 * (xCenter, yCenter) with a radius of radius will be turned grey.
 */
void circleSelect(Picture *pic, int xCenter, int yCenter, int radius)
{
    int i, j;
    int width = rGetPictureWidth (pic); //gets the width of the picture
    int height = rGetPictureHeight (pic); //gets the height of teh picture
    Pixel pix;
    for (i = 0; i < width; i++) //loop going through the pixels of the picture
    {
        for(j = 0; j < height; j++)
        {
            /*specific formula to test if the pixels are in the circle
             surrounding the center*/
            if(((i-xCenter)*(i-xCenter)+(j-yCenter)*(j-yCenter))<=radius*radius)
            {
                pix = rGetPicturePixel (pic, i, j);
                pix.R=100;
                pix.G=100;
                pix.B=100;//when the pixels are equal, the pixel is set to gray
                rSetPicturePixel (pic, i, j, pix);}
        }
    }
    rShowPicture (pic);
}

/* ghost
 * A creative function which blends together two images, creating an
 * etherial image worthy of Alfred Hitchcock, as both images appear
 * impermanent and translucent. It does this by averaging the color
 * components of every pixel in the two images and storing the new
 * pixel values in the second image.
 *
 * Preconditions: pic1 and pic3 are both valid images.
 * Postconditions: the pixels of pic3 now contain the average value
 * of their original contents and the value of the corresponding pixel
 * in pic1. pic1 remains unchanged.
 */
void ghost(Picture * pic1, Picture * pic3)
{
    int i, j;
    int width = rGetPictureWidth (pic1);//gets the width of the picture
    int height = rGetPictureHeight (pic1);//gets the height of the picture
    Pixel pix1, pix3;
    
    for (i = 0;i < width; i++)
    {
        for(j = 0;j < height; j++)
        {
            //gets the pixel of the first picture
            pix3 = rGetPicturePixel (pic3, i, j);
            //gets the pixel of the second picture
            pix1 = rGetPicturePixel (pic1, i, j);
            
            //takes the average of the pixels
            pix3.R=(pix1.R +pix3.R)/2;
            pix3.G=(pix1.G +pix3.G)/2;
            pix3.B=(pix1.B +pix3.B)/2;
            rSetPicturePixel (pic3, i, j, pix3);
        }
    }
    
    rShowPicture (pic3);//shows the picture in question
}


