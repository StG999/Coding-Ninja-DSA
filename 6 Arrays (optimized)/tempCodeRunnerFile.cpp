
    cin>>t;
    int ans[t];

    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;

        int input[n];
        for(int j=0; j<n; j++)
            cin>>input[j];
        
        ans[i] = uniqueElement(input, n);
    }

    for(int i=0; i<t; i++)
        cout<<ans[i