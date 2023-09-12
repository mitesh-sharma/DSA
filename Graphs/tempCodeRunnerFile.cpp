auto result = st.find(make_pair(dist[nbr.first], nbr.first));
                        if(result != st.end()){
                            //remove it if found already
                            st.erase(result);
                        }