#version 450

layout(binding = 0) uniform UniformBufferObject {
    mat4 mvp;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 inNormal;

layout(location = 0) out vec3 fragColor;

void main() {
    gl_Position = ubo.mvp * vec4(inPosition, 1.0);
    fragColor = vec3(1,1,1); //vec3(ubo.mvp *  ivec4(inNormal, 0.0));
}