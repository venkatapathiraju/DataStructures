#pragma  once

#include <iostream>
#include <vector>

namespace graphtest {
	enum class city : int {LONDON,MOSCOW,ISTANBUL};

	std::ostream& operator << (std::ostream& os, const city c)
	{
		switch (c)
		{
		case city::LONDON:
			os << "LONDON";
			break;
		case city::MOSCOW:
			os << "MOSCOW";
			break;
		case city::ISTANBUL:
			os << "ISTANBUL";
			break;
		default:
			break;
		}
		return os;
	}


	struct graph
	{
		std::vector< std::vector<std::pair<int, int>> >data;

		graph(int n)
		{
			data = std::vector< std::vector<std::pair<int, int>> >(n, std::vector<std::pair<int, int> >());
		}

		void addEdge(const city c1, const city c2, int dis)
		{
			std::cout << "ADD: " << c1 << "-" << c2 << "=" << dis << std::endl;
			auto n1 = static_cast<int>(c1);
			auto n2 = static_cast<int>(c2);
			data[n1].push_back({n2,dis});
			data[n2].push_back({ n1,dis });
		}

		void removeEdge(const city c1, const city c2)
		{
			auto n1 = static_cast<int>(c1);
			auto n2 = static_cast<int>(c2);
			std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) { return pair.first == n2; });
			std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) { return pair.first == n1; });
		}
	};

	



	void graphtest()
	{
		graph g(3);

		g.addEdge(city::LONDON, city::MOSCOW, 900);

		g.addEdge(city::LONDON, city::ISTANBUL, 500);


		std::queue<int> order;
		std::vector<int> visited;
	
	}

}