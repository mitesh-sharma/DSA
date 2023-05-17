void PrintFromStartToEnd(vector <int>& v, int start, int end){
    //base case
    if(end == v.size()){
        return;
    }

    // ek case
    for(int i=start; i<=end; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    //recursive call
    PrintFromStartToEnd(v, start , end+1);

}   

void printSubarray(vector <int>& v){
    for(int start = 0; start<v.size(); start++){
        PrintFromStartToEnd(v, start, 0);
    }
}

int main()
{
    vector <int> v = {1,2,3,4,5};
    printSubarray(v);

    return 0;
}