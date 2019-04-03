int collisionennemi(PERSO_PRINCIPALE *perso,ENTITE_SECONDAIRE *ennemi)
{
int verif =1;

int leftA, leftB; int rightA, rightB; int topA, topB; int bottomA, bottomB;
 //Calculate the sides of rect A
leftA = ennemi->position.x; rightA = ennemi->position.x + ennemi->position.w; topA = ennemi->position.y; bottomA = ennemi->position.y + ennemi->position.h;
//Calculate the sides of rect B
leftB = perso->position.x; rightB = perso->position.x + perso->position.w; topB = perso->position.y; bottomB = perso->position.y + perso->position.h;
//If any of the sides from A are outside of B
if( bottomA <= topB )
{ verif= 0; } +-
if( topA >= bottomB )
{ verif= 0; }
if( rightA <= leftB )
{ verif= 0; }
if( leftA >= rightB )
{ verif= 0; }
return verif;
}

