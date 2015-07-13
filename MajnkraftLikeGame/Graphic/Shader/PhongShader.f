#version 330

const int MAX_POINT_LIGHTS=4;
struct BaseLight{
	vec3 color;
	float intensity;
};

struct DirectionalLight{
	BaseLight base;
	vec3 direction;
};

struct Attenuation{
	float constant;
	float linear;
	float exponent;
};

struct PointLight{
	BaseLight base;
	Attenuation atten;
	vec3 position;
};

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform vec3 baseColor;
uniform vec3 ambientLight;
uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform float specularIntensity;
uniform float specularPower;
uniform vec3 eyePos;

in vec2 Texcoord;
in vec3 normal0;
in vec3 worldPos0;
out vec4 pixel;

vec4 calcLight(BaseLight base,vec3 direction,vec3 normal){
	float difuseFactor=dot(normal,-direction);
	vec4 difuseColor = vec4(0,0,0,0);
	vec4 specularColor = vec4(0,0,0,0.0f);
	if(difuseFactor>0){
		difuseColor = vec4(base.color,1.0)*base.intensity*difuseFactor;

		vec3 directionToEye = normalize(eyePos - worldPos0);
		vec3 reflectDirection = normalize(reflect(direction,normal));
		float specularFactor = dot(directionToEye,reflectDirection);
		specularFactor = pow(specularFactor,specularPower);
		if(specularFactor>0){
			specularColor = vec4(base.color,1.0f) * specularIntensity * specularFactor;
		}
                
	}
	return difuseColor + specularColor;
}

vec4 calcDirectionalLight(DirectionalLight directionalLight,vec3 normal){
	return calcLight(directionalLight.base,directionalLight.direction,normal);
}

vec4 calcPointLight(PointLight pointLight,vec3 normal){
	vec3 lightDirection = worldPos0 - pointLight.position;
	float distanceToPoint = length(lightDirection);
	lightDirection = normalize(lightDirection);
	vec4 color = calcLight(pointLight.base,lightDirection,normal);
	float attenuation = pointLight.atten.constant + 
	pointLight.atten.linear * distanceToPoint +
	pointLight.atten.exponent * distanceToPoint * distanceToPoint +
	0.001;
	return color/attenuation;
}

void main() {
	vec4 totalLight = vec4(ambientLight,1);
	vec4 color = vec4(baseColor,1);
	if(color != vec4(0,0,0,0)){
		color *= texture(tex0, Texcoord) ;
	}
	vec3 normal = normalize(normal0);
	totalLight += calcDirectionalLight(directionalLight,normal);
	for (int i = 0; i < MAX_POINT_LIGHTS; i++) {
		totalLight += calcPointLight(pointLights[i],normal);
	}
	pixel = color*totalLight;
}