#ifndef __BUFFER_MANAGER_H__
#define __BUFFER_MANAGER_H__

class Buffer {
  public:
    int sizeInBytes;
    char* buffer;

    std::string tag; // ID
};

class BufferManager {
  public:
    int totalFreeBuffers;

    std::vector <Buffer> buffers;

    int addBuffer (std::string tag, char* buffer);

    int writeBufferToDisk (std::string);
    int writeBufferToDiskAsynchronously (std::string);

    int deleteBuffe (std::string);

};

#endif
