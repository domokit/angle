// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "waterfall/scenes/app_test_scene.h"

#include "escher/base/arraysize.h"
#include "escher/renderer.h"

namespace {

constexpr float kFabSize = 56.0f;

}  // namespace

AppTestScene::AppTestScene() {
  app_bar_material_.set_color(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
  canvas_material_.set_color(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
  card_material_.set_color(glm::vec4(1.0f, 1.0f, 0.8f, 1.0f));
  fab_material_.set_color(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
  green_material_.set_color(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
}

AppTestScene::~AppTestScene() {}

escher::Model AppTestScene::GetModel(const escher::SizeI& size,
                                     const glm::vec2& focus) {
  std::vector<std::unique_ptr<escher::Object>> objects;

  // app bar
  objects.emplace_back(escher::Object::CreateRect(
      glm::vec2(0.0f, 0.0f), glm::vec2(size.width(), 56.0f), 4.0f,
      &app_bar_material_));

  objects.emplace_back(escher::Object::CreateRect(glm::vec2(100.0f, 180.0f),
                                                  glm::vec2(60.0f, 40.0f),
                                                  10.0f, &green_material_));
  objects.emplace_back(escher::Object::CreateRect(glm::vec2(200.0f, 180.0f),
                                                  glm::vec2(60.0f, 40.0f),
                                                  16.0f, &green_material_));
  objects.emplace_back(escher::Object::CreateRect(
      glm::vec2(0.0f, 200.0f), glm::vec2(size.width(), 80.0f), 2.0f,
      &card_material_));

  // canvas
  objects.emplace_back(escher::Object::CreateRect(
      glm::vec2(0.0f, 0.0f), size.AsVec2(), 0.0f, &canvas_material_));

  // fab
  objects.emplace_back(escher::Object::CreateCircle(
      glm::vec2(focus.x - kFabSize / 2.0f, focus.y - kFabSize / 2.0f), kFabSize,
      6.0f, &fab_material_));

  return escher::Model(std::move(objects));
}
