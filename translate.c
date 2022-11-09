/* 
        translate.c
        Nikos Giovanopoulos
*/
#include<stdio.h>

#define tonos 39        /*orismos statherwn*/
#define dialutika 34

enum state{Sany=0,SM,SN,Sm,Sn} S; /*dhlwsh twn katastasewn ths FSM xrhsimopoiwntas enums*/

void init_map(char map[256][3]){ /*sunarthsh arxikopoihshs pinaka metafrashs*/

	int i;
        for(i = 0; i < 256; i++){   /*gemisma olou tou array me ola ta codes tou iso8859-7*/
		map[i][0] = i;
		map[i][1] = '\0';
		map[i][2] = '\0';   /*gemisma me null terminator sth 2h kai 3h grammh tou pinaka*/
	}

        map[193][0] = 'A';      /*kefalaia*/
        map[194][0] = 'V';
        map[195][0] = 'G';      /*Sthn sunexeia assignment stis theseis twn ellhnika grammatwn me ta antistoixa agglika */
        map[196][0] = 'D';
        map[197][0] = 'E';
        map[198][0] = 'Z';
        map[199][0] = 'H';
        map[200][0] = '8';
        map[201][0] = 'I';      /*Oi deiktes tou pinaka antistoixoun ston dekadiko arithmo twn ellhnikwn xarakthrwn*/
        map[202][0] = 'K';      /*enw to periexomeno tou kathe keliou ston antistoixo aggliko tou xarakthra*/
        map[203][0] = 'L';
        map[204][0] = 'M';
        map[205][0] = 'N';

        map[206][0] = 'K';      /*xrhsh 2d-array wste na mporei se enan elliniko xarakthra na antistoixhthei*/
        map[206][1] = 'S';      /*parapanw apo enas agglikos xarakthras, xrhsimopowntas stules(columns)*/

        map[207][0] = 'O';
        map[208][0] = 'P';
        map[209][0] = 'R';
        map[211][0] = 'S';
        map[212][0] = 'T';
        map[213][0] = 'Y';
        map[214][0] = 'F';
        map[215][0] = 'X';

        map[216][0] = 'P';
        map[216][1] = 'S';

        map[217][0] = 'W';

        map[225][0] = 'a';      /*mikra*/
        map[226][0] = 'v';
        map[227][0] = 'g';
        map[228][0] = 'd';
        map[229][0] = 'e';
        map[230][0] = 'z';
        map[231][0] = 'h';
        map[232][0] = '8';
        map[233][0] = 'i';
        map[234][0] = 'k';
        map[235][0] = 'l';
        map[236][0] = 'm';
        map[237][0] = 'n';

        map[238][0] = 'k';
        map[238][1] = 's';

        map[239][0] = 'o';
        map[240][0] = 'p';
        map[241][0] = 'r';
        map[242][0] = 's';
        map[243][0] = 's';
        map[244][0] = 't';
        map[245][0] = 'y';
        map[246][0] = 'f';
        map[247][0] = 'x';

        map[248][0] = 'p';
        map[248][1] = 's';

        map[249][0] = 'w';

	map[182][0] = tonos;    /*kefalaia me tonous*/
	map[182][1] = 'A';
	map[184][0] = tonos;
	map[184][1] = 'E';
	map[185][0] = tonos;
	map[185][1] = 'H';
	map[186][0] = tonos;
	map[186][1] = 'I';
	map[188][0] = tonos;
	map[188][1] = 'O';
	map[190][0] = tonos;
	map[190][1] = 'Y';
	map[191][0] = tonos;
	map[191][1] = 'W';
	
	map[220][0] = 'a';     /*mikra me tonous*/ 
	map[220][1] = tonos;
	map[221][0] = 'e';
	map[221][1] = tonos;
	map[222][0]  = 'h';
	map[222][1] = tonos;
	map[223][0] = 'i';
	map[223][1] = tonos;
	map[252][0] = 'o';
	map[252][1] = tonos;
	map[253][0] = 'y';
	map[253][1] = tonos;
	map[254][0] = 'w';
	map[254][1] = tonos;

	map[218][0] = 'I';     /*kefalaia/mikra  me dialutika*/ 
	map[218][1] = dialutika;
	map[219][0] = 'Y';
	map[219][1] = dialutika;
	map[250][0] = 'i';
	map[250][1] = dialutika;
	map[251][0] = 'y';
	map[251][1] = dialutika;
	map[192][0] = 'i';
	map[192][1] = tonos;
	map[192][2] = dialutika;
	map[224][0] = 'y';
	map[224][1] = tonos;
	map[224][2] = dialutika;
}

void print_char(int c){ /*sunarthsh ektupwshs stoixeiwn tou pinaka metafrashs*/

 	int j;
        char map[256][3];       /*klhsh sunarthshs arxikopoihshs pinaka*/
        
        init_map(map);
	for (j=0; j<3; j++){
                if(map[c][j] != '\0')   /*elegxos gia to an ta epilegomena kelia einai kena h gemata kai ara etoima gia tupwsh*/
                    putchar(map[c][j]);    
        }
}

/*Sunarthseis FSM
Epistrefoun ena state me vash ton xarakthra pou lamvanoun ws orisma kai upo
orismenes sunthikes ektupwnoun xarakthres kalwntas thn print_char)*/

enum state func_any(int c){ /*sunarhsh gia otan to state einai any*/
	
 	switch (c){
		case 204: /*M_gr*/
			return SM;
			break;
		case 236: /*m_gr*/
			return Sm;
			break;
		case 205: /*N_gr*/
			return SN;
			break;
		case 237: /*n_gr*/
			return Sn;
			break;
		default:
			print_char(c);
			return Sany;
			break;	
	}
}

enum state func_M(int c){ /*gia otan to state einai M*/

	switch(c){
		case 208: /*P_gr*/
                        print_char(66); /*B_en*/
			return Sany;
			break;
		case 240: /*p_gr*/
			print_char(66); /*B_en*/
			return Sany;
			break;
		case 204: /*M_gr*/
			print_char(204);
			return SM;
			break;
		case 236: /*m_gr*/
			print_char(204);
			return Sm;
			break;
		case 205: /*N_gr*/
			print_char(204); 
			return SN;
			break;
		case 237: /*n_gr*/
			print_char(204);
			return Sn;
			break;
		default:
			print_char(204);
			print_char(c);
			return Sany;
			break;
	}
}

enum state func_m(int c){ /*gia otan to state einai m*/

        switch(c){
                case 208: /*P_gr*/
                        print_char(98); /*b_en*/
                        return Sany;
                        break;
                case 240: /*p_gr*/
                        print_char(98); /*b_en*/
                        return Sany;
                        break;
                case 204: /*M_gr*/
                        print_char(236);
                        return SM;
                        break;
                case 236: /*m_gr*/
                        print_char(236);
                        return Sm;
                        break;
                case 205: /*N_gr*/
                        print_char(236);
                        return SN;
                        break;
                case 237: /*n_gr*/
                        print_char(236);
                        return Sn;
                        break;
                default:
                        print_char(236);
                        print_char(c);
                        return Sany;
                        break;
        }
}

enum state func_N(int c){ /*gia otan to state einai N*/

        switch(c){
                case 212: /*T_gr*/
                        print_char(68); /*D_en*/
                        return Sany;
                        break;
                case 244: /*t_gr*/
                        print_char(68); /*D_en*/
                        return Sany;
                        break;
                case 205: /*N_gr*/
                        print_char(205);
                        return SN;
                        break;
                case 237: /*n_gr*/
                        print_char(205);
                        return Sn;
                        break;
                case 204: /*M_gr*/
                        print_char(205);
                        return SM;
                        break;
                case 236: /*m_gr*/
                        print_char(205);
                        return Sm;
                        break;
                default:
                        print_char(205);
                        print_char(c);
                        return Sany;
                        break;
        }
}

enum state func_n(int c){ /*gia otan to state einai  n*/

        switch(c){
                case 212: /*T_gr*/
                        print_char(100); /*d_en*/
                        return Sany;
                        break;
                case 244: /*t_gr*/
                        print_char(100); /*d_en*/
                        return Sany;
                        break;
                case 204: /*M_gr*/
                        print_char(237);
                        return SM;
                        break;
                case 236: /*m_gr*/
                        print_char(237);
                        return Sm;
                        break;
                case 205: /*N_gr*/
                        print_char(237);
                        return SN;
                        break;
                case 237: /*n_gr*/
                        print_char(237);
                        return Sn;
                        break;
                default:
                        print_char(237); /*n_gr*/
                        print_char(c);
                        return Sany;
                        break;
        }
}

enum state (*funcptr[])(int c)={func_any,func_M,func_N,func_m,func_n}; /*array apo pointers se sunarthseis FSM*/

int main(){ /*kuria sunarthsh*/

	int c;
	enum state S = Sany; /*arxikopoihsh state se any*/
	
	while ((c=getchar()) != EOF){
		S = (funcptr[S])(c);
	}
	return 0;
}