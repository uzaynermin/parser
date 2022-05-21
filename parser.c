//Nermin UZAY 02200201019
//Clion,C99 versiyonu kullanildi
#include <stdio.h>
#include <stdbool.h>

bool isDelimiter(char ch) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool isDelimiter2(char ch[]) {
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' ||
        ch == '<' || ch == '=')
        return (true);
    return (false);
}

bool isId(char ch[255][255], int count) {
    if (ch[count][0] == 'A' || ch[count][0] == 'B'  ||
        ch[count][0] == 'C' || ch[count][0] == 'D'  ||
        ch[count][0] == 'E' || ch[count][0] == 'F' )
        return true;
    return false;
}

bool isIf(char ch[255][255], int count) {
    if (ch[count][0] == 'i' && ch[count][1] == 'f')
        return true;
    return false;
}

bool isElseIf(char ch[255][255], int count) {
    if (ch[count][0] == 'e' && ch[count][1] == 'l' && ch[count][2] == 's' && ch[count][3] == 'e' &&
        ch[count][4] == 'i' && ch[count][5] == 'f')
        return true;
    return false;
}

bool isElse(char ch[255][255], int count) {
    if (ch[count][0] == 'e' && ch[count][1] == 'l' && ch[count][2] == 's' && ch[count][3] == 'e')
        return true;
    return false;

}

bool isBraceL(char ch[255][255], int count) {
    if (ch[count][0] == '(')
        return true;
    return false;
}

bool isBraceR(char ch[255][255], int count) {
    if (ch[count][0] == ')')
        return true;
    return false;
}

bool isOp(char ch[255][255], int count) {
    if (ch[count][0] == '<' || ch[count][0] == '>' || ch[count][0] == "<=" || ch[count][0] == ">=" ||
        ch[count][0] == '=' && ch[count][1] == '=')
        return true;
    return false;
}

bool isBrace1(char ch[255][255], int count) {
    if (ch[count][0] == '{')
        return true;
    return false;
}

bool isBrace2(char ch[255][255], int count) {
    if (ch[count][0] == '}')
        return true;
    return false;
}

bool equal(char ch[255][255], int count) {
    if (ch[count][0] == '=')
        return true;
    return false;
}

bool isOp1(char ch[255][255], int count) {
    if (ch[count][0] == '+' || ch[count][0] == '-' || ch[count][0] == '*' || ch[count][0] == '/' || ch[count][0] == '=')
        return true;
    return false;
}

int ifgrammar(char final[255][255], int count) {
    bool a;
    printf("%s", final[count]);
    count++;
    a = isBraceL(final, count);
    if (a == true) {
        printf("%s", final[count]);
        count++;
        a = isId(final, count);
        if (a == true) {
            printf("%s", final[count]);
            count++;
            a = isOp(final, count);
            if (a == true) {
                printf("%s", final[count]);
                count++;
                a = isId(final, count);
                if (a == true) {
                    printf("%s", final[count]);
                    count++;
                    a = isBraceR(final, count);
                    if (a == true) {
                        printf("%s", final[count]);
                        count++;
                        count++;
                        a = isBrace1(final, count);
                        if (a == true) {
                            printf("%s", final[count]);
                            count++;
                            a = isId(final, count);
                            if (a == true) {
                                printf("%s", final[count]);
                                count++;
                                a = equal(final, count);
                                if (a == true) {
                                    printf("%s", final[count]);
                                    count++;
                                    a = isId(final, count);
                                    if (a == true) {
                                        printf("%s", final[count]);
                                        count++;
                                        a = isOp1(final, count);
                                        if (a == true) {
                                            printf("%s", final[count]);
                                            count++;
                                            a = isId(final, count);
                                            if (a == true) {
                                                printf("%s", final[count]);
                                                count++;
                                                a = isBrace2(final, count);
                                                if (a == true) {
                                                    printf("%s", final[count]);
                                                    printf("\nif blogu hatasiz hatasiz");
                                                } else {
                                                    printf("%s", final[count]);
                                                    printf("\nhata!! %d. satirinda } bekleniyor", count);
                                                    return 0;
                                                }

                                            } else {
                                                printf("%s", final[count]);
                                                printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                                                return 0;
                                            }
                                        } else {
                                            printf("\n%s", final[count]);
                                            printf("\nhata!! %d. satirinda islem operatoru bekleniyor", count);
                                            return 0;
                                        }
                                    } else {
                                        printf("\n%s", final[count]);
                                        printf("\n%hata!! %d. satirinda id elemani bekleniyor", count);
                                        return 0;
                                    }
                                } else {
                                    printf("\n%s", final[count]);
                                    printf("\nhata!! %d. satirinda = bekleniyor", count);
                                    return 0;
                                }
                            } else {
                                printf("%s", final[count]);
                                printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                                return 0;
                            }
                        } else {
                            printf("%s", final[count]);
                            printf("\nhata!! %d. satirinda { bekleniyor", count);
                            return 0;
                        }
                    } else {
                        printf("%s", final[count]);
                        printf("\nhata!! %d. satirinda ) bekleniyor", count);
                    }
                } else {
                    printf("%s", final[count]);
                    printf("\nhata!! %d. satirinda id elemani bekleniyor");
                    return 0;
                }
            } else {
                printf("%s", final[count]);
                printf("\nhata!! %d. satirinda mantik operatoru bekleniyor");
                return 0;
            }
        } else {
            printf("%s", final[count]);
            printf("\nhata!! %d. satirinda id elemani bekleniyor");
            return 0;
        }
    } else {
        printf("%s", final[count]);
        printf("\nhata!! %d. satirinda ( bekleniyor");
        return 0;
    }
    return count;
}

int elseifgrammar(char final[255][255], int count) {
    bool a;
    printf("%s", final[count]);
    count++;
    a = isBraceL(final, count);
    if (a == true) {
        printf("%s", final[count]);
        count++;
        a = isId(final, count);
        if (a == true) {
            printf("%s", final[count]);
            count++;
            a = isOp(final, count);
            if (a == true) {
                printf("%s", final[count]);
                count++;
                a = isId(final, count);
                if (a == true) {
                    printf("%s", final[count]);
                    count++;
                    a = isBraceR(final, count);
                    if (a == true) {
                        printf("%s", final[count]);
                        count++;
                        count++;
                        a = isBrace1(final, count);
                        if (a == true) {
                            printf("%s", final[count]);
                            count++;
                            a = isId(final, count);
                            if (a == true) {
                                printf("%s", final[count]);
                                count++;
                                a = equal(final, count);
                                if (a == true) {
                                    printf("%s", final[count]);
                                    count++;
                                    a = isId(final, count);
                                    if (a == true) {
                                        printf("%s", final[count]);
                                        count++;
                                        a = isOp1(final, count);
                                        if (a == true) {
                                            printf("%s", final[count]);
                                            count++;
                                            a = isId(final, count);
                                            if (a == true) {
                                                printf("%s", final[count]);
                                                count++;
                                                a = isBrace2(final, count);
                                                if (a == true) {
                                                    printf("%s", final[count]);
                                                    printf("\nelseif blogu hatasiz\n");
                                                } else {
                                                    printf("%s", final[count]);
                                                    printf("\nhata!! %d. satirinda } bekleniyor", count);
                                                    return 0;
                                                }

                                            } else {
                                                printf("%s", final[count]);
                                                printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                                                return 0;
                                            }
                                        } else {
                                            printf("\n%s", final[count]);
                                            printf("\nhata!! %d. satirinda islem operatoru bekleniyor", count);
                                            return 0;
                                        }
                                    } else {
                                        printf("\n%s", final[count]);
                                        printf("\n%hata!! %d. satirinda id elemani bekleniyor", count);
                                        return 0;
                                    }
                                } else {
                                    printf("\n%s", final[count]);
                                    printf("\nhata!! %d. satirinda = bekleniyor", count);
                                    return 0;
                                }
                            } else {
                                printf("%s", final[count]);
                                printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                                return 0;
                            }
                        } else {
                            printf("%s", final[count]);
                            printf("\nhata!! %d. satirinda { bekleniyor", count);
                            return 0;
                        }
                    } else {
                        printf("%s", final[count]);
                        printf("\nhata!! %d. satirinda ) bekleniyor", count);
                    }
                } else {
                    printf("%s", final[count]);
                    printf("\nhata!! %d. satirinda id elemani bekleniyor");
                    return 0;
                }
            } else {
                printf("%s", final[count]);
                printf("\nhata!! %d. satirinda mantik operatoru bekleniyor");
                return 0;
            }
        } else {
            printf("%s", final[count]);
            printf("\nhata!! %d. satirinda id elemani bekleniyor");
            return 0;
        }
    } else {
        printf("%s", final[count]);
        printf("\nhata!! %d. satirinda ( bekleniyor");
        return 0;
    }
    return count;

}

int elsegrammar(char final[255][255], int count) {
    bool a;
    printf("%s", final[count]);
    count++;
    a = isBrace1(final, count);
    if (a == true) {
        printf("%s", final[count]);
        count++;
        a = isId(final, count);
        if (a == true) {
            printf("%s", final[count]);
            count++;
            a = equal(final, count);
            if (a == true) {
                printf("%s", final[count]);
                count++;
                a = isId(final, count);
                if (a == true) {
                    printf("%s", final[count]);
                    count++;
                    a = isOp1(final, count);
                    if (a == true) {
                        printf("%s", final[count]);
                        count++;
                        a = isId(final, count);
                        if (a == true) {
                            printf("%s", final[count]);
                            count++;
                            a = isBrace2(final, count);
                            if (a == true) {
                                printf("%s", final[count]);
                                printf("\nelse blogu hatasiz");
                            } else {
                                printf("%s", final[count]);
                                printf("\nhata!! %d. satirinda } bekleniyor", count);
                                return 0;
                            }

                        } else {
                            printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                            return 0;
                        }
                    } else {
                        printf("\nhata!! %d. satirinda islem operatoru bekleniyor", count);
                        return 0;
                    }
                } else {
                    printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
                    return 0;
                }
            } else {
                printf("\nhata!! %d. satirinda = bekleniyor", count);
                return 0;
            }
        } else {
            printf("\nhata!! %d. satirinda id elemani bekleniyor", count);
            return 0;
        }
    } else {
        printf("\nhata!! %d. satirinda { bekleniyor", count);
        return 0;
    }
}

int main() {

    char buffer;
    char final[255][255];
    char filearray[255];
    int counter = 0;
    int i = 0;
    int j = 0;
    char ch;
    char ch1;
    char file[255];


    printf("dosyanin adresini girin \n Ornegin : C:\\Users\\Dell\\Desktop\\file.txt \n");
    scanf("%s", &file);
    FILE *fn = fopen(file, "r");


//dosya içeriğini diziye aktarma
    if (fn == NULL) {
        fprintf(stderr, "Unable to open file %s\n", file);
    } else {
        while ((buffer = getc(fn)) != EOF) {
            printf("%c",buffer);
            if (buffer == '\t' || buffer == '\n' || buffer == ' ') {
            } else {
                filearray[counter] = buffer;
                counter++;
            }
        }

    }

//dizideki dosya içeriğini ekrana yazma
    for (int k = 0; k < counter; k++) {
        printf("%c  ", filearray[k]);

    }
    printf("\n");
    printf("\n");

    //tokenizer

    for (int k = 0; k < counter; ++k) {
        ch = filearray[k];
        ch1 = filearray[k+1];
        if (isDelimiter(ch) == false ) {
            final[i][j] = ch;
            j++;
            final[i][j] = '/0 ';
        }
        else {
            if(isDelimiter(ch) == true){
                final[i][j] = '/0 ';
                i++;
                j = 0;
                if(isDelimiter2(ch1) == true){

                    final[i][j] = ch;
                    j++;
                    final[i][j] = ch1;
                    j++;
                    final[i][j] = '/0 ';
                    i++;
                    j = 0;
                    k++;
                }
                else{

                    final[i][j] = ch;
                    j++;
                    final[i][j] = '/0 ';
                    i++;
                    j = 0;
                }
            }
        }
    }

    for (int k = 0; k < i; ++k) {
        printf("%s", final[k]);
        printf("\n ");
    }

    //parser

    int count = 0;
    bool c;
    bool a;
    int count1;
    int count2;
    bool d;

    int ifcounter = 0;
    a = isIf(final, count);   // if kelimesi kontrolu
    if (a == true) {
        ifcounter++;
        count1 = ifgrammar(final, count);
    } else {
        printf("hata!! if komutu bekleniyor");
    }

    printf("\n");
    while ((c = isElseIf(final, count1 + 1)) == true) { // elseif kelimesi kontrolu
        count1 = elseifgrammar(final, count1 + 1);
    }
    printf("\n");

    d = isElse(final, count1 + 1); // else kelimesi kontrolu
    if (d == true && ifcounter == 1) {
        if (d == true) {
            elsegrammar(final, count1 + 1);
        } else {
            elsegrammar(final, count2 + 1);
        }
    }
    ifcounter--;


    fclose(fn);

    return 0;
}
//kosul sadece id icin ayarlanmis a>b gibi sayi gelme ihtimali handle edilmemis