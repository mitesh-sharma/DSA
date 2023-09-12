if(v[i] != -1){
            int ans = -1;
            if(v[i]%2 == 0){
                ans = i + (v[i]-1)/2;
            }
            else{
                ans = i + v[i]/2;
            }
            mini = min(mini, ans);
        }