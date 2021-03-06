//===--- Attr.def - Swift Attributes Metaprogramming ------------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://polarphp.org/LICENSE.txt for license information
// See https://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2019/04/26.
//===----------------------------------------------------------------------===//
//
// This file defines macros used for macro-metaprogramming with attributes.
//
//===----------------------------------------------------------------------===//

#ifndef DECL_ATTR
#define DECL_ATTR(SPELLING, CLASS, OPTIONS, CODE)
#endif

#ifndef CONTEXTUAL_DECL_ATTR
#define CONTEXTUAL_DECL_ATTR(SPELLING, CLASS, OPTIONS, CODE) \
   DECL_ATTR(SPELLING, CLASS, OPTIONS, CODE)
#endif

#ifndef SIMPLE_DECL_ATTR
#define SIMPLE_DECL_ATTR(X, CLASS, OPTIONS, CODE) \
   DECL_ATTR(X, CLASS, OPTIONS, CODE)
#endif

#ifndef CONTEXTUAL_SIMPLE_DECL_ATTR
#define CONTEXTUAL_SIMPLE_DECL_ATTR(X, CLASS, OPTIONS, CODE) \
   SIMPLE_DECL_ATTR(X, CLASS, OPTIONS, CODE)
#endif

#ifndef DECL_ATTR_ALIAS
#define DECL_ATTR_ALIAS(SPELLING, CLASS)
#endif

#ifndef CONTEXTUAL_DECL_ATTR_ALIAS
#define CONTEXTUAL_DECL_ATTR_ALIAS(SPELLING, CLASS) \
   DECL_ATTR_ALIAS(SPELLING, CLASS)
#endif

#ifndef TYPE_ATTR
#define TYPE_ATTR(X)
#endif

// Type attributes
TYPE_ATTR(autoclosure)
TYPE_ATTR(convention)
TYPE_ATTR(noreturn)
TYPE_ATTR(noescape)
TYPE_ATTR(escaping)

// SIL-specific attributes
TYPE_ATTR(block_storage)
TYPE_ATTR(box)
TYPE_ATTR(dynamic_self)
TYPE_ATTR(error)
TYPE_ATTR(out)
TYPE_ATTR(in)
TYPE_ATTR(inout)
TYPE_ATTR(inout_aliasable)
TYPE_ATTR(in_guaranteed)
TYPE_ATTR(in_constant)
TYPE_ATTR(owned)
TYPE_ATTR(unowned_inner_pointer)
TYPE_ATTR(guaranteed)
TYPE_ATTR(autoreleased)
TYPE_ATTR(callee_owned)
TYPE_ATTR(callee_guaranteed)
TYPE_ATTR(objc_metatype)
TYPE_ATTR(opened)
TYPE_ATTR(pseudogeneric)
TYPE_ATTR(yields)
TYPE_ATTR(yield_once)
TYPE_ATTR(yield_many)

// SIL metatype attributes.
TYPE_ATTR(thin)
TYPE_ATTR(thick)

// Schema for DECL_ATTR:
//
// - Attribute name.
// - Class name without the 'Attr' suffix (ignored for
// - Options for the attribute, including:
//    * the declarations the attribute can appear on
//    * whether duplicates are allowed
//    * whether the attribute is considered a decl modifier or not (no '@')
// - Unique attribute identifier used for serialization.  This
//   can never be changed.
//
// SIMPLE_DECL_ATTR is the same, but the class becomes
// SimpleDeclAttr<DAK_##NAME>.
//
// Please help ease code review/audits:
// - Please indent once, not to the opening '('.
// - Please place the "OnXYZ" flags together on the next line.
// - Please place the non-OnXYZ flags together on the next to last line.
// - Please place the unique number on the last line. If the attribute is NOT
//   serialized, then please place that flag on the last line too. For example:
//     123)
//     NotSerialized, 321)
// - Please sort attributes by serialization number.
// - Please create a "NOTE" comment if a unique number is skipped.

DECL_ATTR(_silgen_name, SILGenName,
          OnAbstractFunction |
          LongAttribute | UserInaccessible,
          0)
DECL_ATTR(available, Available,
          OnAbstractFunction | OnGenericType | OnVar | OnSubscript | OnEnumElement |
          OnExtension | OnGenericTypeParam |
          AllowMultipleAttributes | LongAttribute,
          1)
CONTEXTUAL_SIMPLE_DECL_ATTR(final, Final,
                            OnClass | OnFunc | OnAccessor | OnVar | OnSubscript |
                            DeclModifier,
                            2)
DECL_ATTR(objc, ObjC,
          OnAbstractFunction | OnClass | OnProtocol | OnExtension | OnVar |
          OnSubscript | OnEnum | OnEnumElement,
          3)
CONTEXTUAL_SIMPLE_DECL_ATTR(required, Required,
                            OnConstructor |
                            DeclModifier,
                            4)
CONTEXTUAL_SIMPLE_DECL_ATTR(optional, Optional,
                            OnConstructor | OnFunc | OnAccessor | OnVar | OnSubscript |
                            DeclModifier,
                            5)
SIMPLE_DECL_ATTR(dynamicCallable, DynamicCallable,
                 OnNominalType,
                 6)
SIMPLE_DECL_ATTR(noreturn, NoReturn,
                 OnFunc | OnAccessor,
                 7)
SIMPLE_DECL_ATTR(_exported, Exported,
                 OnImport |
                 UserInaccessible,
                 8)
SIMPLE_DECL_ATTR(dynamicMemberLookup, DynamicMemberLookup,
                 OnNominalType,
                 9)
SIMPLE_DECL_ATTR(NSCopying, NSCopying,
                 OnVar,
                 10)
SIMPLE_DECL_ATTR(IBAction, IBAction,
                 OnFunc,
                 11)
SIMPLE_DECL_ATTR(IBDesignable, IBDesignable,
                 OnClass | OnExtension,
                 12)
SIMPLE_DECL_ATTR(IBInspectable, IBInspectable,
                 OnVar,
                 13)
SIMPLE_DECL_ATTR(IBOutlet, IBOutlet,
                 OnVar,
                 14)
SIMPLE_DECL_ATTR(NSManaged, NSManaged,
                 OnVar | OnFunc | OnAccessor,
                 15)
CONTEXTUAL_SIMPLE_DECL_ATTR(lazy, Lazy, DeclModifier |
                            OnVar,
                            16)
SIMPLE_DECL_ATTR(LLDBDebuggerFunction, LLDBDebuggerFunction,
                 OnFunc |
                 UserInaccessible,
                 17)
SIMPLE_DECL_ATTR(UIApplicationMain, UIApplicationMain,
                 OnClass,
                 18)
SIMPLE_DECL_ATTR(unsafe_no_objc_tagged_pointer, UnsafeNoObjCTaggedPointer,
                 OnProtocol |
                 UserInaccessible,
                 19)
DECL_ATTR(inline, Inline,
          OnVar | OnSubscript | OnAbstractFunction,
          20)
DECL_ATTR(_semantics, Semantics,
          OnAbstractFunction | OnSubscript |
          AllowMultipleAttributes | UserInaccessible,
          21)
CONTEXTUAL_SIMPLE_DECL_ATTR(dynamic, Dynamic,
                            OnFunc | OnAccessor | OnVar | OnSubscript | OnConstructor |
                            DeclModifier,
                            22)
CONTEXTUAL_SIMPLE_DECL_ATTR(infix, Infix,
                            OnFunc | OnOperator |
                            DeclModifier,
                            23)
CONTEXTUAL_SIMPLE_DECL_ATTR(prefix, Prefix,
                            OnFunc | OnOperator |
                            DeclModifier,
                            24)
CONTEXTUAL_SIMPLE_DECL_ATTR(postfix, Postfix,
                            OnFunc | OnOperator |
                            DeclModifier,
                            25)
SIMPLE_DECL_ATTR(_transparent, Transparent,
                 OnFunc | OnAccessor | OnConstructor | OnVar | UserInaccessible,
                 26)
SIMPLE_DECL_ATTR(requires_stored_property_inits, RequiresStoredPropertyInits,
                 OnClass,
                 27)
SIMPLE_DECL_ATTR(nonobjc, NonObjC,
                 OnExtension | OnFunc | OnAccessor | OnVar | OnSubscript | OnConstructor,
                 30)
SIMPLE_DECL_ATTR(_fixed_layout, FixedLayout,
                 OnVar | OnClass | OnStruct |
                 UserInaccessible,
                 31)
SIMPLE_DECL_ATTR(inlinable, Inlinable,
                 OnVar | OnSubscript | OnAbstractFunction,
                 32)
DECL_ATTR(_specialize, Specialize,
          OnConstructor | OnFunc | OnAccessor |
          AllowMultipleAttributes | LongAttribute | UserInaccessible,
          33)
SIMPLE_DECL_ATTR(objcMembers, ObjCMembers,
                 OnClass,
                 34)
CONTEXTUAL_SIMPLE_DECL_ATTR(__consuming, Consuming,
                            OnFunc | OnAccessor |
                            DeclModifier |
                            UserInaccessible |
                            NotSerialized, 40)
CONTEXTUAL_SIMPLE_DECL_ATTR(mutating, Mutating,
                            OnFunc | OnAccessor |
                            DeclModifier |
                            NotSerialized, 41)
CONTEXTUAL_SIMPLE_DECL_ATTR(nonmutating, NonMutating,
                            OnFunc | OnAccessor |
                            DeclModifier |
                            NotSerialized, 42)
CONTEXTUAL_SIMPLE_DECL_ATTR(convenience, Convenience,
                            OnConstructor |
                            DeclModifier |
                            NotSerialized, 43)
CONTEXTUAL_SIMPLE_DECL_ATTR(override, Override,
                            OnFunc | OnAccessor | OnVar | OnSubscript | OnConstructor | OnAssociatedType |
                            DeclModifier |
                            NotSerialized, 44)
SIMPLE_DECL_ATTR(_hasStorage, HasStorage,
                 OnVar |
                 UserInaccessible |
                 NotSerialized, 45)
DECL_ATTR(private, AccessControl,
          OnFunc | OnAccessor | OnExtension | OnGenericType | OnVar | OnSubscript |
          OnConstructor |
          DeclModifier |
          NotSerialized, 46)
DECL_ATTR_ALIAS(fileprivate, AccessControl)
DECL_ATTR_ALIAS(internal, AccessControl)
DECL_ATTR_ALIAS(public, AccessControl)
CONTEXTUAL_DECL_ATTR_ALIAS(open, AccessControl)
DECL_ATTR(__setter_access, SetterAccess,
          OnVar | OnSubscript |
          DeclModifier | RejectByParser |
          NotSerialized, 47)
DECL_ATTR(__raw_doc_comment, RawDocComment,
          OnAnyDecl |
          RejectByParser |
          NotSerialized, 48)
CONTEXTUAL_DECL_ATTR(weak, ReferenceOwnership,
                     OnVar |
                     DeclModifier |
                     NotSerialized, 49)
CONTEXTUAL_DECL_ATTR_ALIAS(unowned, ReferenceOwnership)
DECL_ATTR(_effects, Effects,
          OnAbstractFunction |
          UserInaccessible,
          50)
DECL_ATTR(__objc_bridged, ObjCBridged,
          OnClass |
          RejectByParser |
          NotSerialized, 51)
SIMPLE_DECL_ATTR(NSApplicationMain, NSApplicationMain,
                 OnClass,
                 52)
SIMPLE_DECL_ATTR(_objc_non_lazy_realization, ObjCNonLazyRealization,
                 OnClass |
                 UserInaccessible,
                 53)
DECL_ATTR(__synthesized_protocol, SynthesizedProtocol,
          OnConcreteNominalType |
          RejectByParser |
          NotSerialized, 54)
SIMPLE_DECL_ATTR(testable, Testable,
                 OnImport |
                 UserInaccessible |
                 NotSerialized, 55)
DECL_ATTR(_alignment, Alignment,
          OnStruct | OnEnum |
          UserInaccessible,
          56)
SIMPLE_DECL_ATTR(rethrows, Rethrows,
                 OnFunc | OnAccessor | OnConstructor |
                 RejectByParser,
                 57)
DECL_ATTR(_swift_native_objc_runtime_base, SwiftNativeObjCRuntimeBase,
          OnClass |
          UserInaccessible,
          59)
CONTEXTUAL_SIMPLE_DECL_ATTR(indirect, Indirect, DeclModifier |
                            OnEnum | OnEnumElement,
                            60)
SIMPLE_DECL_ATTR(warn_unqualified_access, WarnUnqualifiedAccess,
                 OnFunc | OnAccessor /*| OnVar*/ |
                 LongAttribute,
                 61)
SIMPLE_DECL_ATTR(_show_in_interface, ShowInInterface,
                 OnProtocol |
                 UserInaccessible,
                 62)
DECL_ATTR(_cdecl, CDecl,
          OnFunc | OnAccessor |
          LongAttribute | UserInaccessible,
          63)
SIMPLE_DECL_ATTR(usableFromInline, UsableFromInline,
                 OnAbstractFunction | OnVar | OnSubscript | OnNominalType | OnTypeAlias |
                 LongAttribute,
                 64)
SIMPLE_DECL_ATTR(discardableResult, DiscardableResult,
                 OnFunc | OnAccessor | OnConstructor |
                 LongAttribute,
                 65)
SIMPLE_DECL_ATTR(GKInspectable, GKInspectable,
                 OnVar,
                 66)
DECL_ATTR(_implements, Implements,
          OnFunc | OnAccessor | OnVar | OnSubscript | OnTypeAlias |
          UserInaccessible |
          NotSerialized, 67)
DECL_ATTR(_objcRuntimeName, ObjCRuntimeName,
          OnClass |
          UserInaccessible |
          NotSerialized, 68)
SIMPLE_DECL_ATTR(_staticInitializeObjCMetadata, StaticInitializeObjCMetadata,
                 OnClass | LongAttribute | RejectByParser |
                 NotSerialized, 69)
DECL_ATTR(_restatedObjCConformance, RestatedObjCConformance,
          OnProtocol |
          LongAttribute | RejectByParser |
          NotSerialized, 70)
// NOTE: 71 is unused
SIMPLE_DECL_ATTR(_implicitly_unwrapped_optional, ImplicitlyUnwrappedOptional,
                 OnFunc | OnAccessor | OnVar | OnParam | OnSubscript | OnConstructor |
                 RejectByParser,
                 72)
DECL_ATTR(_optimize, Optimize,
          OnAbstractFunction | OnSubscript | OnVar |
          UserInaccessible,
          73)
DECL_ATTR(_clangImporterSynthesizedType, ClangImporterSynthesizedType,
          OnGenericType |
          LongAttribute | RejectByParser | UserInaccessible |
          NotSerialized, 74)
SIMPLE_DECL_ATTR(_weakLinked, WeakLinked,
                 OnNominalType | OnAssociatedType | OnFunc | OnAccessor | OnVar |
                 OnSubscript | OnConstructor | OnEnumElement | OnExtension | UserInaccessible,
                 75)
SIMPLE_DECL_ATTR(_frozen, Frozen,
                 OnEnum |
                 UserInaccessible,
                 76)
SIMPLE_DECL_ATTR(_forbidSerializingReference, ForbidSerializingReference,
                 OnAnyDecl |
                 LongAttribute | RejectByParser | UserInaccessible | NotSerialized,
                 77)
SIMPLE_DECL_ATTR(_hasInitialValue, HasInitialValue,
                 OnVar |
                 UserInaccessible,
                 78)
SIMPLE_DECL_ATTR(_nonoverride, NonOverride,
                 OnFunc | OnAccessor | OnVar | OnSubscript | OnConstructor | OnAssociatedType |
                 UserInaccessible | NotSerialized,
                 79)
DECL_ATTR(_dynamicReplacement, DynamicReplacement,
          OnAbstractFunction | OnVar | OnSubscript | UserInaccessible,
          80)
SIMPLE_DECL_ATTR(_borrowed, Borrowed,
                 OnVar | OnSubscript | UserInaccessible |
                 NotSerialized, 81)
DECL_ATTR(_private, PrivateImport,
          OnImport |
          UserInaccessible |
          NotSerialized, 82)

#undef TYPE_ATTR
#undef DECL_ATTR_ALIAS
#undef CONTEXTUAL_DECL_ATTR_ALIAS
#undef SIMPLE_DECL_ATTR
#undef CONTEXTUAL_SIMPLE_DECL_ATTR
#undef DECL_ATTR
#undef CONTEXTUAL_DECL_ATTR
