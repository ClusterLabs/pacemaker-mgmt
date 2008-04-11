/*
 * order_constraint_provider.c: HA_ResourceOrderConstraint provider
 * 
 * Author: Jia Ming Pan <jmltc@cn.ibm.com>
 * Copyright (c) 2005 International Business Machines
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#include <pygui_internal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cmpidt.h>
#include <cmpift.h>
#include <cmpimacs.h>
#include <hb_api.h>
#include "cmpi_utils.h"
#include "cluster_info.h"
#include "constraint_common.h"

static const char * PROVIDER_ID = "cim-op";
static CMPIBroker * Broker    = NULL;
static char ClassName []      = "HA_OrderConstraint";
DeclareInstanceFunctions(OrderConstraint);

static CMPIStatus 
OrderConstraintCleanup(CMPIInstanceMI * mi, CMPIContext * ctx)
{
	CMReturn(CMPI_RC_OK);
}

static CMPIStatus 
OrderConstraintEnumInstanceNames(CMPIInstanceMI * mi, CMPIContext * ctx,
                              CMPIResult * rslt, CMPIObjectPath * ref)
{
        CMPIStatus rc;

        PROVIDER_INIT_LOGGER();
        constraint_enum_insts(Broker, ClassName, ctx, rslt, ref, 
			FALSE, TID_CONS_ORDER, &rc);
        return rc;
}


static CMPIStatus 
OrderConstraintEnumInstances(CMPIInstanceMI * mi, CMPIContext * ctx,
                          CMPIResult * rslt, CMPIObjectPath * ref,
                          char ** properties)
{
        CMPIStatus rc;

        PROVIDER_INIT_LOGGER();
        constraint_enum_insts(Broker, ClassName, ctx, rslt, ref, 
			TRUE, TID_CONS_ORDER, &rc);
        return rc;
}

static CMPIStatus 
OrderConstraintGetInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                        CMPIResult * rslt, CMPIObjectPath * cop,
                        char ** properties)
{
        CMPIStatus rc;

        PROVIDER_INIT_LOGGER();
        constraing_get_inst(Broker, ClassName, ctx, rslt, cop, 
                           properties, TID_CONS_ORDER, &rc);
	return rc;
}

static CMPIStatus 
OrderConstraintCreateInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                           CMPIResult * rslt, CMPIObjectPath * cop,
                           CMPIInstance * ci)
{
	CMPIStatus rc = {CMPI_RC_OK, NULL};

	PROVIDER_INIT_LOGGER();
	constraint_create_inst(Broker, ClassName, mi, ctx, rslt, 
			cop, ci, TID_CONS_ORDER, &rc);
	return rc;
}


static CMPIStatus 
OrderConstraintSetInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                        CMPIResult * rslt, CMPIObjectPath * cop,
                        CMPIInstance * ci, char ** properties)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};

	PROVIDER_INIT_LOGGER();
	constraint_update_inst(Broker, ClassName, mi, ctx, rslt, 
			cop, ci, properties, TID_CONS_ORDER, &rc);
        return rc;
}


static CMPIStatus 
OrderConstraintDeleteInstance(CMPIInstanceMI * mi, CMPIContext * ctx,
                           CMPIResult * rslt, CMPIObjectPath * cop)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
	constraint_delete_inst(Broker, ClassName, mi, ctx, 
			rslt, cop, TID_CONS_ORDER, &rc);
	return rc;
}

static CMPIStatus 
OrderConstraintExecQuery(CMPIInstanceMI * mi, CMPIContext * ctx,
                      CMPIResult * rslt, CMPIObjectPath * ref,
                      char * lang, char * query)
{
        CMPIStatus rc = {CMPI_RC_OK, NULL};
        CMSetStatusWithChars(Broker, &rc, CMPI_RC_ERR_NOT_SUPPORTED, 
                             "CIM_ERR_NOT_SUPPORTED");
	return rc;
}

/*****************************************************
 * install provider
 ****************************************************/

DeclareInstanceMI(OrderConstraint, HA_OrderConstraintProvider, Broker);
