map<int, int>::iterator i;
    for(i = skills.begin(); i!=skills.end(); ++i){
        cout << "{" << i->first << ": " << i->second << "}\n";
    }