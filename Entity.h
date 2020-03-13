#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"
#include <vector>


enum EntityType { PLAYER, OBSTACLE, PLATFORM};

class Entity {
public:
    EntityType entityType;

    glm::vec3 position;
    glm::vec3 movement;
    glm::vec3 acceleration;
    glm::vec3 velocity;

    float width = 1.0f;
    float height = 1.0f;

    float speed;    

    GLuint textureID;
    
    glm::mat4 modelMatrix;
    
    bool isActive = true;

    bool collidedTop = false;
    bool collidedBottom = false;
    bool collidedLeft = false;
    bool collidedRight = false;

    EntityType lastCollision;

    Entity();
    
    bool CheckCollision(Entity* other);
    void CheckCollisionsY(Entity* objects, int objectCount);
    void CheckCollisionsX(Entity* objects, int objectCount);
    void Update(float deltaTime, Entity* obstacles, int obstacleCount, Entity* platforms, int platformCount);
    void Render(ShaderProgram *program);
    void DrawTexture(ShaderProgram *program, GLuint textureID);
};
