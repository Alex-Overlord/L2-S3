Create table Operateur(
numero numeric primary key,
nom character(40) NOT NULL,
age numeric
);

Create table Machine(
referenceM numeric primary key,
designationM character
);

Create table Piece(
referenceP numeric primary key,
designationP character,
reference_machine numeric references Machine(referenceM),
numero_operateur numeric references Operateur(numero),
quantite numeric
);

Create table Qualifie_sur(
ref_m numeric references Machine(referenceM),
num_op numeric references Operateur(numero),
dates date,
Primary key(ref_m,num_op)
);
