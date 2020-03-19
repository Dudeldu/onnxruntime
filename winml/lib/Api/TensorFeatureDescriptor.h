﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "TensorFeatureDescriptor.g.h"
#include "iengine.h"

namespace winrt::Windows::AI::MachineLearning::implementation {
struct TensorFeatureDescriptor : TensorFeatureDescriptorT<
                                     TensorFeatureDescriptor,
                                     ILearningModelFeatureDescriptorNative,
                                     WinML::IDescriptorInfoProvider> {
  TensorFeatureDescriptor() = delete;
  TensorFeatureDescriptor(
      const char* name,
      const char* description,
      winml::TensorKind tensor_kind,
      const std::vector<int64_t>& shape,
      bool is_required,
      bool has_unsuppored_image_metadata);
  
  TensorFeatureDescriptor(
      hstring const& name,
      hstring const& description,
      Windows::AI::MachineLearning::TensorKind const& kind,
      array_view<int64_t const> shape);

  // ITensorDescriptor
  winml::TensorKind
  TensorKind();

  wfc::IVectorView<int64_t>
  Shape();

  // IFeatureDescriptor
  winrt::hstring
  Name();

  winrt::hstring
  Description();

  winml::LearningModelFeatureKind
  Kind();

  bool
  IsRequired();

  bool
  IsUnsupportedMetaData();

  STDMETHOD(GetName)
  (
      const wchar_t** name,
      uint32_t* cchName) override;

  STDMETHOD(GetDescription)
  (
      const wchar_t** description,
      uint32_t* cchDescription) override;

  
  STDMETHOD(GetDescriptorInfo)
  (
      WinML::IEngineFactory* engine_factory, 
      WinML::IDescriptorInfo** info) override;

 private:
  winrt::hstring name_;
  winrt::hstring description_;
  winml::TensorKind tensor_kind_;
  std::vector<int64_t> shape_;
  bool is_required_;
  bool has_unsupported_image_metadata_;
};
}  // namespace winrt::Windows::AI::MachineLearning::implementation


namespace winrt::Windows::AI::MachineLearning::factory_implementation
{
    struct TensorFeatureDescriptor : TensorFeatureDescriptorT<TensorFeatureDescriptor, implementation::TensorFeatureDescriptor>
    {
    };
}
