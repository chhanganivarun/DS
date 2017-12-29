class node:
    def __init__(self,value=None):
        self.value = value
        self.left_child = None
        self.right_child = None
        self.parent = None


class binary_search_tree:
    def __init__(self):
        self.root = None

    def insert(self,value):
        if self.root == None:
            self.root = node(value)
        else:
            self._insert(value,self.root)              #insert 
    
    def _insert(self,value,cur_node):
        if value < cur_node.value:
            if cur_node.left_child == None:
                cur_node.left_child = node(value)
                cur_node.left_child.parent = cur_node
            else:
                self._insert(value,cur_node.left_child)
        else:
            if cur_node.right_child == None:
                cur_node.right_child = node(value)
                cur_node.right_child.parent = cur_node
            else:
                self._insert(value,cur_node.right_child)
    def find(self,value):
        if self.root == None:
            return None
        else:
            return self._find(value,self.root)
    
    def _find(self,value,cur_node):
        if value == cur_node.value:
            return cur_node
        elif value<cur_node.value and cur_node.left_child != None:
            return self._find(value,cur_node.left_child)
        elif value>cur_node.value and cur_node.right_child != None:
            return self._find(value,cur_node.right_child)
        else:
            return None

    def delete_value(self,value):
        return self.delete_node(self.find(value))

    def delete_node(self,cur_node):
        
        def min_value_node(n):
            current = n
            while current.left_child != None:
                current = current.left_child
            return current
        no_of_nodes = 0
        
        if cur_node == None:
            return
        else:
            if cur_node.left_child != None:
                no_of_nodes = no_of_nodes + 1
            if cur_node.right_child != None:
                no_of_nodes = no_of_nodes + 1
           
            
            parent_node = cur_node.parent

            if no_of_nodes == 0:
                if parent_node.left_child == cur_node:
                    parent_node.left_child = None
                else:
                    parent_node.right_child = None

            if no_of_nodes == 1:
                
                if cur_node.left_child != None:
                    child = cur_node.left_child
                else:
                    child = cur_node.right_child

                if parent_node.left_child == cur_node:
                    parent_node.left_child = child
                    
                else:
                    parent_node.right_child = child
                    
                child.parent = parent_node

            if no_of_nodes == 2:
                successor = min_value_node(cur_node.right_child)
                cur_node.value = successor.value
                self.delete_node(successor)

            

    def print_tree(self):
        if self.root != None:
            self._print_tree(self.root)
    
    def _print_tree(self,cur_node):
        if cur_node!= None:
            self._print_tree(cur_node.left_child)
            print str(cur_node.value)
            self._print_tree(cur_node.right_child)

    def height(self):
        if self.root != None:
            return self._height(self.root,0)
        else:
            return 0
    def _height(self,cur_node,cur_height):
        if cur_node == None : return cur_height
        left_height = self._height(cur_node.left_child,cur_height+1)
        right_height = self._height(cur_node.right_child,cur_height+1)
        return max(left_height,right_height)

    def search(self,value):
        if self.root!=None:
            return self._search(value,self.root)
        else :
            return False
    def _search(self,value,cur_node):
        if value == cur_node.value:
            return True
        elif value<cur_node.value and cur_node.left_child != None:
            return self._search(value,cur_node.left_child)
        elif value>cur_node.value and cur_node.right_child != None:
            return self._search(value,cur_node.right_child)
        else: return False
    
    

def fill_tree(tree,num_elems=100,max_int=100):
    from random import randint
    for _ in range(num_elems) :
        cur_elem = randint(0,max_int)
        tree.insert(cur_elem)
    return tree

#tree = binary_search_tree()
#tree.insert(10)
#tree.insert(12)
#tree.insert(15)
#tree.insert(8)
#tree.insert(25)
#tree.print_tree()
#tree.delete_value(10)
#tree.delete_value(12)
#tree.print_tree()
#tree = fill_tree(tree)
#print tree.search(50)
#tree.print_tree()
#print tree.height()