# chti23

**Si vous ouvrez ce fichier README.md avec `Visual Code Studio`, faites CTRL+K,V pour visualiser le contenu.**

Dépôt commun pour le BE chti :
Chaque binome travaille sur ça branche de type grpE_NOM1_NOM2.

## Guide de travail Git
---

Une fois l'[installation](#installation) et la branche faite voilà le *workflow* conseillé en TP chez soi à chaque séance de travail.


 1)  Vérifier que l'on est bien sur sa branche grpX_NOM1_NOM2 (sinon faire git checkout NOMDEBREANCHE) et récuppérer tout ce qu'il y a de nouveau sur le dépôt :   
<code sh>
git status   
git pull
</code>   
Là normalement il n'y a pas de conflit... Sinon il faudra les régler et faire un commit (demander à chatGPT ou au prof)

2) Vous travaillez et modifiez vos fichiers en local. 
3) A la fin d'une séance de travail ou d'une étape il faut enregistrer une version nouvelle de son travail (faire un "commit") et pour cela ajouter les nouveautés à enregistrer (faire des "add"). Un git status permet de voir ou on en est et faire ses add. On peut aveuglément tout ajouter.   
<code shell>
git pull   
git status     
git add * --dry-run 
</code>   
Là vérifier ce que dit le  `dry-run` (essai à vide) et que tout ira bien. N'ajouter que du code source pas de fichiers générés parasites etc.   
<code shell>
git add *   
git commit -am "TP1 pas fini de rien comprendre"   
git push
</code>


## Installation
___

Pour celles qui conaisse git voilà le résumé :

<code bash>
git clone https://git.etud.insa-toulouse.fr/VOTRE_COMPTE/chti23.git
</code>  


### Clone
---

* Lancez git bash : "menu windows tapez Git et sélectionnez Git Bash" pour vérifier qu'il est bien installé
* Placez vous où bon vous semble et faites un clic droit puis `Git Bash Here`, puis faite un clone du dépot git (hébergé par l'INSA grâce aux étudiantes du club Info) avec la ligne de commande :   
<code bash>
   git clone https://git.etud.insa-toulouse.fr/VOTRE_COMPTE/chti23.git
</code>

* Pour vérifier, naviguer dans le répertoire `chti23`, faites un clic droit et `Git Bash Here` et tentez de faire la fameuse commande :   
<code bash>
   git status
</code>

> Il se peut qu'un message parlant de **répertoire non secure** s'affiche et propose une ligne de commande  dans le message qui doit resembler à :   
>   git config --global --add safe.directory '%(prefix)///netapp1/GNIAGNIAGNIA...'   
> Faites un copier-coller de cette commande et exécutez-la.
> La commande git status doit enfin fonctionner



Les fichiers sont visibles et partagés !



