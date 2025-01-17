///Simono Šaltenio 2gr. 2pogr. v0.5.1

#include "header.h"

int main()
{
    cout << "Jei norite duomenis ivesti pats, iveskite 0" << endl;
    cout << "Jei norite duomenis nuskaityti is failo, iveskite 1" << endl;
    cout << "Jei norite sukurti random duomenu faila, iveskite 2 (visi skaiciavimai nuo v0.4 irgi yra realizuojami sitam pasirinkime)" << endl;
    int arDuom=3;
    tikrinimasDuom(arDuom);

    if(arDuom==1){
        cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
        int ar=2;
        //tikrina ar ivedamas geras skaicius
        tikrinimasBinarinio(ar);

        vector<stud> studentai;
        std::ifstream fin ("duom.txt");
        string line;
        try{
            if(!fin) throw "FAILAS NEEGZISTUOJA";

            while (getline(fin, line)){
                if(line!=""){
                    stud temp;
                    int x;
                    std::istringstream iss(line);
                    iss >> temp.vardas;
                    iss >> temp.pavarde;

                    while(!iss.eof()){
                        iss >> x;
                        if(iss.fail()) {
                            iss.clear();
                            string laikinas;
                            iss >> laikinas;
                            continue;
                            /*cout << "Blogai ivesti duomenys" << endl;
                            exit(EXIT_FAILURE);*/
                        }
                        else if(x<0 || x>10){
                        continue;
                        }
                        else temp.nd.push_back(x);
                    }
                    temp.egz=temp.nd.back();
                    temp.nd.pop_back();

                    if(ar==1) temp.galutinis=galVid(temp);
                    else temp.galutinis=galMed(temp);

                    studentai.push_back(temp);
                }
                else continue;
            }
            isvedimas(studentai, ar);
        }catch(const char* msg){
        cout << msg << endl;
        }
    }
    else if(arDuom==0){
        cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
        int ar=2;
        //tikrina ar ivedamas geras skaicius
        cin.clear();
        tikrinimasBinarinio(ar);

        cout << "Kiek studentu bus is viso:" << endl;
        int n;
        //tikrina ar ivedamas geras skaicius
        while(1){
            cin >> n;
            if(cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Ivedete ne int'a" << endl;
            }
            else if (n<=0) cout << "Studentu turi buti daugiau nei 0" << endl;
            else break;
        }

        cout << "Jei norite, kad gautieji balai uz n.d butu sugeneruoti atsitiktinai, iveskite 1, jei norite irasyti patys, iveskite 0" << endl;
        int arNd=2;
        //tikrina ar ivedamas geras skaicius
        tikrinimasBinarinio(arNd);

        vector<stud> studentai;
        for(int i=0; i<n; i++) {
            stud temp;
            cout << "Iveskite studento varda ir pavarde:" << endl;
            cin >> temp.vardas;
            cin >> temp.pavarde;
            cout << "Iveskite egzamino rezultata: " << endl;
            //tikrina ar ivedamas geras skaicius
            while(1){
                cin >> temp.egz;
                if(cin.fail()){
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Ivedete ne int'a" << endl;
                }
                else if (temp.egz>10 || temp.egz<0) cout << "Egzamino rezultatas turi but tarp 0 ir 10" << endl;
                else break;
            }

            if(arNd==0){
                cout << "Ivesktie N.D pazymius (kai noresite nutraukti ivedima, iveskite neigiama int'a): " << endl;
                ivedimas(temp);
            }
            else{
                cout << "Kiek n.d pazymiu norite, jog butu sugeneruota?" << endl;
                int kiek;
                //tikrina ar ivedamas geras skaicius
                while(1){
                    cin >> kiek;
                    if(cin.fail()){
                    cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Ivedete ne int'a" << endl;
                    }
                    else if (kiek<=0) cout << "Pazymiu turi buti daugiau nei 0" << endl;
                    else break;
                }
                generavimas(temp, kiek);
            }

            if(ar==1) temp.galutinis=galVid(temp);
            else temp.galutinis=galMed(temp);

            studentai.push_back(temp);

        }
        isvedimas(studentai, ar);
    }
    else{
        //PASIRINKTI KIEK IRASU
        int kiekIrasu=100000;
        //generavimasFailo(kiekIrasu);

        /// paprastumo delei v0.5 versijoje skaiciavimus atliksiu tik su vidurkiu
        // cout << "Jei norite skaiciuoti su vidurkiu, iveskite 1, jei su mediana 0: " << endl;
        int ar=1;

        cout << "Pirma strategija - 1" << endl;
        cout << "Antra strategija - 0" << endl;
        int arStr=2;
        tikrinimasBinarinio(arStr);

        auto start = std::chrono::system_clock::now();

        //NORINT PASIRINKTI, KOKI KONTEINERI NAUDOTI, REIKIA UZKOMENTUOTI LIKUSIUS 2

        vector<stud> studentai;
        vector<stud> vargsiukai;
        vector<stud> kietakai;

        //deque<stud> studentai;
        //deque<stud> vargsiukai;
        //deque<stud> kietakai;

        //list<stud> studentai;
        //list<stud> vargsiukai;
        //list<stud> kietakai;

        std::ifstream fin ("generatedfile.txt");
        string line;
        try{
            if(!fin) throw "FAILAS NEEGZISTUOJA";

            while (getline(fin, line)){
                if(line!=""){
                    stud temp;
                    int x;
                    std::istringstream iss(line);
                    iss >> temp.vardas;
                    iss >> temp.pavarde;

                    while(!iss.eof()){
                        iss >> x;
                        if(iss.fail()) {
                            iss.clear();
                            string laikinas;
                            iss >> laikinas;
                            continue;
                            /*
                            arba butu galima is viso sustabdyti programa
                            cout << "Blogai ivesti duomenys" << endl;
                            exit(EXIT_FAILURE);
                            */
                        }
                        else if(x<0 || x>10){
                        continue;
                        }
                        else temp.nd.push_back(x);
                    }
                    temp.egz=temp.nd.back();
                    temp.nd.pop_back();

                    if(ar==1) temp.galutinis=galVid(temp);
                    else temp.galutinis=galMed(temp);

                    studentai.push_back(temp);
                }
                else continue;
            }

            //UZKOMENTUOTA NUO V1.0, KAD VEIKTU PAPILDOMA UZDUOTIS
            /*
            if(arStr==1){
                rusiavimasStudentu(studentai, vargsiukai, kietakai, kiekIrasu);
                surusiuotuIsvedimas(vargsiukai, kietakai);
            }
            else{
                /*int f=0;
                rusiavimasStudentu(studentai, vargsiukai, kiekIrasu);
                surusiuotuIsvedimas(vargsiukai, studentai, f);
                */
            //    rusiavimasSuPartition(studentai);
            //}

            //PAPILDOMA UZDUOTIS
            //raskMinkstus(studentai, vargsiukai);
            iterpkKietus(studentai, vargsiukai);

            auto end = std::chrono::system_clock::now();
            auto elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            auto elapsedS = std::chrono::duration_cast<std::chrono::seconds>(end - start);
            cout << "Programos trukme: " << elapsedMS.count() << "ms arba apytiksliai " << elapsedS.count() << "s" << endl;
        }catch(const char* msg){
        cout << msg << endl;
        }
    }
    return 0;
}
