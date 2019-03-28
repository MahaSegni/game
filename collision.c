int CollisionDecor(sdlJeu *sj,float dx, float dy){
    /*retourne des nombres differents en fonction de la collision*/
 
    int xmin,xmax,ymin,ymax,i,j;
 
    char c;
 
    Mario *perso = jeuGetMario(&sj->jeu);
    Niveau *niv = jeuGetNiveau(&sj->jeu);
 
    /*Personnage endehors du terrain*/
    if (perso->x<0 || (perso->x + TAILLE_SPRITE -1)>=21*TAILLE_SPRITE
     || perso->y<0 || (perso->y + TAILLE_SPRITE -1)>=12*TAILLE_SPRITE)
        return -1;
 
    if (dx<0 || dy<0){
        xmin=(perso->x + dx) / TAILLE_SPRITE;
        ymin=(perso->y + dy) / TAILLE_SPRITE;
 
        xmax=perso->x / TAILLE_SPRITE;
        ymax=perso->y / TAILLE_SPRITE;
 
     //   printf("b2\n");
    }
 
    else{
 
        xmin = perso->x / TAILLE_SPRITE;
        ymin = perso->y / TAILLE_SPRITE;
        xmax = (perso->x + dx + TAILLE_SPRITE -1) / TAILLE_SPRITE;
        ymax = (perso->y + dy + TAILLE_SPRITE -1) / TAILLE_SPRITE;
    }
 
    for(i=xmin;i<=xmax;i++)
    {
        for(j=ymin;j<=ymax;j++)
        {
            c=nivGetXY(niv,i,j);
 
           /* /*Collision Personnage sur le haut*/
            if(dx==0 && dy <= 0){
 
                if(c=='#'){ return 1;}
 
            }
 
            /*Collision Personnage sur le bas*/
            if(dx==0 && dy >= 0){
 
                if(c=='#'){ return 3;}
 
            }*/
 
            /*Collision Personnage sur la gauche*/
            else if(dx<=0 && dy == 0){
 
                if(c=='#'){ return 2;}
 
            }
             /*Collision Personnage sur la droite*/
            else if(dx>=0 && dy == 0){
 
                if(c=='#'){ return 4;}
 
            }
 
            /*Dans une collision*/
            else{
 
                if(c=='#'){ return 5;}
 
            }
        }
    }
 
    /*En cas de non collision*/
    return 0;
}
