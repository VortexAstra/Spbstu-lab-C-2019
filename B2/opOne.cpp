#include "queue.hpp"
#include <algorithm>
#include <sstream>
#include <vector>
#include <iostream>

void runOption1()
{
  QueueWithPriority<std::string> queue;

  std::string line;

  std::vector <std::string> commands = { "add", "get", "accelerate" };

  std::vector <std::string> prioritets = { "low", "normal", "high" };

  while (std::getline(std::cin, line))
  {
    std::stringstream in(line);

    in >> line;

    switch (std::distance(commands.begin(), std::find(commands.begin(), commands.end(), line)))
    {
      case 0:
      {
        std::string priority;
        in >> priority;

        auto findResult = std::find(prioritets.begin(), prioritets.end(), priority);

        if (findResult != prioritets.end())
        {

          std::string data;
          std::getline(in >> std::ws, data);

          if (data.empty())
          {
            std::cout << "INVALID COMMAND" << "\n";
          }

          queue.PutElementToQueue(data, static_cast<QueueWithPriority<std::string>::ElementPriority>(std::distance(prioritets.begin(), findResult)));
        }

        else
        {
          std::cout << "INVALID COMMAND" << "\n";
        }
        break;
      }

      case 1:
        queue.empty() ? std::cout << "EMPTY" << "\n" : std::cout << queue.GetElementFromQueue() << "\n";
        break;

      case 2:
        queue.Accelerate();
        break;

      default:
        std::cout << "INVALID COMMAND" << "\n";
    };
  }
}
