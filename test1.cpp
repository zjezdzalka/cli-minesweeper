#include<iostream> /*cout, cin, do while(), etc.*/
#include<time.h> /*Do wyznaczania czasu*/
#include<cstdlib> /*Do wyznaczania liczb randomowych pseudolosowych*/
#include<stdlib.h> /*Do usuwania treści konsoli, oraz do funkcji sleep.*/

using namespace std;

char difficulty(char diff){
	/*Do wyboru poziomu trudności. Wszystko będzie napisane po angielsku, ponieważ dawaliśmy kolegom z innych kraju do przetestowania, czy finalnie działa ^^.*/
	do{
		cout<<"Choose the level difficulty: "<<endl
		<<"A - Easy (8x8) - 10 bombs"<<endl
		<<"B - Medium (12x12) - 24 bombs"<<endl
		<<"C - Hard (16x16) - 44 bombs"<<endl;
		cin>>diff;
	}
	/*Jeżeli inne od wartości: A, B, C.*/
	while(
	diff != 'A' && diff != 'a' && 
	diff != 'B' && diff != 'b' && 
	diff != 'C' && diff != 'c'
	);
	
	/*Zwróć wartość diff.*/
	return diff;
}

void gra_latwa(int gra[], char gra2[]){
	/*Rozpocznij rysowanie tablicy.*/
	cout<<"   A  B  C  D  E  F  G  H"<<endl<<endl;
	
	for(int i = 0; i<8; i++){
		i = i+1;
		cout<<i;
		i = i-1;
		
		
		for(int j = 0; j<8; j++){
			cout<<"  "<<gra2[((i*8)+j)];	
		}
		
		cout<<endl<<endl;
	}
	
	int row, number, number2, number3, number4; 
	int solution = 0;
	char column;
	
	/*Rozdzieliłem bo był problem z bool'ami.*/
	bool top_left, left = false;
	bool bottom_left, bottom = false;
	bool bottom_right, right = false;
	bool top_right, top = false;
	
	
	/*Loop, w którym zamieszczona jest gra.*/
	for(int i = 0; i>=0; i++){
		bool top_left, left = false;
		bool bottom_left, bottom = false;
		bool bottom_right, right = false;
		bool top_right, top = false;
		
		number3 = '0';
		number2 = 0;
		column = 'n';
		number = 0;
		
		/*Zresetowano wszystkie wartości.*/
		
		do{
			cout<<endl<<"Type in the letter of the column: ";
			cin>>column;
		}
		
		while(
		column != 'A' && column != 'a' && 
		column != 'B' && column != 'b' && 
		column != 'C' && column != 'c' && 
		column != 'D' && column != 'd' && 
		column != 'E' && column != 'e' && 
		column != 'F' && column != 'f' && 
		column != 'G' && column != 'g' && 
		column != 'H' && column != 'h'
		);
		
		/*Wartość kolumny. -^ */
		/*Wartość rzędu. -v*/
		
		do{
			cout<<endl<<"Type in the number of the row: ";
			cin>>row;
		}
		while(row > 8 && row <= 0);

		/*Przypisanie wartości liczbowej do number 4, z char'a, oraz podanie numeru kolumny do number.*/
		
		if(column == 'A' || column == 'a'){
			number = 0;
			number4 = 0;
		}
		if(column == 'B' || column == 'b'){
			number = 1;
			number4 = 1;
		}
		if(column == 'C' || column == 'c'){
			number = 2;
			number4 = 2;
		}
		if(column == 'D' || column == 'd'){
			number = 3;
			number4 = 3;
		}
		if(column == 'E' || column == 'e'){
			number = 4;
			number4 = 4;
		}
		if(column == 'F' || column == 'f'){
			number = 5;
			number4 = 5;
		}
		if(column == 'G' || column == 'g'){
			number = 6;
			number4 = 6;
		}
		if(column == 'H' || column == 'h'){
			number = 7;
			number4 = 7;
		}
		
		/*Zamienie wartości z row i column jako wartość, którą można znaleźć w tablicy.*/
		
		number = number + ((row-1)*8);
		
		/*Jeżeli number 3 (ilość pól z bomb'ami do okoła) nie jest równa 0, ustaw na 0.*/
		
		if(number3 != 0){
			number3 = 0;
		}
	
		/*Proces sprawdzenia bomb wokół wpisanych koordynatów.*/
		
		/*Top*/
		if(row==0){
			top = false;
			top_right = false;
			top_left = false;
		}
		else if(gra[(number-8)]==1 && row!=0){
			top = true;
		}
		
		/*Top_left i Top_right*/
		
		if(gra[(number-7)]==1 && (row!=0 && number4 !=7)){
			top_right = true;
		}
		if(gra[(number-9)]==1 && (row!=0 && number4 !=0)){
			top_left = true;
		}
		
		/*Right*/
		
		if(number4 == 7){
			top_right = false;
			right = false;
			bottom_right = false;
		}
		else if(gra[(number+1)]==1 && number4 != 7){
			right = true;
		}
		
		/*Left*/
		
		if(number4 == 0){
			bottom_left = false;
			left = false;
			top_left = false;
		}
		else if(gra[(number-1)]==1 && number4 != 0){
			left = true;
		}
		
		/*Bottom*/
		
		if(row==7){
			bottom = false;
			bottom_right = false;
			bottom_left = false;
		}
		else if(gra[(number+8)]==1 && row != 7){
			bottom = true;
		}
		
		/*Bottom_right i Bottom_left*/
		
		if(gra[(number+9)]==1 && (row!=7 && number4 !=7)){
				bottom_right = true;
		}
		if(gra[(number+7)]==1 && (row!=7 && number4 !=0)){
				bottom_left = true;
		}
		
		/*Podsumowanie wszystkich kierunków, i zapisanie jako wartości number2.*/
		
		if(bottom == true){
			number2 = number2 + 1;
			bottom = false;
		}
		if(bottom_left == true){
			number2 = number2 + 1;
			bottom_left = false;
		}
		if(bottom_right == true){
			number2 = number2 + 1;
			bottom_right = false;
		}
		if(right == true){
			number2 = number2 + 1;
			right = false;
		}
		if(left == true){
			number2 = number2 + 1;
			left = false;
		}
		if(top == true){
			number2 = number2 + 1;
			top = false;
		}
		if(top_left == true){
			number2 = number2 + 1;
			top_left = false;
		}
		if(top_right == true){
			number2 = number2 + 1;
			top_right = false;
		}
		
		/*Ustawienie wartości char number3, jeżeli dana jest wartość number2.*/
		
		if(number2 == 0){
			number3 = '0';
		}
		if(number2 == 1){
			number3 = '1';
		}
		if(number2 == 2){
			number3 = '2';
		}
		if(number2 == 3){
			number3 = '3';
		}
		if(number2 == 4){
			number3 = '4';
		}
		if(number2 == 5){
			number3 = '5';
		}
		if(number2 == 6){
			number3 = '6';
		}
		if(number2 == 7){
			number3 = '7';
		}
		if(number2 == 8){
			number3 = '8';
		}
		
		/*Wykrywanie czy bomba jest danych koordynatach i zakończenie gry.*/
		
		if(gra[number]==1){
			cout<<"Game over.";
			sleep(5000); 
			return;
		}
		
		/*Wypisanie tablicy.*/
		
		else {
			/*Przypisanie wartości bomb wokół korydnatów do tablicy 2 (która wyświetla cały ten board jakby).*/
			if(gra2[number] == number3){
				gra2[number] = number3;
			}
			else{
				gra2[number] = number3;
				solution = solution + 1;
			}
			/*Wyczyszczenie konsoli.*/
			system("CLS");
			/*Drukowanie tablicy.*/
			cout<<"   A  B  C  D  E  F  G  H"<<endl<<endl;
			/*Nie można mieć dwóch integerów i w jednym zagnieżdzeniu for'ów!!!!*/
			for(int print = 0; print<8; print++){
				print = print+1;
				cout<<print;
				print = print-1;
		
				for(int j = 0; j<8; j++){
					cout<<"  "<<gra2[((print*8)+j)];
				}
				
				cout<<endl<<endl;
			}
			/*Wartość bomb wokół kordynatów jest równe 0.*/
			number3 = '0';
		}
		if(solution==54){
			/*Wygrałeś i odczekaj 5000ms.*/
			cout<<endl<<"You won!";
			sleep(5000); 
		}
	}
}

/*Wszystko poniżej to jest to samo tylko z innymi wartościami row / column bo innego rozmiaru jest tablica.*/

void gra_srednia(int gra[], char gra2[]){
	cout<<"    A  B  C  D  E  F  G  H  I  J  K  L"<<endl<<endl;
			for(int i = 0; i<9; i++){
				i = i+1;
				cout<<i;
				i = i-1;
		
				for(int j = 0; j<12; j++){
					if(j==0){
						cout<<"   "<<gra2[((i*12)+j)];
					}
					else{
						cout<<"  "<<gra2[((i*12)+j)];	
					}
				}
				cout<<endl<<endl;
			}
			for(int i = 9; i<12; i++){
				i = i+1;
				cout<<i;
				i = i-1;
		
				for(int j = 0; j<12; j++){
					cout<<"  "<<gra2[((i*12)+j)];
				}
				cout<<endl<<endl;
			}
	
	int row, number, number2, number3, number4;
		int solution = 0;
	char column;
	bool top_left, left = false;
	bool bottom_left, bottom = false;
	bool bottom_right, right = false;
	bool top_right, top = false;
	
	for(int i = 0; i>=0; i++){
		bool top_left, left = false;
		bool bottom_left, bottom = false;
		bool bottom_right, right = false;
		bool top_right, top = false;
		number3 = '0';
		number2 = 0;
		column = 'n';
		number = 0;
		do{
			cout<<endl<<"Type in the letter of the column: ";
			cin>>column;
		}
		while(
		column != 'A' && column != 'a' && 
		column != 'B' && column != 'b' && 
		column != 'C' && column != 'c' && 
		column != 'D' && column != 'd' && 
		column != 'E' && column != 'e' && 
		column != 'F' && column != 'f' && 
		column != 'G' && column != 'g' && 
		column != 'H' && column != 'h' && 
		column != 'I' && column != 'i' && 
		column != 'J' && column != 'j' && 
		column != 'K' && column != 'k' && 
		column != 'L' && column != 'l');
		
		do{
			cout<<endl<<"Type in the number of the row: ";
			cin>>row;
		}
		while(row > 12 && row <= 0);


		
		if(column == 'A' || column == 'a'){
			number = 0;
			number4 = 0;
		}
		if(column == 'B' || column == 'b'){
			number = 1;
			number4 = 1;
		}
		if(column == 'C' || column == 'c'){
			number = 2;
			number4 = 2;
		}
		if(column == 'D' || column == 'd'){
			number = 3;
			number4 = 3;
		}
		if(column == 'E' || column == 'e'){
			number = 4;
			number4 = 4;
		}
		if(column == 'F' || column == 'f'){
			number = 5;
			number4 = 5;
		}
		if(column == 'G' || column == 'g'){
			number = 6;
			number4 = 6;
		}
		if(column == 'H' || column == 'h'){
			number = 7;
			number4 = 7;
		}
		if(column == 'I' || column == 'i'){
			number = 8;
			number4 = 8;
		}
		if(column == 'J' || column == 'j'){
			number = 9;
			number4 = 9;
		}
		if(column == 'K' || column == 'k'){
			number = 10;
			number4 = 10;
		}
		if(column == 'L' || column == 'l'){
			number = 11;
			number4 = 11;
		}
		
		number = number + ((row-1)*12);
		
		if(number3 != 0){
			number3 = 0;
		}
	
		/*sprawdzenie czy bomby są do okoła*/
		
		/*Top*/
		if(row==0){
			top = false;
			top_right = false;
			top_left = false;
		}
		else if(gra[(number-12)]==1 && row!=0){
			top = true;
		}
		
		/*Top_left i Top_right*/
		
		if(gra[(number-11)]==1 && (row!=0 && number4 !=11)){
			top_right = true;
		}
		if(gra[(number-13)]==1 && (row!=0 && number4 !=0)){
			top_left = true;
		}
		
		/*Right*/
		
		if(number4 == 11){
			top_right = false;
			right = false;
			bottom_right = false;
		}
		else if(gra[(number+1)]==1 && number4 != 11){
			right = true;
		}
		
		/*Left*/
		
		if(number4 == 0){
			bottom_left = false;
			left = false;
			top_left = false;
		}
		else if(gra[(number-1)]==1 && number4 != 0){
			left = true;
		}
		
		/*Bottom*/
		
		if(row==11){
			bottom = false;
			bottom_right = false;
			bottom_left = false;
		}
		else if(gra[(number+12)]==1 && row != 11){
			bottom = true;
		}
		
		/*Bottom_right i Bottom_left*/
		
		if(gra[(number+13)]==1 && (row!=11 && number4 !=11)){
				bottom_right = true;
		}
		if(gra[(number+11)]==1 && (row!=11 && number4 !=0)){
				bottom_left = true;
		}
		
		
		
		if(bottom == true){
			number2 = number2 + 1;
			bottom = false;
		}
		if(bottom_left == true){
			number2 = number2 + 1;
			bottom_left = false;
		}
		if(bottom_right == true){
			number2 = number2 + 1;
			bottom_right = false;
		}
		if(right == true){
			number2 = number2 + 1;
			right = false;
		}
		if(left == true){
			number2 = number2 + 1;
			left = false;
		}
		if(top == true){
			number2 = number2 + 1;
			top = false;
		}
		if(top_left == true){
			number2 = number2 + 1;
			top_left = false;
		}
		if(top_right == true){
			number2 = number2 + 1;
			top_right = false;
		}
		
		if(number2 == 0){
			number3 = '0';
		}
		if(number2 == 1){
			number3 = '1';
		}
		if(number2 == 2){
			number3 = '2';
		}
		if(number2 == 3){
			number3 = '3';
		}
		if(number2 == 4){
			number3 = '4';
		}
		if(number2 == 5){
			number3 = '5';
		}
		if(number2 == 6){
			number3 = '6';
		}
		if(number2 == 7){
			number3 = '7';
		}
		if(number2 == 8){
			number3 = '8';
		}
		
		if(gra[number]==1){
			cout<<"Game over.";
			sleep(5000); 
			return;
		}		
		/*Wypisanie tablicy.*/
		
		else {
			/*Przypisanie wartości bomb wokół korydnatów do tablicy 2 (która wyświetla cały ten board jakby).*/
			if(gra2[number] == number3){
				gra2[number] = number3;
			}
			else{
				gra2[number] = number3;
				solution = solution + 1;
			}
			/*Wyczyszczenie konsoli.*/
			system("CLS");
			/*Drukowanie tablicy.*/
			cout<<"   A  B  C  D  E  F  G  H"<<endl<<endl;
			/*Nie można mieć dwóch integerów i w jednym zagnieżdzeniu for'ów!!!!*/
			for(int print = 0; print<12; print++){
				print = print+1;
				cout<<print;
				print = print-1;
		
				for(int j = 0; j<12; j++){
					cout<<"  "<<gra2[((print*12)+j)];
				}
				
				cout<<endl<<endl;
			}
			/*Wartość bomb wokół kordynatów jest równe 0.*/
			number3 = '0';
		}
		if(solution==120){
			/*Wygrałeś i odczekaj 5000ms.*/
			cout<<endl<<"You won!";
			sleep(5000); 
		}
	}
}

void gra_trudna(int gra[], char gra2[]){
	cout<<"    A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P"<<endl<<endl;
			for(int i = 0; i<9; i++){
				i = i+1;
				cout<<i;
				i = i-1;
		
				for(int j = 0; j<16; j++){
					if(j==0){
						cout<<"   "<<gra2[((i*16)+j)];
					}
					else{
						cout<<"  "<<gra2[((i*16)+j)];	
					}
				}
				cout<<endl<<endl;
			}
			for(int i = 9; i<16; i++){
				i = i+1;
				cout<<i;
				i = i-1;
		
				for(int j = 0; j<16; j++){
					cout<<"  "<<gra2[((i*16)+j)];
				}
				cout<<endl<<endl;
			}
	
	int row, number, number2, number3, number4;
	int solution = 0;
	char column;
	bool top_left, left = false;
	bool bottom_left, bottom = false;
	bool bottom_right, right = false;
	bool top_right, top = false;
	
	for(int i = 0; i>=0; i++){
		bool top_left, left = false;
		bool bottom_left, bottom = false;
		bool bottom_right, right = false;
		bool top_right, top = false;
		number3 = '0';
		number2 = 0;
		column = 'n';
		number = 0;
		do{
			cout<<endl<<"Type in the letter of the column: ";
			cin>>column;
		}
		while(
		column != 'A' && column != 'a' && 
		column != 'B' && column != 'b' && 
		column != 'C' && column != 'c' && 
		column != 'D' && column != 'd' && 
		column != 'E' && column != 'e' && 
		column != 'F' && column != 'f' && 
		column != 'G' && column != 'g' && 
		column != 'H' && column != 'h' && 
		column != 'I' && column != 'i' && 
		column != 'J' && column != 'j' && 
		column != 'K' && column != 'k' && 
		column != 'L' && column != 'l' && 
		column != 'M' && column != 'm' && 
		column != 'N' && column != 'n' && 
		column != 'O' && column != 'o' && 
		column != 'P' && column != 'p'
		);
		
		do{
			cout<<endl<<"Type in the number of the row: ";
			cin>>row;
		}
		while(row > 16 && row <= 0);


		
		if(column == 'A' || column == 'a'){
			number = 0;
			number4 = 0;
		}
		if(column == 'B' || column == 'b'){
			number = 1;
			number4 = 1;
		}
		if(column == 'C' || column == 'c'){
			number = 2;
			number4 = 2;
		}
		if(column == 'D' || column == 'd'){
			number = 3;
			number4 = 3;
		}
		if(column == 'E' || column == 'e'){
			number = 4;
			number4 = 4;
		}
		if(column == 'F' || column == 'f'){
			number = 5;
			number4 = 5;
		}
		if(column == 'G' || column == 'g'){
			number = 6;
			number4 = 6;
		}
		if(column == 'H' || column == 'h'){
			number = 7;
			number4 = 7;
		}
		if(column == 'I' || column == 'i'){
			number = 8;
			number4 = 8;
		}
		if(column == 'J' || column == 'j'){
			number = 9;
			number4 = 9;
		}
		if(column == 'K' || column == 'k'){
			number = 10;
			number4 = 10;
		}
		if(column == 'L' || column == 'l'){
			number = 11;
			number4 = 11;
		}
		if(column == 'M' || column == 'm'){
			number = 12;
			number4 = 12;
		}
		if(column == 'N' || column == 'n'){
			number = 13;
			number4 = 13;
		}
		if(column == 'O' || column == 'o'){
			number = 14;
			number4 = 14;
		}
		if(column == 'P' || column == 'p'){
			number = 15;
			number4 = 15;
		}
		
		number = number + ((row-1)*16);
		
		if(number3 != 0){
			number3 = 0;
		}
	
		/*sprawdzenie czy bomby są do okoła*/
		
		/*Top*/
		if(row==0){
			top = false;
			top_right = false;
			top_left = false;
		}
		else if(gra[(number-16)]==1 && row!=0){
			top = true;
		}
		
		/*Top_left i Top_right*/
		
		if(gra[(number-15)]==1 && (row!=0 && number4 !=15)){
			top_right = true;
		}
		if(gra[(number-17)]==1 && (row!=0 && number4 !=0)){
			top_left = true;
		}
		
		/*Right*/
		
		if(number4 == 15){
			top_right = false;
			right = false;
			bottom_right = false;
		}
		else if(gra[(number+1)]==1 && number4 != 15){
			right = true;
		}
		
		/*Left*/
		
		if(number4 == 0){
			bottom_left = false;
			left = false;
			top_left = false;
		}
		else if(gra[(number-1)]==1 && number4 != 0){
			left = true;
		}
		
		/*Bottom*/
		
		if(row==15){
			bottom = false;
			bottom_right = false;
			bottom_left = false;
		}
		else if(gra[(number+16)]==1 && row != 15){
			bottom = true;
		}
		
		/*Bottom_right i Bottom_left*/
		
		if(gra[(number+17)]==1 && (row!=11 && number4 !=15)){
				bottom_right = true;
		}
		if(gra[(number+15)]==1 && (row!=11 && number4 !=0)){
				bottom_left = true;
		}
		
		
		
		if(bottom == true){
			number2 = number2 + 1;
			bottom = false;
		}
		if(bottom_left == true){
			number2 = number2 + 1;
			bottom_left = false;
		}
		if(bottom_right == true){
			number2 = number2 + 1;
			bottom_right = false;
		}
		if(right == true){
			number2 = number2 + 1;
			right = false;
		}
		if(left == true){
			number2 = number2 + 1;
			left = false;
		}
		if(top == true){
			number2 = number2 + 1;
			top = false;
		}
		if(top_left == true){
			number2 = number2 + 1;
			top_left = false;
		}
		if(top_right == true){
			number2 = number2 + 1;
			top_right = false;
		}
		
		if(number2 == 0){
			number3 = '0';
		}
		if(number2 == 1){
			number3 = '1';
		}
		if(number2 == 2){
			number3 = '2';
		}
		if(number2 == 3){
			number3 = '3';
		}
		if(number2 == 4){
			number3 = '4';
		}
		if(number2 == 5){
			number3 = '5';
		}
		if(number2 == 6){
			number3 = '6';
		}
		if(number2 == 7){
			number3 = '7';
		}
		if(number2 == 8){
			number3 = '8';
		}
		
		if(gra[number]==1){
			cout<<"Game over.";
			sleep(5000); 
			return;
		}		
		/*Wypisanie tablicy.*/
		
		else {
			/*Przypisanie wartości bomb wokół korydnatów do tablicy 2 (która wyświetla cały ten board jakby).*/
			if(gra2[number] == number3){
				gra2[number] = number3;
			}
			else{
				gra2[number] = number3;
				solution = solution + 1;
			}
			/*Wyczyszczenie konsoli.*/
			system("CLS");
			/*Drukowanie tablicy.*/
			cout<<"   A  B  C  D  E  F  G  H"<<endl<<endl;
			/*Nie można mieć dwóch integerów i w jednym zagnieżdzeniu for'ów!!!!*/
			for(int print = 0; print<12; print++){
				print = print+1;
				cout<<print;
				print = print-1;
		
				for(int j = 0; j<12; j++){
					cout<<"  "<<gra2[((print*12)+j)];
				}
				
				cout<<endl<<endl;
			}
			/*Wartość bomb wokół kordynatów jest równe 0.*/
			number3 = '0';
		}
		if(solution==212){
			/*Wygrałeś i odczekaj 5000ms.*/
			cout<<endl<<"You won!";
			sleep(5000); 
		}
		}
	}



int main(){
	char diff, diff2;
	int diff3;
	diff2 = difficulty(diff);
	
	/*Jeżeli wartość diff2 jest równa: A,B,C ustaw wartość liczbową diff.*/
	
	if(diff2 == 'A' || diff2 == 'a'){
		diff3 = 1;
	}
	if(diff2 == 'B' || diff2 == 'b'){
		diff3 = 2;
	}
	if(diff2 == 'C' || diff2 == 'c'){
		diff3 = 3;
	} 
	/*Przypisanie wartości liczbowej do trudności poziomu.*/
	
	int n; 
	/*Do n-elementowej tablicy*/
	/*Jeżeli wartość diff3 jest równa ileś. Stwórz tablice n-elemntową o wartości: (elementy_tablicy)^2.*/
	if(diff3==1){
		n = 8*8;
	}
	if(diff3==2){
		n = 12*12;
	}
	if(diff3==3){
		n = 16*16;
	}
	
	/*Zadeklarowanie tablic.*/
	
	int gra[n], x;
	char gra2[n];
	srand(time(NULL));
	
	/*Wypisanie wartości do tablic.*/
	
	for(int i=0; i<n; i++){
		gra[i] = 0;
	}
	for(int i=0; i<n; i++){
		gra2[i] = 'x';
	}
	
	/*Wartość bomby jest równa 1, a puste pole 0.*/
	/*Wylosowanie miejsca bomb na polu.*/
	
	if(diff3==1){
		for(int i=0; i<=10; i++){
			x = rand()%64;
			if(gra[x] == 1){
				do{
					x = rand()%64;
				}
				while(gra[x] != 1);
			}
			else{
				gra[x] = 1;
			}
		}
	}
	if(diff3==2){
		for(int i=0; i<=24; i++){
			x = rand()%144;
			if(gra[x] == 1){
				do{
					x = rand()%144;
				}
				while(gra[x] != 1);
			}
			else{
				gra[x] = 1;
			}
		}
	}
	if(diff3==3){
		for(int i=0; i<=44; i++){
			x = rand()%256;
			if(gra[x] == 1){
				do{
					x = rand()%256;
				}
				while(gra[x] != 1);
			}
			else{
				gra[x] = 1;
			}
		}
	}
	
	/*Rozpoczęcie gry.*/
	
	if(diff2 == 'A' || diff2 == 'a'){
		gra_latwa(gra, gra2);
	}
	if(diff2 == 'B' || diff2 == 'b'){
		gra_srednia(gra, gra2);
	}
	if(diff2 == 'C' || diff2 == 'c'){
		gra_trudna(gra, gra2);
	} 
	return 0;
}