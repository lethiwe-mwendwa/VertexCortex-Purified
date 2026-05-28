// VertexCortex Purified Testing

#include "VertexCortex.h"
#include <string>

// Code that will be run once at the start, prior to window creation
void setup() {
	
	OutputDebugString(TEXT("\nHello console world\n"));

}

// Code run every frame
void update(float deltaTime) {

	OutputDebugString(TEXT("\nUPDATE\n"));

	//OutputDebugString(std::to_wstring(1.0f / deltaTime).c_str());

}

// Code run at the termination stage of the application
void destroy() {

	OutputDebugString(TEXT("\nDESTROY\n"));

}