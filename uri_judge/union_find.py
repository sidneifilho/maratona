
#Union-Find Algorithm | Set 1 (Detect Cycle in a an Undirected Graph)

class Edge:
	def __init__(self, s, d):
		self.src = a
		self.dest = b

class Subset:
	def __init__(self, p, r):
		self.parent = p
		self.rank = r

class Graph:
	def __init__(self, V, E):
		self.V = V
		self.E = E
		self.edges = [None]*E

	def addedge(self, idx, a, b):
		self.edges[idx] = (Edge(a, b))

	# A utility function to find set of an element i
	# (uses path compression technique)
	def find(self, subsets, i):
		if(subsets[i].parent != i):
			subsets[i].parent = self.find(subsets, subsets[i].parent)
			
		return subsets[i].parent

	# A function that does union of two sets of x and y
	# (uses union by rank)
	def Union(self, subsets, x, y):
		xroot = self.find(subsets, x)
		yroot = self.find(subsets, y)

		# Attach smaller rank tree under root of high rank tree
    	#(Union by Rank)
		if(subsets[xroot].rank < subsets[yroot].rank):
			subsets[xroot].parent = yroot
		elif(subsets[xroot].rank > subsets[yroot].rank):
			subsets[yroot].parent = xroot
		else:
			subsets[yroot].parent = xroot
			subsets[xroot].rank += 1

	def iscycle(self):

		subsets = [-1]*self.V
		for v in range(0, self.V):
			subsets[v] = Subset(v,0)

		for e in self.edges:
			xset = self.find(subsets, e.src)
			yset = self.find(subsets, e.dest)

			if(xset == yset):
				return True

			self.Union(subsets, xset, yset)

		return False


T = int(input())

i=0
while(i<T):


	N, M = map(int, input().split(' '))

	g = Graph(N, M)

	j=0
	while(j<M):

		a, b = map(int, input().split(' '))
		a-=1
		b-=1

		g.addedge(j, a, b)

		j+=1

	if(g.iscycle()):
		print('SIM')
	else:
		print('NAO')

	i+=1