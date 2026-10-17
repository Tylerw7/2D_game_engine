#pragma once
#include <string>


class Shader {
    public:
      Shader(const std::string& vertexPath, const std::string& fragmentPath);
      ~Shader();
      Shader(const Shader&) = delete;
      Shader& operator=(const Shader&) = delete;

      void use() const;
      unsigned int id() const { return m_id; }

    private:
      unsigned int m_id = 0;
      static std::string readFile(const std::string& path);
      static unsigned int compile(unsigned int type, const std::string& src);

};