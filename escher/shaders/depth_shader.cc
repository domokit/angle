// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "escher/shaders/depth_shader.h"

#include "escher/gl/extensions.h"
#include "util/shader_utils.h"

namespace escher {
namespace {

constexpr char g_vertex_shader[] = SHADER_SOURCE(
  attribute vec3 a_position;
  uniform mat4 u_matrix;

  void main() {
    gl_Position = u_matrix * vec4(a_position, 1.0);
  }
);

constexpr char g_fragment_shader[] = SHADER_SOURCE(
  void main() { }
);

}  // namespace

DepthShader::DepthShader() {
}

DepthShader::~DepthShader() {
}

bool DepthShader::Compile() {
  program_ = MakeUniqueProgram(g_vertex_shader, g_fragment_shader);
  if (!program_)
    return false;

  matrix_ = 0;
  glBindUniformLocation(program_.id(), matrix_, "u_matrix");

  position_ = 0;
  return true;
}

}  // namespace escher