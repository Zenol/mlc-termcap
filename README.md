- Termcap -
====================

Mais qu'est ce donc que ce bout de code? Si vous voulez faire joujou avec des termcap, sans vous prendre la tête, en gros si vous cherchez une CACALIB simplifiée - alors ceci est fait pour vous.

- How to compile ? -
====================

Pour compiler cette bibliothèque, il vous faut `curse.h`. Vous pouvez l'obtenir avec un `apt-get install libncurses5-dev`.

La bibliothèque se trouve dans `/lib`. Vous pouvez la compiler en version statique avec un simple `make`.

Un projet de démo est disponible dans `/example`.

Vous pouvez regénérer le makefile si vous modifiez les fichiers .c avec `./makegen.sh`.

- How To Use ? -
=================

Read The Fucking Manual(Ici, mlc.h!)

    ```============='''
    << ThxomgIlov'U: >>
    ~~~_____________/\/

Send me a poem about the secret love story of Php and C++.

Plus précisement, la bibliothèque fonctione sur un modèle de boucle infinie dans laquelle viennent se greffer des callback. Vous en avez une qui sera appelé à chaque iteration de la boucle, et une autre qui reagit aux entrées clavier. Se référer au code d'exemple pour plus de détails.

- License Z-Lib -
=================

Le code est sous license Z-Lib. Vous pouvez le modifier et réutiliser dans vos projet, y compris les projets closed source. Vous n'avez pas obligation de préciser que le code viens d'ici, même si ça fait plaisir :)
