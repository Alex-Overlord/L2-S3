Insert into Operateur Values (042,'Robert',32);
Insert into Operateur Values (010,'Sophie',41);
Insert into Operateur Values (078,'Lucette',25);
Insert into Operateur Values (022,'Albert',25);
Insert into Operateur Values (057,'Marc',38);

Insert into Machine Values (012,'Perceuse');
Insert into Machine Values (013,'Ponceuse');
Insert into Machine Values (014,'Tour numerique');

Insert into Piece Values (01,'Piece1',012,010,250);
Insert into Piece Values (02,'Piece2',012,022,600);
Insert into Piece Values (03,'Piece3',014,022,200);
Insert into Piece Values (04,'Piece4',013,078,150);

Insert into Qualifie_sur Values (010,012,   );
Insert into Qualifie_sur Values (022,012,   );
Insert into Qualifie_sur Values (010,013,   );
Insert into Qualifie_sur Values (042,013,   );
Insert into Qualifie_sur Values (078,012,   );
Insert into Qualifie_sur Values (010,014,   );
