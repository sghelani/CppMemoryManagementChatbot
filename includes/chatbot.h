#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include "chatlogic.h"

class GraphNode; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    ChatBot(const ChatBot &chatBot);
    ChatBot(ChatBot &&chatBot);
    ChatBot& operator=(const ChatBot &chatBot);
    ChatBot& operator=(ChatBot &&chatBot);

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode);
    void SetChatLogicHandle(ChatLogic *chatLogic);
    ChatLogic* GetChatLogicHandle();
    wxBitmap *GetImageHandle();

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
