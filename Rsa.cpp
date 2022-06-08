#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#define SCENE 10
enum { FRONTPAGE,ENCRYPTION,EXIT };
int rev_analog_sig_angle;
int width = 650, height = 650;
void *font =GLUT_BITMAP_HELVETICA_12;
int len;
long int P=5,Q=7,N,T,flag,E[100],D[100],Temp[100],J,M[100],En[100],I,Z,S[100]; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
void EncrypT(); 
void DecrypT(); 
void *fonts[] =
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24, // Text Styles
GLUT_BITMAP_HELVETICA_12,
GLUT_BITMAP_HELVETICA_10,
GLUT_BITMAP_HELVETICA_18,
};
// TO DISPLAY THE TEXT INFORMATION
void output(int x, int y, char *string,int j)
{ 
int i;
glRasterPos2f(x, y);
len = (int) strlen(string);
//printf("%d",len);
for (i = 0; i < len; i++)
glutBitmapCharacter(fonts[j], string[i]);
}
void output1(int x, int y, char *string,int j)
{ int i;
glRasterPos2f(x, y);
for (i = 0;string[i]!=-1; i++)
glutBitmapCharacter(fonts[j], string[i]);
}
// FUNCTIONS. FOR DELAY
void delay()
{ int i,j,k;
for(i=0;i<50000;i++)
{
for(j=0;j<10000;j++);
for(k=0;k<5000;k++);
}}
void delay1(void)
{ int i;
for(i=0;i<900000;i++);
}
// FIRST SCREEN - FRONT PAGE
void front_page()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glColor3f(1,1,0);
output(200,550,"",2);
glColor3f(0,0.81,0.61);
output(260,450,"MINI PROJECT ON",2);
output(200,400,"RSA ALGORITHM",2);
glColor3f(1.0,0.81,0.61);
output(70,200,"Guides:",5);
output(115,180,"",2);
output(115,150,"",2);
output(460,200,"By:",5);
output(485,180,"",2);
output(485,150,"",2);
output(275,100,"Press S to start",2);
output(275,50,"Press Q to quit",2);
glFlush();
glCallList(SCENE);
glPopMatrix();
glutSwapBuffers();
}
/* Movement angles */
GLint
movement_angle=0,packet_angle=0,head_angle=0,packet_angle1=0,head_angle1=0,packet_angle2=0,head_angle2=0,packet_angle3=0,head_angle3=0,packet_angle4=0;
GLdouble mov_speed = 1;
GLint
head_angle4=0,packet_angle5=0,head_angle5=0,packet_angle6=0,head_angle6=0,packet_angle7,head_angle7=0,packet_angle8=40;
/* Movement angles */
GLint
movement_angle1=0,arrow_angle=0,rev_arrow_angle=0,phy_header_angle=0,rev_phy_header_angle=0,rev_phy_header_angle1=0,phy_header_angle1=0,analog_sig_angle=0,rev_analog_sig_angle = 0;
void animation_encryp(void)
{ if ((movement_angle += mov_speed) >= 600)
movement_angle = 600;
if ((arrow_angle += mov_speed) >= 150)
arrow_angle = 150;
if(arrow_angle==150)
if ((phy_header_angle += mov_speed) >= 100)
phy_header_angle = 100;
if(phy_header_angle==100)
if ((phy_header_angle1 += mov_speed) >= 100)
phy_header_angle1 = 100;
if(phy_header_angle1==100)
if ((analog_sig_angle += mov_speed) >= 100)
analog_sig_angle = 100;
if(analog_sig_angle==100)
if ((movement_angle1 += mov_speed) >= 420)
movement_angle1 = 420;
delay1();
if(movement_angle1 ==420)
if ((rev_analog_sig_angle += mov_speed) >= 100)
rev_analog_sig_angle = 100;
if(rev_analog_sig_angle ==100)
if ((rev_phy_header_angle += mov_speed) >= 200)
rev_phy_header_angle = 200;
if(rev_phy_header_angle ==200)
if ((rev_phy_header_angle1 += mov_speed) >= 100)
rev_phy_header_angle1 = 100;
if(rev_phy_header_angle ==200)
if ((rev_arrow_angle += mov_speed) >= 100)
rev_arrow_angle = 100;
glutPostRedisplay();
}
void computer()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(55.0,340.0);
glVertex2f(145.0,340.0);
glVertex2f(150.0,350.0);
glVertex2f(60.0,350.0);
glEnd();
glColor3f(1,1,1);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(60.0,355.0);
glVertex2f(150.0,355.0);
glVertex2f(150.0,370.0);
glVertex2f(60.0,370.0);
glEnd();
glColor3f(1,1,1);
glBegin(GL_LINE_LOOP);
glVertex2f(75.0,380.0);
glVertex2f(135,380.0);

glVertex2f(135.0,430.0);
glVertex2f(75.0,430.0);
glEnd();
glColor3f(0,0,0.61);
glBegin(GL_QUADS);
glVertex2f(80.0,385.0);
glVertex2f(130.0,385.0);
glColor3f(1,1,1);
glVertex2f(130.0,425.0);
glVertex2f(80.0,425.0);
glEnd();
glColor3f(0.75,0.85,0.65);
glBegin(GL_LINES);
glVertex2f(90.0,370.0);
glVertex2f(90.0,380.0);
glVertex2f(120.0,370.0);
glVertex2f(120.0,380.0);
glEnd();
}
void computer_dest()
{
glColor3f(0.75,0.85,0.65);//keyboard
glBegin(GL_QUADS);
glVertex2f(545.0,525.0);
glVertex2f(635.0,525.0);
glVertex2f(640.0,535.0);
glVertex2f(550.0,535.0);
glEnd();
glColor3f(1,1,1);//cabinet
glBegin(GL_LINE_LOOP);
glVertex2f(550.0,540.0);
glVertex2f(640.0,540.0);
glVertex2f(640.0,555.0);
glVertex2f(550.0,555.0);
glEnd();
glColor3f(1,1,1);//cpu
glBegin(GL_LINE_LOOP);
glVertex2f(565.0,565.0);
glVertex2f(625,565.0);
glVertex2f(625.0,615.0);
glVertex2f(565.0,615.0);
glEnd();
glColor3f(0,0,0.61);//monitor
glBegin(GL_QUADS);
glVertex2f(570.0,570.0);
glVertex2f(620.0,570.0);
glColor3f(1,1,1);
glVertex2f(620.0,610.0);
glVertex2f(570.0,610.0);
glEnd();
glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2f(580.0,555.0);
glVertex2f(580.0,565.0);
glVertex2f(610.0,555.0);
glVertex2f(610.0,565.0);
glEnd();
}
void cipher()
{
glColor3f(0.0f,0.0f,1.0f);
glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,14,0);
glutSolidCube(2);
glColor3f(0,0,0);
output1(-1,0,En,2);
glPopMatrix();
}
void message_data()
{
glColor3f(1.0f,1.0f,0.0f);
glPushMatrix();
glScalef(40,20,.5);
glTranslatef(3,14,0);
glutSolidCube(2);
glColor3f(0,0,0);
output(-1,0,msg,2);
glPopMatrix();
}
void message_key(void)
{
glColor3f(0.0f,1.0f,0.0f);
glPushMatrix();
glScalef(20,20,.5);
glTranslatef(3,14,0);
glutSolidCube(2);
glColor3f(0,0,0);
output(-1,0,"KEY",2);
glPopMatrix();
}
void encryption()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glPushMatrix();
glColor3f(1.0f,1.0f,1.0f);
output(140,640,"RSA:ENCRYPTION AND DECRYPTION PROCESS",2);
glPopMatrix();
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(-30,200,0);
output(75,440,"Sender",2);
computer();
glPopMatrix();
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
output(565,630,"Receiver",2);
computer_dest();
glPopMatrix();
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glColor3f(0,1,0);
glBegin(GL_QUADS);
glVertex2i(250,20);
glVertex2i(290,20);
glVertex2i(290,50);
glVertex2i(250,50);
glEnd();
glColor3f(1.0f,1.0f,1.0f);
output(300,30,"Public Key",2);
glPopMatrix();
glColor3f(0,0,61);
glPushMatrix();
glBegin(GL_QUADS);
glVertex2i(250,60);
glVertex2i(290,60);
glVertex2i(290,90);
glVertex2i(250,90);
glEnd();
glColor3f(1.0f,1.0f,1.0f);
output(300,70,"Cipher Text",2);
glPopMatrix();
glPushMatrix();
glColor3f(1,1,0);
glBegin(GL_QUADS);
glVertex2i(250,100);
glVertex2i(290,100);
glVertex2i(290,130);
glVertex2i(250,130);
glEnd();
glColor3f(1.0f,1.0f,1.0f);
output(300,110,"Plain Text",2);
glPopMatrix();
glPushMatrix();
glColor3f(1.0f,1.0f,1.0f);
glBegin(GL_LINE_LOOP);
glVertex2i(240,10);
glVertex2i(395,10);
glVertex2i(395,140);
glVertex2i(240,140);
glEnd();
glPopMatrix();
glPushMatrix();
glColor3f(1.0f,1.0f,1.0f);
output(20,130,"The Plain text is decrypted",5);
output(20,100,"using the reciever's public key",5);
glPopMatrix();
glPushMatrix();
glColor3f(1.0f,1.0f,1.0f);
output(470,130,"The Cipher text is decrypted",5);
output(470,100,"using the reciever's private key",5);
glPopMatrix();
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glScalef(70,40,.5);
glTranslatef(1.5,7,0);
glutWireCube(1.8);
glPopMatrix();
delay1();
if(phy_header_angle1!=100)
{
glPushMatrix();
glTranslatef(0,-phy_header_angle1,0);
glPushMatrix();
glTranslatef(0,-arrow_angle,0);
glTranslatef(0,150,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(phy_header_angle,0,0);
glTranslatef(-100,0,0);
message_key();
glPopMatrix();
glPopMatrix();
}
glPushMatrix();
glTranslatef(movement_angle1,0,0);
delay1();
if(phy_header_angle1==100)
{
glPushMatrix();
delay1();
if(movement_angle1>=420)
{
glTranslatef(0,rev_analog_sig_angle,0);
}
glTranslatef(0,-analog_sig_angle,0);
if(rev_analog_sig_angle!=100)
cipher();
glPopMatrix();
}
glPopMatrix();
glPushMatrix();
glTranslatef(movement_angle1,0,0);
if(phy_header_angle1==100)
{
glPushMatrix();
glScalef(50,30,.5);
glTranslatef(2.5,2.5,0);
//glutWireCube(1.8);
glPopMatrix();
}
glPopMatrix();
delay1();
if(rev_analog_sig_angle==100)
{
glPushMatrix();
glTranslatef(450,rev_phy_header_angle1,0);
glPushMatrix();
glTranslatef(0,rev_arrow_angle,0);
glTranslatef(0,0,0);
message_data();
glPopMatrix();
glPushMatrix();
glTranslatef(rev_phy_header_angle,0,0);
glTranslatef(-10,0,0);
delay1();
if(rev_phy_header_angle<200)
message_key();
glPopMatrix();
glPopMatrix();
}
glColor3f(1.0f,1.0f,1.0f);
glPushMatrix();
glTranslatef(450,0,0);
glScalef(70,40,.5);
glTranslatef(1.5,7,0);
glutWireCube(1.8);//right layer
glPopMatrix();
animation_encryp();
glFlush();
glutSwapBuffers();
}
void myinit()
{
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,700.0,0.0,700.0);
}
void display()
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
front_page();
glFlush();
glutSwapBuffers();
}
void key (unsigned char key, int x, int y)
{
switch(key) {
case 'S' :
case 's' :movement_angle=0; packet_angle=0; head_angle=0; packet_angle1=0; head_angle1=0; packet_angle2=0; head_angle2=0; packet_angle3=0; head_angle3=0; packet_angle4=0;
    mov_speed = 1;head_angle4=0;packet_angle5=0;head_angle5=0;packet_angle6=0;head_angle6=0;packet_angle7=0; head_angle7=0; packet_angle8=40;
    movement_angle1=0; arrow_angle=0; rev_arrow_angle=0; phy_header_angle=0;rev_phy_header_angle=0;rev_phy_header_angle1=0;phy_header_angle1=0;analog_sig_angle=0;  rev_analog_sig_angle = 0;
    glutDisplayFunc(encryption);
break;
case 'q':
case 'Q':exit(0);
}
glutPostRedisplay();
}

static void menu(int mode)
{
switch (mode)
{
case 1:glutDisplayFunc(front_page); break;
case 2:
glutPostRedisplay();
movement_angle=0; packet_angle=0; head_angle=0; packet_angle1=0; head_angle1=0; packet_angle2=0; 
head_angle2=0; packet_angle3=0; head_angle3=0; packet_angle4=0;
    mov_speed = 1;
    head_angle4=0;packet_angle5=0;head_angle5=0;packet_angle6=0;
head_angle6=0;packet_angle7=0; head_angle7=0; packet_angle8=40;
    movement_angle1=0; arrow_angle=0; rev_arrow_angle=0; phy_header_angle=0;rev_phy_header_angle=0;
rev_phy_header_angle1=0;phy_header_angle1=0;analog_sig_angle=0;rev_analog_sig_angle = 0;
glutDisplayFunc(encryption);
break;
case 3: exit(0);
}
glutPostRedisplay();
}
int prime(long int pr) 
{ 
int i; 
J=sqrt(pr); 
for(i=2;i<=J;i++) 
{ 
if(pr%i==0) 
return 0; 
} 
return 1; 
}
 
void ce() 
{ 
int k; 
k=0; 
for(I=2;I<T;I++) 
        {
            if(T%I==0)
                continue;
                flag=prime(I);
            if(flag==1&&I!=P&&I!=Q)
            {
                E[k]=I; flag=cd(E[k]);
                if(flag>0) 
{ 
D[k]=flag; 
k++; 
} 
if(k==99) 
break; 
} 
} 
}
 
long int cd(long int x) 
{ 
long int k=1; 
while(1) 
{ 
k=k+T; 
if(k%x==0) 
return(k/x); 
} 
} 
 
void EncrypT() 
{ 
long int pt,ct,key=E[0],k,len; 
I=0; 
len=strlen(msg); 
while(I!=len) 
{ 
pt=M[I]; 
pt=pt-96; 
k=1; 
for(J=0;J<key;J++) 
{ 
k=k*pt; 
k=k%N; 
} 
Temp[I]=k; 
ct=k+96; 
En[I]=ct; 
I++; 
} 
En[I]=-1; 
printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
for(I=0;En[I]!=-1;I++) 
{
S[I]=En[I];
printf("%c",En[I]);
}
} 
 
void DecrypT() 
{ 
long int pt,ct,key=D[0],k; 
I=0; 
while(En[I]!=-1) 
{ 
ct=Temp[I]; 
k=1; 
for(J=0;J<key;J++) 
{ 
k=k*ct; 
k=k%N; 
} 
pt=k+96; 
M[I]=pt; 
I++; 
} 
M[I]=-1; 
printf("\nTHE DECRYPTED MESSAGE IS\n"); 
for(I=0;M[I]!=-1;I++) 
printf("%c",M[I]); 

}



void main(int argc, char** argv)
{
printf("\nENTER MESSAGE\n"); 
fflush(stdin); 
scanf("%s",msg); 
for(I=0;msg[I]!=NULL;I++) 
M[I]=msg[I]; 
N=P*Q; 
T=(P-1)*(Q-1); 
ce();  
EncrypT(); 
DecrypT(); 
delay();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1000,700);
glutInitWindowPosition(0,0);
glutCreateWindow("ENCRYPTION");
glutKeyboardFunc(key);
myinit();
glutDisplayFunc(display);
glutCreateMenu(menu);
glutAddMenuEntry("Front Page", 1);
glutAddMenuEntry("Encryption",2);
glutAddMenuEntry("Exit",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}
