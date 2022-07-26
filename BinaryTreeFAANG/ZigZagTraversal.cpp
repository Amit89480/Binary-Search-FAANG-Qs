// The solutions are in the java

/*class GFG
{
   //Function to store the zig zag order traversal of tree in a list.
ArrayList<Integer> zigZagTraversal(Node root)
{
    //Add your code here.
    ArrayList<Integer> di = new ArrayList<>();
    Queue<Node> q = new LinkedList<>();
    q.add(root);
    int c = 0;
    while(!q.isEmpty()){
        int size = q.size();
        List<Integer> temp = new ArrayList<>();
        while(size-->0){
            root = q.remove();
            temp.add(root.data);
            if(root.left != null){
                q.add(root.left);
            }
            if(root.right != null){
                q.add(root.right);
            }
        }
        if(c%2 != 0){
        for(int i=temp.size()-1;i>=0;i--){
             di.add(temp.get(i));
            }
        }
        else{
            for(int i=0;i<temp.size();i++){
                di.add(temp.get(i));
            }
           }
        c++;
    }
    return di;
}
}*/