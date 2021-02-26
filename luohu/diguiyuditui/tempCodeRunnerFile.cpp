    ll x,y,z;
    cin>>x>>y>>z;
    while(x!=-1&&y!=-1&&z!=-1){
        // printf("w(%ll,%ll,%ll) = %ll\n",x,y,z,dfs(x,y,z));
        cout<<"w("<<x<<", "<<y<<", "<<z<<")"<<' '<<'='<<' '<<dfs(x,y,z)<<endl;
        cin>>x>>y>>z;
    }