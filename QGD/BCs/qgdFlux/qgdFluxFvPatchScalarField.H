/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  | Copyright (C) 2016 OpenCFD Ltd.
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::qgdFluxFvPatchScalarField

Group
    grpInletBoundaryConditions grpWallBoundaryConditions

Description
    This boundary condition sets the pressure gradient to the provided value
    such that the flux on the boundary is that specified by the velocity
    boundary condition.

    Example of the boundary condition specification:
    \verbatim
    <patchName>
    {
        type            qgdFlux;
    }
    \endverbatim

See also
    Foam::fixedGradientFvPatchField

SourceFiles
    qgdFluxFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef qgdFluxFvPatchScalarField_H
#define qgdFluxFvPatchScalarField_H

#include "fvPatchFields.H"
#include "fixedGradientFvPatchFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
             Class qgdFluxFvPatchScalarField Declaration
\*---------------------------------------------------------------------------*/

class qgdFluxFvPatchScalarField
:
    public fixedGradientFvPatchScalarField
{


public:

    //- Runtime type information
    TypeName("qgdFlux");


    // Constructors

        //- Construct from patch and internal field
        qgdFluxFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        qgdFluxFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given qgdFluxFvPatchScalarField onto
        //  a new patch
        qgdFluxFvPatchScalarField
        (
            const qgdFluxFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        qgdFluxFvPatchScalarField
        (
            const qgdFluxFvPatchScalarField&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchScalarField> clone() const
        {
            return tmp<fvPatchScalarField>
            (
                new qgdFluxFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        qgdFluxFvPatchScalarField
        (
            const qgdFluxFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchScalarField> clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchScalarField>
            (
                new qgdFluxFvPatchScalarField(*this, iF)
            );
        }


    // Member functions

        ////- Update the patch pressure gradient field from the given snGradp
        //virtual void updateSnGrad(const scalarField& snGradp);

        //- Update the patch pressure gradient field
        virtual void updateCoeffs();

        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

//#include "volFields.H"
//
//namespace Foam
//{
//    template<class GradBC>
//    inline void setSnGrad
//    (
//        volScalarField::Boundary& bf,
//        const FieldField<fvsPatchField, scalar>& snGrad
//    )
//    {
//        forAll(bf, patchi)
//        {
//            if (isA<GradBC>(bf[patchi]))
//            {
//                refCast<GradBC>(bf[patchi]).updateSnGrad(snGrad[patchi]);
//            }
//        }
//    }
//
//    template<class GradBC>
//    inline void setSnGrad
//    (
//        volScalarField::Boundary& bf,
//        const tmp<FieldField<fvsPatchField, scalar>>& tsnGrad
//    )
//    {
//        setSnGrad<GradBC>(bf, tsnGrad());
//    }
//}
//

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
