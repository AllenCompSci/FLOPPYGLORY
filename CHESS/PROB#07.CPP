s this package weigh in lbs. (max. 10 lbs.)?"<<endl;
			cin >> Pkg;
		} while (Pkg > 10); //Will not continue until Pkg is less than 10
		Pkg = Pkg * 16;

	}
	else {
		do {
			cout << "About How much does this package weigh in ounces (max 160 oz.)?"<<endl;
			cin >> Pkg;
		} while (Pkg > 10 * 16); //Will not continue until Pkg is less than 160
	}

clrscr();

cout <<"Weight of Package: "<<Pkg<<" oz."<<endl;
cout << "Cost to send (In dollars) to location