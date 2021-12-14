// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lesson7.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_lesson7_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_lesson7_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_lesson7_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_lesson7_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_lesson7_2eproto;
namespace proto {
class FullName;
struct FullNameDefaultTypeInternal;
extern FullNameDefaultTypeInternal _FullName_default_instance_;
class Student;
struct StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class StudentsGroup;
struct StudentsGroupDefaultTypeInternal;
extern StudentsGroupDefaultTypeInternal _StudentsGroup_default_instance_;
}  // namespace proto
PROTOBUF_NAMESPACE_OPEN
template<> ::proto::FullName* Arena::CreateMaybeMessage<::proto::FullName>(Arena*);
template<> ::proto::Student* Arena::CreateMaybeMessage<::proto::Student>(Arena*);
template<> ::proto::StudentsGroup* Arena::CreateMaybeMessage<::proto::StudentsGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace proto {

// ===================================================================

class FullName final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.FullName) */ {
 public:
  inline FullName() : FullName(nullptr) {}
  ~FullName() override;
  explicit constexpr FullName(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  FullName(const FullName& from);
  FullName(FullName&& from) noexcept
    : FullName() {
    *this = ::std::move(from);
  }

  inline FullName& operator=(const FullName& from) {
    CopyFrom(from);
    return *this;
  }
  inline FullName& operator=(FullName&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const FullName& default_instance() {
    return *internal_default_instance();
  }
  static inline const FullName* internal_default_instance() {
    return reinterpret_cast<const FullName*>(
               &_FullName_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FullName& a, FullName& b) {
    a.Swap(&b);
  }
  inline void Swap(FullName* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FullName* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  FullName* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<FullName>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const FullName& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const FullName& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FullName* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.FullName";
  }
  protected:
  explicit FullName(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMNameFieldNumber = 1,
    kMSurnameFieldNumber = 2,
    kMPatronymicFieldNumber = 3,
  };
  // string m_name = 1;
  void clear_m_name();
  const std::string& m_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_m_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_m_name();
  PROTOBUF_NODISCARD std::string* release_m_name();
  void set_allocated_m_name(std::string* m_name);
  private:
  const std::string& _internal_m_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_m_name(const std::string& value);
  std::string* _internal_mutable_m_name();
  public:

  // string m_surname = 2;
  void clear_m_surname();
  const std::string& m_surname() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_m_surname(ArgT0&& arg0, ArgT... args);
  std::string* mutable_m_surname();
  PROTOBUF_NODISCARD std::string* release_m_surname();
  void set_allocated_m_surname(std::string* m_surname);
  private:
  const std::string& _internal_m_surname() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_m_surname(const std::string& value);
  std::string* _internal_mutable_m_surname();
  public:

  // optional string m_patronymic = 3;
  bool has_m_patronymic() const;
  private:
  bool _internal_has_m_patronymic() const;
  public:
  void clear_m_patronymic();
  const std::string& m_patronymic() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_m_patronymic(ArgT0&& arg0, ArgT... args);
  std::string* mutable_m_patronymic();
  PROTOBUF_NODISCARD std::string* release_m_patronymic();
  void set_allocated_m_patronymic(std::string* m_patronymic);
  private:
  const std::string& _internal_m_patronymic() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_m_patronymic(const std::string& value);
  std::string* _internal_mutable_m_patronymic();
  public:

  // @@protoc_insertion_point(class_scope:proto.FullName)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr m_name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr m_surname_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr m_patronymic_;
  friend struct ::TableStruct_lesson7_2eproto;
};
// -------------------------------------------------------------------

class Student final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.Student) */ {
 public:
  inline Student() : Student(nullptr) {}
  ~Student() override;
  explicit constexpr Student(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Student(const Student& from);
  Student(Student&& from) noexcept
    : Student() {
    *this = ::std::move(from);
  }

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }
  inline Student& operator=(Student&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Student& default_instance() {
    return *internal_default_instance();
  }
  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Student& a, Student& b) {
    a.Swap(&b);
  }
  inline void Swap(Student* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Student* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Student* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Student>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Student& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Student& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Student* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.Student";
  }
  protected:
  explicit Student(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMScoresFieldNumber = 2,
    kMFullnameFieldNumber = 1,
    kMAveragescoreFieldNumber = 3,
  };
  // repeated int32 m_scores = 2;
  int m_scores_size() const;
  private:
  int _internal_m_scores_size() const;
  public:
  void clear_m_scores();
  private:
  int32_t _internal_m_scores(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_m_scores() const;
  void _internal_add_m_scores(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_m_scores();
  public:
  int32_t m_scores(int index) const;
  void set_m_scores(int index, int32_t value);
  void add_m_scores(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      m_scores() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_m_scores();

  // .proto.FullName m_fullname = 1;
  bool has_m_fullname() const;
  private:
  bool _internal_has_m_fullname() const;
  public:
  void clear_m_fullname();
  const ::proto::FullName& m_fullname() const;
  PROTOBUF_NODISCARD ::proto::FullName* release_m_fullname();
  ::proto::FullName* mutable_m_fullname();
  void set_allocated_m_fullname(::proto::FullName* m_fullname);
  private:
  const ::proto::FullName& _internal_m_fullname() const;
  ::proto::FullName* _internal_mutable_m_fullname();
  public:
  void unsafe_arena_set_allocated_m_fullname(
      ::proto::FullName* m_fullname);
  ::proto::FullName* unsafe_arena_release_m_fullname();

  // double m_averagescore = 3;
  void clear_m_averagescore();
  double m_averagescore() const;
  void set_m_averagescore(double value);
  private:
  double _internal_m_averagescore() const;
  void _internal_set_m_averagescore(double value);
  public:

  // @@protoc_insertion_point(class_scope:proto.Student)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > m_scores_;
  mutable std::atomic<int> _m_scores_cached_byte_size_;
  ::proto::FullName* m_fullname_;
  double m_averagescore_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_lesson7_2eproto;
};
// -------------------------------------------------------------------

class StudentsGroup :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:proto.StudentsGroup) */ {
 public:
  inline StudentsGroup() : StudentsGroup(nullptr) {}
  ~StudentsGroup() override;
  explicit constexpr StudentsGroup(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  StudentsGroup(const StudentsGroup& from);
  StudentsGroup(StudentsGroup&& from) noexcept
    : StudentsGroup() {
    *this = ::std::move(from);
  }

  inline StudentsGroup& operator=(const StudentsGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline StudentsGroup& operator=(StudentsGroup&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const StudentsGroup& default_instance() {
    return *internal_default_instance();
  }
  static inline const StudentsGroup* internal_default_instance() {
    return reinterpret_cast<const StudentsGroup*>(
               &_StudentsGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(StudentsGroup& a, StudentsGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(StudentsGroup* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(StudentsGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  StudentsGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<StudentsGroup>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const StudentsGroup& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const StudentsGroup& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(StudentsGroup* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "proto.StudentsGroup";
  }
  protected:
  explicit StudentsGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMGroupFieldNumber = 1,
  };
  // repeated .proto.Student m_group = 1;
  int m_group_size() const;
  private:
  int _internal_m_group_size() const;
  public:
  void clear_m_group();
  ::proto::Student* mutable_m_group(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Student >*
      mutable_m_group();
  private:
  const ::proto::Student& _internal_m_group(int index) const;
  ::proto::Student* _internal_add_m_group();
  public:
  const ::proto::Student& m_group(int index) const;
  ::proto::Student* add_m_group();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Student >&
      m_group() const;

  // @@protoc_insertion_point(class_scope:proto.StudentsGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Student > m_group_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_lesson7_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FullName

// string m_name = 1;
inline void FullName::clear_m_name() {
  m_name_.ClearToEmpty();
}
inline const std::string& FullName::m_name() const {
  // @@protoc_insertion_point(field_get:proto.FullName.m_name)
  return _internal_m_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_m_name(ArgT0&& arg0, ArgT... args) {
 
 m_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.FullName.m_name)
}
inline std::string* FullName::mutable_m_name() {
  std::string* _s = _internal_mutable_m_name();
  // @@protoc_insertion_point(field_mutable:proto.FullName.m_name)
  return _s;
}
inline const std::string& FullName::_internal_m_name() const {
  return m_name_.Get();
}
inline void FullName::_internal_set_m_name(const std::string& value) {
  
  m_name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_m_name() {
  
  return m_name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_m_name() {
  // @@protoc_insertion_point(field_release:proto.FullName.m_name)
  return m_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_m_name(std::string* m_name) {
  if (m_name != nullptr) {
    
  } else {
    
  }
  m_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), m_name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (m_name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    m_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.FullName.m_name)
}

// string m_surname = 2;
inline void FullName::clear_m_surname() {
  m_surname_.ClearToEmpty();
}
inline const std::string& FullName::m_surname() const {
  // @@protoc_insertion_point(field_get:proto.FullName.m_surname)
  return _internal_m_surname();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_m_surname(ArgT0&& arg0, ArgT... args) {
 
 m_surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.FullName.m_surname)
}
inline std::string* FullName::mutable_m_surname() {
  std::string* _s = _internal_mutable_m_surname();
  // @@protoc_insertion_point(field_mutable:proto.FullName.m_surname)
  return _s;
}
inline const std::string& FullName::_internal_m_surname() const {
  return m_surname_.Get();
}
inline void FullName::_internal_set_m_surname(const std::string& value) {
  
  m_surname_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_m_surname() {
  
  return m_surname_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_m_surname() {
  // @@protoc_insertion_point(field_release:proto.FullName.m_surname)
  return m_surname_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void FullName::set_allocated_m_surname(std::string* m_surname) {
  if (m_surname != nullptr) {
    
  } else {
    
  }
  m_surname_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), m_surname,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (m_surname_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    m_surname_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.FullName.m_surname)
}

// optional string m_patronymic = 3;
inline bool FullName::_internal_has_m_patronymic() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool FullName::has_m_patronymic() const {
  return _internal_has_m_patronymic();
}
inline void FullName::clear_m_patronymic() {
  m_patronymic_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& FullName::m_patronymic() const {
  // @@protoc_insertion_point(field_get:proto.FullName.m_patronymic)
  return _internal_m_patronymic();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void FullName::set_m_patronymic(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 m_patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:proto.FullName.m_patronymic)
}
inline std::string* FullName::mutable_m_patronymic() {
  std::string* _s = _internal_mutable_m_patronymic();
  // @@protoc_insertion_point(field_mutable:proto.FullName.m_patronymic)
  return _s;
}
inline const std::string& FullName::_internal_m_patronymic() const {
  return m_patronymic_.Get();
}
inline void FullName::_internal_set_m_patronymic(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  m_patronymic_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* FullName::_internal_mutable_m_patronymic() {
  _has_bits_[0] |= 0x00000001u;
  return m_patronymic_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* FullName::release_m_patronymic() {
  // @@protoc_insertion_point(field_release:proto.FullName.m_patronymic)
  if (!_internal_has_m_patronymic()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = m_patronymic_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (m_patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    m_patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void FullName::set_allocated_m_patronymic(std::string* m_patronymic) {
  if (m_patronymic != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  m_patronymic_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), m_patronymic,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (m_patronymic_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    m_patronymic_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:proto.FullName.m_patronymic)
}

// -------------------------------------------------------------------

// Student

// .proto.FullName m_fullname = 1;
inline bool Student::_internal_has_m_fullname() const {
  return this != internal_default_instance() && m_fullname_ != nullptr;
}
inline bool Student::has_m_fullname() const {
  return _internal_has_m_fullname();
}
inline void Student::clear_m_fullname() {
  if (GetArenaForAllocation() == nullptr && m_fullname_ != nullptr) {
    delete m_fullname_;
  }
  m_fullname_ = nullptr;
}
inline const ::proto::FullName& Student::_internal_m_fullname() const {
  const ::proto::FullName* p = m_fullname_;
  return p != nullptr ? *p : reinterpret_cast<const ::proto::FullName&>(
      ::proto::_FullName_default_instance_);
}
inline const ::proto::FullName& Student::m_fullname() const {
  // @@protoc_insertion_point(field_get:proto.Student.m_fullname)
  return _internal_m_fullname();
}
inline void Student::unsafe_arena_set_allocated_m_fullname(
    ::proto::FullName* m_fullname) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(m_fullname_);
  }
  m_fullname_ = m_fullname;
  if (m_fullname) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:proto.Student.m_fullname)
}
inline ::proto::FullName* Student::release_m_fullname() {
  
  ::proto::FullName* temp = m_fullname_;
  m_fullname_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::proto::FullName* Student::unsafe_arena_release_m_fullname() {
  // @@protoc_insertion_point(field_release:proto.Student.m_fullname)
  
  ::proto::FullName* temp = m_fullname_;
  m_fullname_ = nullptr;
  return temp;
}
inline ::proto::FullName* Student::_internal_mutable_m_fullname() {
  
  if (m_fullname_ == nullptr) {
    auto* p = CreateMaybeMessage<::proto::FullName>(GetArenaForAllocation());
    m_fullname_ = p;
  }
  return m_fullname_;
}
inline ::proto::FullName* Student::mutable_m_fullname() {
  ::proto::FullName* _msg = _internal_mutable_m_fullname();
  // @@protoc_insertion_point(field_mutable:proto.Student.m_fullname)
  return _msg;
}
inline void Student::set_allocated_m_fullname(::proto::FullName* m_fullname) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete m_fullname_;
  }
  if (m_fullname) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper<::proto::FullName>::GetOwningArena(m_fullname);
    if (message_arena != submessage_arena) {
      m_fullname = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, m_fullname, submessage_arena);
    }
    
  } else {
    
  }
  m_fullname_ = m_fullname;
  // @@protoc_insertion_point(field_set_allocated:proto.Student.m_fullname)
}

// repeated int32 m_scores = 2;
inline int Student::_internal_m_scores_size() const {
  return m_scores_.size();
}
inline int Student::m_scores_size() const {
  return _internal_m_scores_size();
}
inline void Student::clear_m_scores() {
  m_scores_.Clear();
}
inline int32_t Student::_internal_m_scores(int index) const {
  return m_scores_.Get(index);
}
inline int32_t Student::m_scores(int index) const {
  // @@protoc_insertion_point(field_get:proto.Student.m_scores)
  return _internal_m_scores(index);
}
inline void Student::set_m_scores(int index, int32_t value) {
  m_scores_.Set(index, value);
  // @@protoc_insertion_point(field_set:proto.Student.m_scores)
}
inline void Student::_internal_add_m_scores(int32_t value) {
  m_scores_.Add(value);
}
inline void Student::add_m_scores(int32_t value) {
  _internal_add_m_scores(value);
  // @@protoc_insertion_point(field_add:proto.Student.m_scores)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
Student::_internal_m_scores() const {
  return m_scores_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
Student::m_scores() const {
  // @@protoc_insertion_point(field_list:proto.Student.m_scores)
  return _internal_m_scores();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
Student::_internal_mutable_m_scores() {
  return &m_scores_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
Student::mutable_m_scores() {
  // @@protoc_insertion_point(field_mutable_list:proto.Student.m_scores)
  return _internal_mutable_m_scores();
}

// double m_averagescore = 3;
inline void Student::clear_m_averagescore() {
  m_averagescore_ = 0;
}
inline double Student::_internal_m_averagescore() const {
  return m_averagescore_;
}
inline double Student::m_averagescore() const {
  // @@protoc_insertion_point(field_get:proto.Student.m_averagescore)
  return _internal_m_averagescore();
}
inline void Student::_internal_set_m_averagescore(double value) {
  
  m_averagescore_ = value;
}
inline void Student::set_m_averagescore(double value) {
  _internal_set_m_averagescore(value);
  // @@protoc_insertion_point(field_set:proto.Student.m_averagescore)
}

// -------------------------------------------------------------------

// StudentsGroup

// repeated .proto.Student m_group = 1;
inline int StudentsGroup::_internal_m_group_size() const {
  return m_group_.size();
}
inline int StudentsGroup::m_group_size() const {
  return _internal_m_group_size();
}
inline void StudentsGroup::clear_m_group() {
  m_group_.Clear();
}
inline ::proto::Student* StudentsGroup::mutable_m_group(int index) {
  // @@protoc_insertion_point(field_mutable:proto.StudentsGroup.m_group)
  return m_group_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Student >*
StudentsGroup::mutable_m_group() {
  // @@protoc_insertion_point(field_mutable_list:proto.StudentsGroup.m_group)
  return &m_group_;
}
inline const ::proto::Student& StudentsGroup::_internal_m_group(int index) const {
  return m_group_.Get(index);
}
inline const ::proto::Student& StudentsGroup::m_group(int index) const {
  // @@protoc_insertion_point(field_get:proto.StudentsGroup.m_group)
  return _internal_m_group(index);
}
inline ::proto::Student* StudentsGroup::_internal_add_m_group() {
  return m_group_.Add();
}
inline ::proto::Student* StudentsGroup::add_m_group() {
  ::proto::Student* _add = _internal_add_m_group();
  // @@protoc_insertion_point(field_add:proto.StudentsGroup.m_group)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::proto::Student >&
StudentsGroup::m_group() const {
  // @@protoc_insertion_point(field_list:proto.StudentsGroup.m_group)
  return m_group_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_lesson7_2eproto
